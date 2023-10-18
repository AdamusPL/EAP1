//
// Created by adamc on 12/10/2023.
//

#include "Matrix.h"

Matrix::Matrix(){

}

Matrix::Matrix(int nrV) {

    adjMatrix = new int *[nrV]; //array of pointers on int

    for (int i = 0; i < nrV; ++i) {
        adjMatrix[i] = new int[nrV]; //
    }

    this->nrV = nrV;

}

Matrix::~Matrix(){
    for (int i = 0; i < nrV; ++i) {
        delete [] adjMatrix[i]; //
    }

    delete [] adjMatrix; //
}

void Matrix::printMatrix() {
    for (int i = 0; i < nrV; ++i) {
        for (int j = 0; j < nrV; ++j) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout<<std::endl;
    }
}
