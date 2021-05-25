//
// Created by pablo on 18/5/21.
//

#include <iostream>
#include "LinkedList.h"
using namespace std;
LinkedList::LinkedList() {
}

void LinkedList::addToList(int _data[9][9],string movement) {
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

LLNode* LinkedList::getLastElement() {
    LLNode *temp = thisData;
    thisData = thisData->prev;
    return thisData;
}

void LinkedList::printList() {
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

string LinkedList::getLastMovement() {
    return thisData->movement;
}

void LinkedList::replaceInALl(int num,int x, int y) {
    LLNode **temp = &thisData;
    while(*temp!= nullptr){
        (*temp)->data[y][x] = num;
        temp = &(*temp)->prev;
    }
}
