#include <iostream>
#include "FileReader.h"
#include "Randomizer.h"
#include "Matrix.h"

int main() {
    int option=0;
    Matrix *matrix = nullptr; //dynamically alocated object

    while(option!=5){ //menu

        std::cout << "1. Read data from file" << std::endl;
        std::cout << "2. Generate random data" << std::endl;
        std::cout << "3. Print previously read or generated data" << std::endl;
        std::cout << "4. Launch algorithm for previously read or generated data" << std::endl;

        std::cin >> option;

        switch (option) {
            case 1:
                FileReader fileReader;

                if(matrix != nullptr){ //free memory if previous matrix still exist
                    matrix->~Matrix();
                }

                //do I have to remove the previous one?
                matrix = fileReader.read(); //read matrix data from .txt file and change pointer to it
                matrix->printMatrix();
                break;

            case 2:
                Randomizer randomizer;

                if(matrix != nullptr){ //free memory if previous matrix still exist
                    matrix->~Matrix();
                }

                matrix = randomizer.generate();
                matrix->printMatrix();

                break;

            case 3:
                matrix->printMatrix();
                break;

            default:
                return 0;

        }

    }

}
