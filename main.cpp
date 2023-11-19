#include <iostream>
#include "FileReader.h"
#include "Randomizer.h"
#include "Matrix.h"
#include "TSPBruteForce.h"
#include "Timer.h"
#include "BranchAndBound.h"
#include "Menu.h"

int main() {
    int option=0;
    Menu menu;

    while(option!=5){ //menu

        std::cout << std::endl;
        std::cout << "1. Read data from file" << std::endl;
        std::cout << "2. Generate random data" << std::endl;
        std::cout << "3. Print previously read or generated data" << std::endl;
        std::cout << "4. Launch algorithm for previously read or generated data" << std::endl;

        std::cin >> option;
        std::cout << std::endl;

        switch (option) {
            case 1:
                menu.option1();
                break;

            case 2:
                menu.option2();
                break;

            case 3:
                menu.option3();
                break;

            case 4:
                menu.option4();

        }

    }

}

