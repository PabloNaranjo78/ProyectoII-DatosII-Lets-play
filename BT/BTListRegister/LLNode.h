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
    void setData(int _data[9][9], string movement, int x,int y);
    string movement;
    LLNode *prev;
    int data[9][9];
    int posMove = 0;
private:
};


#endif //BACKTRACKING_LLNODE_H
