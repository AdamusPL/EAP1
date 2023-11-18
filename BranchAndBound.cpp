//
// Created by adamc on 25.10.2023.
//

#include "BranchAndBound.h"
#include "Node.h"
#include "Cmp.h"

BranchAndBound::BranchAndBound(Matrix *matrix) {
    this->matrix = matrix;
    this->bestRoute = INT_MAX;
}

BranchAndBound::~BranchAndBound() {
    while(!priorityQueue.empty()){
        delete priorityQueue.top().second;
        priorityQueue.pop();
    }
}

bool BranchAndBound::launch(Matrix *matrix, Timer timer) {

    Node* prevNode = new Node(matrix->nrV);
    prevNode->route.push_back(0);
    BranchAndBound::copyMatrix(prevNode->matrix,matrix);
    prevNode->lowerBound = BranchAndBound::reduceMatrix(prevNode->matrix); //reducing matrix, calculating lowerBound which is sum of every reduction in row/column
    prevNode->nrV = 0;
    prevNode->level = 0;

//    std::cout << "lowerBound= " << prevNode->lowerBound << std::endl;

    //pair <key: lowerBound, value: Node>
    //priority queue, sorted in ascending way by key
    std::priority_queue<std::pair<int, Node*>, std::vector<std::pair<int, Node*>>, Cmp> priorityQueueCpy;


    priorityQueue.emplace(prevNode->lowerBound, prevNode); //put node 0 to queue

    int reduction;
    int minCost = INT_MAX; //this will store best minCost of full path
    Node* bestSol; //this will store last best solution
//    double combinations = 0;
//    double silnia17 = 355687428096000;

    while(!priorityQueue.empty()) {

//        if(timer.stopTimer()/1000000.0 > 300){
//            std::cout<<"Nie wykonano do konca w 5 minut"<<std::endl;
//            std::cout<<"Rozwazone przypadki: "<<combinations/silnia17;
//            return false;
//        }

        if (priorityQueue.top().first < minCost) { //if there's Node with lower lowerBound than in last node in the best solution, DFS this Node

            prevNode = priorityQueue.top().second; //take this Node
            priorityQueue.pop(); //remove it from queue

            while(!priorityQueue.empty()) { //remove not worth more searching solutions
                if (priorityQueue.top().first < minCost) {
                    priorityQueueCpy.push(priorityQueue.top());
                    priorityQueue.pop();
                }

                else{
                    delete priorityQueue.top().second; //free memory
                    priorityQueue.pop();
                }
            }

            priorityQueue = priorityQueueCpy;

            while(!priorityQueueCpy.empty()){
                priorityQueueCpy.pop();
            }

            int currentMinCost = INT_MAX; //this will help finding best lowerBound from unvisited Nodes

            for (int i = 1; i < matrix->nrV; ++i) {

                //check if we have visited this Node
                bool visited = false;

                for (int j = 0; j < prevNode->route.size(); ++j) {
                    if(prevNode->route[j]==i){
                        visited=true;
                        break;
                    }
                }

                if(visited) continue; //if yes, skip that iteration


                Node *node = new Node(matrix->nrV);
                node->route = prevNode->route; //copy route from previous node
                node->nrV = i;
                node->level = prevNode->level + 1; //we are one level down

                BranchAndBound::copyMatrix(node->matrix,
                                           prevNode->matrix); //copying matrix to save it in case you want to come back to it

                node->route.push_back(i); //add this Node to route

                //1. reduce size
                for (int j = 0; j < matrix->nrV; ++j) { //filling a row and column with -1
                    //if we analyze edge (1,2), then we fill row 1. with -1 and column 2. with -1
                    node->matrix->adjMatrix[j][node->nrV] = -1;
                    node->matrix->adjMatrix[prevNode->nrV][j] = -1;
                }

                //2. prevent from cycles
                node->matrix->adjMatrix[i][0] = -1; //we don't come back to the beginning verticle (nr 0)

//                std::cout << "Before reduction:" << std::endl;
//                node->matrix->printMatrix();

                //3. reduce matrix
                reduction = BranchAndBound::reduceMatrix(node->matrix); //reduce matrix

//                std::cout << "After reduction:" << std::endl;
//                node->matrix->printMatrix();

                //4. calculate lowerBound
                node->lowerBound = prevNode->matrix->adjMatrix[prevNode->nrV][i] + prevNode->lowerBound +
                                   reduction; //calculate the current cost
//                std::cout << "lowerBound= " << node->lowerBound << std::endl;

                priorityQueue.emplace(node->lowerBound, node); //put this node in queue

                if (node->lowerBound < currentMinCost) { //if we find new best route
                    bestSol = node;
                    currentMinCost = node->lowerBound;
                }
            }

            if(bestSol->level == matrix->nrV-1){ //if we visited all nodes, then it's our new solution
                solution = bestSol->route;
                minCost = currentMinCost;
//                combinations++;
            }

        }

        else{ //if no, we found best track
            break;
        }

    }

    bestRoute = minCost;
    return true;

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
