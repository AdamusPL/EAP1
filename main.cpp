#include <iostream>
#include "FileReader.h"
#include "Randomizer.h"
#include "Matrix.h"

int main() {
    int option=0;
    Matrix matrix;

    while(option!=5){ //menu

        std::cout << "1. Read data from file" << std::endl;
        std::cout << "2. Generate random data" << std::endl;
        std::cout << "3. Print previously read or generated data" << std::endl;
        std::cout << "4. Launch algorithm for previously read or generated data" << std::endl;

        std::cin >> option;

        switch (option) {
            case 1:
                FileReader fileReader;

                if(matrix.adjMatrix != nullptr){ //free memory if previous matrix still exist
                    matrix.~Matrix();
                }

                matrix = fileReader.read(); //read matrix data from .txt file
                break;

            case 2:
                Randomizer randomizer;

                if(matrix.adjMatrix != nullptr){ //free memory if previous matrix still exist
                    matrix.~Matrix();
                }

                break;

            case 3:
                matrix.printMatrix();
                break;

            default:
                return 0;

        }

    }

}
