//
// Created by adamc on 17.11.2023.
//

#ifndef PEA1_CMP_H
#define PEA1_CMP_H

#include "Node.h"

class Cmp{
public:
    bool operator()(const std::pair<int, Node*>& p1, const std::pair<int, Node*>& p2) {
        // Compare based on the first element of the pairs (the key)
        return p1.first > p2.first; // Change to '<' for ascending order
    }
};

#endif //PEA1_CMP_H
