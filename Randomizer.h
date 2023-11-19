//
// Created by adamc on 09/10/2023.
//

#ifndef PEA1_RANDOMIZER_H
#define PEA1_RANDOMIZER_H
#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include "Matrix.h"

class Randomizer {
public:
    Matrix* generate(int);
};


#endif //PEA1_RANDOMIZER_H
