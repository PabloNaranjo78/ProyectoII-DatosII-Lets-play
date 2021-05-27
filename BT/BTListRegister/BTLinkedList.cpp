//
// Created by pablo on 18/5/21.
//

#include <iostream>
#include "BTLinkedList.h"
using namespace std;

BTLinkedList::BTLinkedList() {
}

void BTLinkedList::addToList(int _data[9][9],string movement, int x, int y) {
    if (thisData == NULL){
        thisData = new LLNode;
        thisData->setData(_data,movement);
        firstData = thisData;
    }else{
        LLNode *temp = thisData;
        thisData = new LLNode;
        thisData->setData(_data,movement);
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
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9;j++){
                cout<<temp->data[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"################"<<endl;
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
