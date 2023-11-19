//
// Created by adamc on 18.11.2023.
//

#include "Tests.h"
#include "TSPBruteForce.h"
#include "BranchAndBound.h"
#include "Randomizer.h"

void Tests::test(int choice){

    int N;
    std::cout<<"Enter N:"<<std::endl;
    std::cin>>N;

    std::string amount = "N";

    Randomizer randomizer;

    for (int i = 0; i < 100; ++i) {

        if(choice == 1){

            std::string type = "BF";
            std::string filename = type+"_"+amount+"_"+std::to_string(i);

        }
    }
}