//
// Created by pablo on 18/5/21.
//

#ifndef BACKTRACKING_LINKEDLIST_H
#define BACKTRACKING_LINKEDLIST_H


#include "LLNode.h"
#include "iostream"
using namespace std;
class BTLinkedList {

public:
    BTLinkedList();
    void addToList(int _data[9][9],string movement);
    LLNode *getLastElement();
    string getLastMovement();
    void printList();
    void replaceInALl(int num,int x, int y);
private:
    LLNode *thisData = NULL;
    LLNode *firstData;
};


#endif //BACKTRACKING_LINKEDLIST_H
