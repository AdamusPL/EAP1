//
// Created by adamc on 17.11.2023.
//

#ifndef PEA1_NODE_H
#define PEA1_NODE_H


#include "Matrix.h"
#include <vector>

class Node {
public:
    Node(int);
    ~Node();
    //Node stores matrix
    std::vector<int> route;
    Matrix *matrix;
    int lowerBound;
    int nrV;
    int level;
};


#endif //PEA1_NODE_H
