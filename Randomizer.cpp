//
// Created by adamc on 09/10/2023.
//

#include "Randomizer.h"

//generating random complete graph
Matrix* Randomizer::generate(int N) {

    int distance;
    Matrix *matrix = new Matrix(N);

    srand(time(NULL)); //initialize seed of random number generator

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix->adjMatrix[i][j]=-1; //fill the matrix with value -1
        }
    }
    
    for(int i=0; i<N; i++){
        for (int j = 0; j < N; ++j) {
            if(i!=j && matrix->adjMatrix[i][j]==-1) { //if it isn't the same vertex
                distance = rand() % 100 + 1; // random number [1;100]
                matrix->adjMatrix[i][j] = distance; //asymetric graph
            }
        }
    }

    return matrix;

}
