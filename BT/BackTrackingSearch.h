//
// Created by pablo on 17/5/21.
//

#ifndef BACKTRACKING_BACKTRACKINGSEARCH_H
#define BACKTRACKING_BACKTRACKINGSEARCH_H


#include "BTListRegister/LinkedList.h"

class BackTrackingSearch {
public:
    BackTrackingSearch();
    void add(int _matrix[9][9]);
    void printMatrix();
    void searchOnePath();
    void searchBestPath();
private:
    LinkedList list;
    void searchStart();
    bool closePath(int x, int y);
    int matrix[9][9]{};
    int startRow = 0;
    int startColumn = 0;
    string result = "";
};


#endif //BACKTRACKING_BACKTRACKINGSEARCH_H