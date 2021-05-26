//
// Created by pablo on 18/5/21.
//

#ifndef BACKTRACKING_LLNODE_H
#define BACKTRACKING_LLNODE_H
#include "iostream"
using namespace std;

class LLNode {
public:
    LLNode();

    int getData();
    void setData(int _data[9][9], string movement);
    string movement;
    LLNode *prev;
    int data[9][9];
private:
};


#endif //BACKTRACKING_LLNODE_H
