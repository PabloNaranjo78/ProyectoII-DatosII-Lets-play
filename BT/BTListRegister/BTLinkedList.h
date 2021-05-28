//
// Created by pablo on 18/5/21.
//

#ifndef BACKTRACKING_LINKEDLIST_H
#define BACKTRACKING_LINKEDLIST_H


#include "LLNode.h"
#include "iostream"
#include "../../PathfindingA/LinkedList.h"

using namespace std;
class BTLinkedList {

public:
    BTLinkedList();
    void addToList(int _data[9][9],string movement, int x, int y);
    LLNode *getLastElement();
    string getLastMovement();
    void printList();
    //void printPostList();
    LinkedList* getPostList();
    void replaceInALl(int num,int x, int y);
private:
    LLNode *thisData = NULL;
    LLNode *firstData;
    int matrix_names[9][9];
    LinkedList *regList;

};


#endif //BACKTRACKING_LINKEDLIST_H
