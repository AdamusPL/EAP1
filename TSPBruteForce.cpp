//
// Created by adamc on 18/10/2023.
//

#include "TSPBruteForce.h"

TSPBruteForce::TSPBruteForce(Matrix *matrix) {
    this->matrix = matrix;
    this->stringOfVerticles = new int [matrix->nrV];
    this->bestRoute = INT_MAX;
}

void TSPBruteForce::launch(int tab[], int l, int r){
    int route = 0;
    int x;
    // Base case
    if (l == r) {
//        printing all permutations
//        for (int i = 0; i < matrix->nrV; ++i) {
//            std::cout<<tab[i]<<" ";
//        }
//        std::cout<<std::endl;

        for(int i = 0; i < matrix->nrV - 1; i++){
            route += matrix->adjMatrix[tab[i]][tab[i+1]];
        }

        route += matrix->adjMatrix[tab[matrix->nrV - 1]][tab[0]];

        if(route < bestRoute){
            for (int i = 0; i < matrix->nrV; ++i) {
                stringOfVerticles[i] = tab[i];
            }
            bestRoute = route;
        }
    }
    else {
        // Permutations made
        for (int i = l; i <= r; i++) {

            // Swapping done
            x = tab[l];
            tab[l] = tab[i];
            tab[i] = x;

            // Recursion called
            launch(tab, l + 1, r);

            // backtrack
            x = tab[l];
            tab[l] = tab[i];
            tab[i] = x;

        }
    }

}

void TSPBruteForce::perm(int tab[], int l, int r){
    int x;
    // Base case
    if (l == r) {
        for(int i=0; i<matrix->nrV; i++){
            std::cout<<tab[i]<<" ";
        }
        std::cout<<std::endl;
    }
    else {
        // Permutations made
        for (int i = l; i <= r; i++) {

            // Swapping done
            x = tab[l];
            tab[l] = tab[i];
            tab[i] = x;

            // Recursion called
            perm(tab, l + 1, r);

            // backtrack
            x = tab[l];
            tab[l] = tab[i];
            tab[i] = x;

        }
    }

}
