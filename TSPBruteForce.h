//
// Created by adamc on 18/10/2023.
//

#ifndef PEA1_TSPBRUTEFORCE_H
#define PEA1_TSPBRUTEFORCE_H


#include "Matrix.h"

class TSPBruteForce {
public:
    TSPBruteForce(Matrix *matrix);
    void launch(int*, int, int);
    void perm(int*, int, int);
    Matrix* matrix;

    int* stringOfVerticles;
    int bestRoute;
};


#endif //PEA1_TSPBRUTEFORCE_H
