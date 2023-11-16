//
// Created by adamc on 18/10/2023.
//

#ifndef PEA1_TSPBRUTEFORCE_H
#define PEA1_TSPBRUTEFORCE_H


#include "Matrix.h"

class TSPBruteForce {
public:
    TSPBruteForce(Matrix *matrix);
    ~TSPBruteForce();

    void launch(int arr[], int l, int r);
    Matrix* matrix;

    int* stringOfNodes;
    int bestRoute;
};


#endif //PEA1_TSPBRUTEFORCE_H
