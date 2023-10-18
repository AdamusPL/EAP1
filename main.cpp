#include <iostream>
#include "FileReader.h"
#include "Randomizer.h"
#include "Matrix.h"
#include "TSPBruteForce.h"

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
                break;

            case 2:
                Randomizer randomizer;

                if(matrix != nullptr){ //free memory if previous matrix still exist
                    matrix->~Matrix();
                }

                //do I have to remove the previous one?
                matrix = randomizer.generate();

                break;

            case 3:
                matrix->printMatrix();
                break;

            case 4:
                TSPBruteForce tspBruteForce = TSPBruteForce(matrix);

                int tab[matrix->nrV];
                for (int i = 0; i < matrix->nrV; ++i) {
                    tab[i] = i;
                }

                tspBruteForce.launch(tab,0,matrix->nrV-1);

                std::cout<<"Wyniki:"<<std::endl;
                for (int i = 0; i < matrix->nrV; ++i) {
                    std::cout << tspBruteForce.stringOfVerticles[i] << "->";
                }
                std::cout << tspBruteForce.stringOfVerticles[0];

                std::cout << std::endl;
                std::cout << tspBruteForce.bestRoute << std::endl;

                break;

        }

    }

}
