//
// Created by adamc on 17.11.2023.
//

#include "Node.h"

Node::Node(int nrV){
    matrix = new Matrix(nrV);
}

Node::~Node(){

    delete matrix;

}
