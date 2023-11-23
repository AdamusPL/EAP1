//
// Created by adamc on 18.11.2023.
//

#ifndef PEA1_FILEWRITER_H
#define PEA1_FILEWRITER_H
#include <fstream>
#include <cstring>
#include <iostream>

class FileWriter {
public:
    FileWriter(bool);
    long *results;
    void write(int, std::string, int);
};


#endif //PEA1_FILEWRITER_H
