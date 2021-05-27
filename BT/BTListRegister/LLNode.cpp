//
// Created by pablo on 18/5/21.
//

#include <cstring>
#include "LLNode.h"

LLNode::LLNode() {
}


void LLNode::setData(int _data[9][9],string _movement,int x,int y) {
    memcpy(data,_data,sizeof(int)*9*9);
    movement = _movement;
    posMove = (x*10)+y;
}

