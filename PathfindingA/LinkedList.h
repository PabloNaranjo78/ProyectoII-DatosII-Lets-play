
//
// Created by anthony on 11/5/21.
//

#ifndef PROYECTO2_LINKEDLIST_H
#define PROYECTO2_LINKEDLIST_H


#include "Node.h"
#include <iostream>
#include <string>

using namespace std;
class LinkedList {
private:
    Node * head;
public:
    LinkedList();
    void addValue(int val, int id);
    int getValueAtTop();
    void printList();
    bool isIn(int id);
    void deleteNode(int id);
};


#endif //PROYECTO2_LINKEDLIST_H
