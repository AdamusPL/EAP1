//
// Created by adamc on 18.11.2023.
//

#include "FileWriter.h"

FileWriter::FileWriter(bool isAutomatic){
    if(isAutomatic) {
        results = new long[100];
    }
}

void FileWriter::write(int N, std::string type, int done){

    std::fstream file;
    std::string filename = type+"_"+std::to_string(N)+".txt";

    file.open(filename, std::ios::out);
    long avg = 0;

    for (int i = 0; i < 100; i++) {
        file << results[i] << std::endl;
        avg += results[i];
    }

    avg = avg / done;

    file << std::endl;

    file << avg << std::endl;
}