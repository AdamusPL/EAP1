//
// Created by adamc on 25.10.2023.
//

#ifndef PEA1_BRANCHANDBOUND_H
#define PEA1_BRANCHANDBOUND_H


#include "Matrix.h"

class BranchAndBound {

    int upperBound;
    int* stringOfVertices;
    int bestRoute;
    bool* visited;
    int reduceMatrix(Matrix*);
    void copyMatrix(Matrix*, Matrix*);

public:
    BranchAndBound(Matrix *matrix);
    Matrix *matrix;
    ~BranchAndBound();

    void launch(Matrix*);
};


#endif //PEA1_BRANCHANDBOUND_H