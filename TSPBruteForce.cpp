//
// Created by adamc on 18/10/2023.
//

#include "TSPBruteForce.h"

TSPBruteForce::TSPBruteForce(Matrix *matrix) {
    this->matrix = matrix;
    this->stringOfVerticles = new int [matrix->nrV];
    this->bestRoute = INT_MAX;
}

TSPBruteForce::~TSPBruteForce() {
    delete[] stringOfVerticles;
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
            route += matrix->adjMatrix[arr[i]][arr[i + 1]];
        }

        route += matrix->adjMatrix[arr[matrix->nrV - 1]][arr[0]];

        if(route < bestRoute){
            for (int i = 0; i < matrix->nrV; ++i) {
                stringOfVerticles[i] = arr[i];
            }
            bestRoute = route;
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

void TSPBruteForce::perm(int arr[], int l, int r){
    int x;

    if (l == r) {
        for(int i=0; i<matrix->nrV; i++){
            std::cout << arr[i] << " ";
        }
        std::cout<<std::endl;
    }
    else {

        for (int i = l; i <= r; i++) {

            x = arr[l]; //swap
            arr[l] = arr[i];
            arr[i] = x;

            perm(arr, l + 1, r); //recursion

            x = arr[l]; //swap
            arr[l] = arr[i];
            arr[i] = x;

        }
    }

}
