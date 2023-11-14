//
// Created by adamc on 25.10.2023.
//

#include "BranchAndBound.h"

BranchAndBound::BranchAndBound(Matrix *matrix) {
    this->matrix = matrix;
    this->stringOfVertices = new int [matrix->nrV];
    this->bestRoute = INT_MAX;
    this->visited = new bool[matrix->nrV];
}

BranchAndBound::~BranchAndBound() {

}

void BranchAndBound::launch(Matrix *matrix) {

    int lowerBound = BranchAndBound::reduceMatrix(matrix); //reducing matrix, calculating lowerBound which is sum of every reduction in row/column
    std::cout << "Sum of reduction cost: " << lowerBound << std::endl;

    upperBound = -1;

    for (int i = 0; i < matrix->nrV; ++i) { //fill the array with false value
        visited[i] = false;
    }

    visited[0] = true; //we have visited first vertex
    stringOfVertices[0] = 0; //we start from vertex nr 0

    Matrix* cpy = new Matrix(matrix->nrV); //matrix which will store copy of the matrix from previous iteration
    Matrix* saved = new Matrix(matrix->nrV); //matrix which will store matrix from current best solution from current iteration

    //making the copy of the matrix to find best solution
    BranchAndBound::copyMatrix(cpy, matrix);

    int reduction;
    int currentCost;
    int minCost;

    for (int k = 0; k < matrix->nrV-1; ++k) { //current vertex from stringOfVertices
        //you have to remember cost of previous nodes in order to come back to them, so... use STL?
        //own binary tree?

        minCost = INT_MAX;

        for (int i = 0; i < matrix->nrV; ++i) {

            if(visited[i]) continue; //if we have visited the vertex, skip to the next iteration

            //1. reduce size
            for (int j = 0; j < matrix->nrV; ++j) { //filling a row and column with -1
                //if we analyze edge (1,2), then we fill row 1. with -1 and column 2. with -1
                matrix->adjMatrix[j][i] = -1;
                matrix->adjMatrix[stringOfVertices[k]][j] = -1;
            }

            //2. prevent from cycles
            matrix->adjMatrix[i][stringOfVertices[0]] = -1; //we don't come back to the beginning verticle (nr 0)

            std::cout<<"Before reduction:"<<std::endl;
            matrix->printMatrix();

            //3. reduce matrix
            reduction = BranchAndBound::reduceMatrix(matrix); //reduce matrix

            std::cout<<"After reduction:"<<std::endl;
            matrix->printMatrix();

            //4. calculate lowerBound
            currentCost = cpy->adjMatrix[stringOfVertices[k]][i] + lowerBound + reduction; //calculate the current cost
            std::cout<<"Current cost: "<<currentCost<<std::endl;

            if(currentCost < minCost){ //if we find new best route

                minCost = currentCost;
                stringOfVertices[k+1] = i; //we add vertex to string of solution
                BranchAndBound::copyMatrix(saved, matrix); //we save matrix of that solution

            }

            BranchAndBound::copyMatrix(matrix, cpy);

        }
        lowerBound = minCost;
        BranchAndBound::copyMatrix(cpy, saved); //copy Matrix of best solution
        visited[stringOfVertices[k + 1]] = true; //we have visited that vertex
        saved->printMatrix();
        BranchAndBound::copyMatrix(matrix, cpy);
    }

    std::cout<<"Final cost: "<<minCost<<std::endl;

}

int BranchAndBound::reduceMatrix(Matrix* matrix){
    //reducing matrix
    int min; //min value
    int reductionCost = 0;

    //reducing rows
    for (int i = 0; i < matrix->nrV; ++i) {

        min = INT_MAX;

        //find minimum value in a row
        for (int j = 0; j < matrix->nrV; ++j) {
            if(matrix->adjMatrix[i][j]<min && matrix->adjMatrix[i][j]!=-1) min = matrix->adjMatrix[i][j];
        }

        if(min>0 && min<INT_MAX){
            //subtract "min" from every value in that row
            reductionCost+=min;
            for (int j = 0; j < matrix->nrV; ++j) {
                if(matrix->adjMatrix[i][j]!=-1) matrix->adjMatrix[i][j] = matrix->adjMatrix[i][j] - min;
            }
        }
    }

    //reducing columns
    for (int j = 0; j < matrix->nrV; ++j) {

        min = INT_MAX;

        for (int i = 0; i < matrix->nrV; ++i) {
            if(matrix->adjMatrix[i][j]<min && matrix->adjMatrix[i][j]!=-1) min = matrix->adjMatrix[i][j];
        }

        if(min>0 && min<INT_MAX){
            reductionCost+=min;
            for (int i = 0; i < matrix->nrV; ++i) {
                if(matrix->adjMatrix[i][j]!=-1) matrix->adjMatrix[i][j] = matrix->adjMatrix[i][j] - min;
            }
        }
    }
    return reductionCost;
}

void BranchAndBound::copyMatrix(Matrix* to, Matrix* from){
    for (int i = 0; i < matrix->nrV; ++i) { //copy the solution to new matrix
        for (int j = 0; j < matrix->nrV; ++j) {
            to->adjMatrix[i][j] = from->adjMatrix[i][j];
        }
    }
}