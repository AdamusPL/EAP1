//
// Created by adamc on 18.11.2023.
//

#ifndef PEA1_MENU_H
#define PEA1_MENU_H

#include "Matrix.h"
#include "FileReader.h"
#include "Randomizer.h"
#include "TSPBruteForce.h"
#include "BranchAndBound.h"

class Menu {
public:
    Menu();
    Matrix* matrix;

    void option1();
    void option2();
    void option3();
    void option4();
    void manualTests();
    void automaticTests();
    void bruteForce(bool);
    void branchAndBound(bool);
};


#endif //PEA1_MENU_H
