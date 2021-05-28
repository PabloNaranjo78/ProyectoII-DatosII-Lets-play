//
// Created by pablo on 17/5/21.
//

#ifndef BACKTRACKING_BACKTRACKINGSEARCH_H
#define BACKTRACKING_BACKTRACKINGSEARCH_H


#include "BTListRegister/BTLinkedList.h"

class BackTrackingSearch {
public:
    BackTrackingSearch(bool obstacles[9][9]);
    void printMatrix();
    LinkedList* getPath(int x, int y);
    void printPostList();
private:
    void add(int _matrix[9][9]);
    LinkedList* searchOnePath();
    void searchBestPath();
    LinkedList * getPostList();
    BTLinkedList list;
    void searchStart();
    bool closePath(int x, int y);
    int matrix[9][9]{};

    int startRow = 0;
    int startColumn = 0;
    string result = "";
    LinkedList* regList;
};


#endif //BACKTRACKING_BACKTRACKINGSEARCH_H
