//
// Created by adamc on 18.11.2023.
//

#include "Menu.h"
#include "FileWriter.h"

Menu::Menu(){
    matrix = nullptr;
}

void Menu::option1() {
    FileReader fileReader;

    if(matrix != nullptr){ //free memory if previous matrix still exist
        delete matrix;
    }

    matrix = fileReader.read(); //read matrix data from .txt file and change pointer to it
}

void Menu::option2() {
    Randomizer randomizer;

    if(matrix != nullptr){ //free memory if previous matrix still exist
        delete matrix;
    }

    int N;
    std::cout<<"Enter N"<<std::endl;
    std::cin>>N;

    matrix = randomizer.generate(N); //generate random data into the matrix and change pointer to it
}

void Menu::option3() {
    if(matrix==nullptr){ //if matrix doesn't exist
        std::cout<<"Data hasn't been read yet"<<std::endl;
    }

    else {

        std::cout << matrix->nrV << std::endl; //print number of towns
        matrix->printMatrix(); //print matrix

    }
}

void Menu::option4(){

    int methodT = 3;
    std::cout << "1. Manual tests" << std::endl;
    std::cout << "2. Automatic tests" << std::endl;
    std::cin>>methodT;

    if(methodT == 1){
        manualTests();
    }

    else if(methodT == 2){
        automaticTests();
    }

}

void Menu::manualTests(){

    bool isAutomatic = false;
    if(matrix==nullptr){ //if matrix doesn't exist
        std::cout<<"Data hasn't been read yet"<<std::endl;
        return;
    }

    int method = 3;
    std::cout << "1. Brute force" << std::endl;
    std::cout << "2. Branch and bound" << std::endl;
    std::cin>>method;

    switch(method){
        case 1:
            bruteForce(isAutomatic);
            break;

        case 2:
            branchAndBound(isAutomatic);
            break;
    }
}

void Menu::automaticTests(){

    bool isAutomatic = true;

    if(matrix!=nullptr){
        delete matrix;
    }

    int method = 3;
    std::cout << "1. Brute force" << std::endl;
    std::cout << "2. Branch and bound" << std::endl;
    std::cin>>method;

    switch(method){
        case 1:
            bruteForce(isAutomatic);
            break;

        case 2:
            branchAndBound(isAutomatic);
            break;
    }

}

void Menu::bruteForce(bool isAutomatic){

    FileWriter fileWriter = FileWriter(isAutomatic);
    int numberOfInstances = 1;
    int N;
    double time;

    if(isAutomatic){
        std::cout<<"Enter N:"<<std::endl;
        std::cin>>N;
        numberOfInstances = 100;
    }

    for (int i = 0; i < numberOfInstances; ++i) {

        if(isAutomatic){ //if it's automatic test, we need to generate random matrix
            Randomizer randomizer;
            matrix = randomizer.generate(N);
        }

        TSPBruteForce *tspBruteForce = new TSPBruteForce(matrix);
        Timer timer;
        int *arr = new int[matrix->nrV]; //array in which we will calculate permutations

        for (int i = 0; i < matrix->nrV; ++i) {
            arr[i] = i;
        }

        timer.startTimer(); //start the timer
        tspBruteForce->launch(arr, 1, matrix->nrV - 1); //launch algorithm and find all possible permutations of array's elements with indexes [1;n-1]
        time=timer.stopTimer(); //stop the timer

        if(!isAutomatic) { //if it's manual test, then print scores
            std::cout << "Scores:" << std::endl; //print scores from algorithm
            for (int i = 0; i < matrix->nrV; ++i) {
                std::cout << tspBruteForce->stringOfNodes[i] << "->"; //string of verticles
            }
            std::cout << tspBruteForce->stringOfNodes[0]; //we come back to the beginning verticle

            std::cout << std::endl;
            std::cout << tspBruteForce->bestRoute << std::endl; //print cost of most optimal route
            std::cout << "Required time: " << std::endl; //print time of performing algorithm
            timer.printTime();
        }

        else{ //else, write score to .txt
            fileWriter.results[i] = time;
        }

        delete[] arr; //free memory, delete array with stored permutations
        delete tspBruteForce; //free memory, call the destructor
    }

    if(isAutomatic){
        fileWriter.write(N,"BF");
    }

}

void Menu::branchAndBound(bool isAutomatic){

    FileWriter fileWriter = FileWriter(isAutomatic);
    int numberOfInstances = 1;
    int N;
    double time;

    if(isAutomatic){
        std::cout<<"Enter N:"<<std::endl;
        std::cin>>N;
        numberOfInstances = 100;
    }

    for (int i = 0; i < numberOfInstances; ++i) {

        BranchAndBound *branchAndBound = new BranchAndBound(matrix);
        bool endedOnTime;
        Timer timer;

        timer.startTimer();
        endedOnTime = branchAndBound->launch(matrix, timer);

        if(endedOnTime) { //if algorithm ends within 5 min, then stop timer
            time=timer.stopTimer();
        }

        else{ //we don't care about the time
            return;
        }

        if(!isAutomatic) { //if it's manual test, then print scores
            std::cout << "Scores:" << std::endl; //print scores from algorithm
            for (int i = 0; i < branchAndBound->solution.size(); ++i) {
                std::cout << branchAndBound->solution[i] << "->"; //string of verticles
            }

            std::cout << "0"; //we come back to the beginning verticle

            std::cout << std::endl;
            std::cout << branchAndBound->bestRoute << std::endl; //print cost of most optimal route

            std::cout << "Required time: " << std::endl; //print time of performing algorithm
            timer.printTime();
        }

        else{
            fileWriter.results[i] = time;
        }

        delete branchAndBound;

    }

    if(isAutomatic){
        fileWriter.write(N,"BaB");
    }


}