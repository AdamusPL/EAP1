//
// Created by adamc on 25.10.2023.
//

#ifndef PEA1_BRANCHANDBOUND_H
#define PEA1_BRANCHANDBOUND_H


#include "Matrix.h"
#include "Timer.h"
#include "Node.h"
#include "Cmp.h"
#include <queue>

class BranchAndBound {
public:
    int upperBound;
    int bestRoute;
    std::priority_queue<std::pair<int, Node*>, std::vector<std::pair<int, Node*>>, Cmp> priorityQueue;
    std::vector<int> solution;
    int reduceMatrix(Matrix*);
    void copyMatrix(Matrix*, Matrix*);

    BranchAndBound(Matrix *matrix);
    Matrix *matrix;
    ~BranchAndBound();

    bool launch(Matrix*, Timer);
};


#endif //PEA1_BRANCHANDBOUND_H