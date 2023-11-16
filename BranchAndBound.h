//
// Created by adamc on 25.10.2023.
//

#ifndef PEA1_BRANCHANDBOUND_H
#define PEA1_BRANCHANDBOUND_H


#include "Matrix.h"
#include <queue>

class BranchAndBound {
public:
    int upperBound;
    int bestRoute;
    std::vector<int> solution;
    int reduceMatrix(Matrix*);
    void copyMatrix(Matrix*, Matrix*);

    BranchAndBound(Matrix *matrix);
    Matrix *matrix;
    ~BranchAndBound();

    void launch(Matrix*);
};


#endif //PEA1_BRANCHANDBOUND_H