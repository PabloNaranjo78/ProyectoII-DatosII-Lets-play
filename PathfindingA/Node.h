//
// Created by anthony on 11/5/21.
//

#ifndef PROYECTO2_NODE_H
#define PROYECTO2_NODE_H

#include <iostream>

using namespace std;
class Node {
public:
    Node * next;
    int id;
    int parent;
    Node(int id);
};


#endif //PROYECTO2_NODE_H
