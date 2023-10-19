#include <iostream>
#include "FileReader.h"
#include "Randomizer.h"
#include "Matrix.h"
#include "TSPBruteForce.h"
#include "Timer.h"

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
                    matrix->~Matrix(); //call destructor and free memory
                }

                matrix = fileReader.read(); //read matrix data from .txt file and change pointer to it
                break;

            case 2:
                Randomizer randomizer;

                if(matrix != nullptr){ //free memory if previous matrix still exist
                    matrix->~Matrix(); //call destructor and free memory
                }

                matrix = randomizer.generate(); //generate random data into the matrix and change pointer to it

                break;

            case 3:
                matrix->printMatrix(); //print matrix
                break;

            case 4:
                TSPBruteForce tspBruteForce = TSPBruteForce(matrix);

                int *arr = new int[matrix->nrV]; //array in which we will calculate permutations
                for (int i = 0; i < matrix->nrV; ++i) {
                    arr[i] = i;
                }

                Timer timer;
                timer.startTimer(); //start the timer
                tspBruteForce.launch(arr, 1, matrix->nrV - 1); //launch algorithm
                double time = timer.stopTimer(); //stop the timer

                std::cout<<"Scores:"<<std::endl; //print scores from algorithm
                for (int i = 0; i < matrix->nrV; ++i) {
                    std::cout << tspBruteForce.stringOfVerticles[i] << "->"; //string of verticles
                }
                std::cout << tspBruteForce.stringOfVerticles[0]; //we come back to the beginning verticle

                std::cout << std::endl;
                std::cout << tspBruteForce.bestRoute << std::endl; //print cost of most optimal route
                std::cout << "Required time: " << std::endl; //print time of performing algorithm
                timer.printTime();

                delete[] arr; //free memory, delete array with stored permutations

                break;

        }

    }

}
