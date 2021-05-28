//
// Created by anthony on 11/5/21.
//

#ifndef PROYECTO2_NODE_H
#define PROYECTO2_NODE_H

#include <iostream>

using namespace std;
/**
 * Nodo de la lista enlazada simple
 */
class Node {
public:
    Node * next;
    int id;
    int parent;
    /**
     * Constructor de la clase
     * @param id identificador del nodo
     */
    Node(int id);
};


#endif //PROYECTO2_NODE_H
