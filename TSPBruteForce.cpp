//
// Created by adamc on 18/10/2023.
//

#include "TSPBruteForce.h"

TSPBruteForce::TSPBruteForce(Matrix *matrix) {
    this->matrix = matrix;
    this->stringOfNodes = new int [matrix->nrV];
    this->bestRoute = INT_MAX;
}

TSPBruteForce::~TSPBruteForce() {
    delete[] stringOfNodes;
}

void TSPBruteForce::launch(int arr[], int l, int r){
    int route = 0;
    int x;

    if (l == r) {
//        printing all permutations
//        for (int i = 0; i < matrix->nrV; ++i) {
//            std::cout<<arr[i]<<" ";
//        }
//        std::cout<<std::endl;

        for(int i = 0; i < matrix->nrV - 1; i++){
            route += matrix->adjMatrix[arr[i]][arr[i + 1]]; //take route length from matrix
        }

        route += matrix->adjMatrix[arr[matrix->nrV - 1]][arr[0]]; //we need to come back to the beginning verticle

        if(route < bestRoute){ //if we find better route than previous one
            for (int i = 0; i < matrix->nrV; ++i) {
                stringOfNodes[i] = arr[i]; //save that string of verticles
            }
            bestRoute = route; //save route cost
        }
    }

    else {

        for (int i = l; i <= r; i++) {

            x = arr[l]; //swap
            arr[l] = arr[i];
            arr[i] = x;

            launch(arr, l + 1, r); //recursion

            x = arr[l]; //swap
            arr[l] = arr[i];
            arr[i] = x;

        }
    }

}