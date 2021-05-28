//
// Created by pablo on 18/5/21.
//

#include <iostream>
#include "BTLinkedList.h"
using namespace std;

BTLinkedList::BTLinkedList() {

    int numAt = 1;
    for (int i = 0; i<9; i++) {
        for (int j = 0; j < 9; j++) {
            matrix_names[i][j]  = numAt;
            cout<<numAt<<" ";
            numAt++;
        } cout<<endl;
    }
}

void BTLinkedList::addToList(int _data[9][9],string movement, int x, int y) {


    cout<<matrix_names[y][x]<<"~~~~~~~~~"<<endl;
    if (thisData == NULL){
        thisData = new LLNode;
        thisData->setData(_data,movement,matrix_names[y][x]);
//        firstData = thisData;
    }else{
        LLNode *temp = thisData;
        thisData = new LLNode;
        thisData->setData(_data,movement,matrix_names[y][x]);
        thisData->prev = temp;
    }
}

LLNode* BTLinkedList::getLastElement() {
    LLNode *temp = thisData;
    thisData = thisData->prev;
    return thisData;
}

void BTLinkedList::printList() {
    LLNode *temp = thisData;
    while(temp!= nullptr){

        cout<<temp->posMove<<"<--"<<endl;
      //  cout<<"################"<<endl;
        temp = temp->prev;
    }
}

string BTLinkedList::getLastMovement() {
    return thisData->movement;
}

void BTLinkedList::replaceInALl(int num,int x, int y) {
    LLNode **temp = &thisData;
    while(*temp!= nullptr){
        (*temp)->data[y][x] = num;
        temp = &(*temp)->prev;
    }
}

LinkedList* BTLinkedList::getPostList() {
    LLNode *temp = thisData;
    LinkedList* result = new LinkedList;
    while(temp!= nullptr){
        result->addValue(temp->posMove);
        temp = temp->prev;
    }

    return result;
}

