
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
    int length;
    LinkedList();
    void addValue(int id);
    int getValueAt(int i);
    void printList();
    bool isIn(int id);
    void deleteNode(int id);
    void setParent(int parent, int id);
    int getParent(int id);
    string getListString();
};


#endif //PROYECTO2_LINKEDLIST_H
