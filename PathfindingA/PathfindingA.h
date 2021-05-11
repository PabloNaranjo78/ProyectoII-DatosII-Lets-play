//
// Created by anthony on 9/5/21.
//

#ifndef PROYECTO2_PATHFINDINGA_H
#define PROYECTO2_PATHFINDINGA_H
#include <iostream>
#include <string>
#include<stdlib.h>
#include<time.h>
#include "LinkedList.h"

using namespace std;
class PathfindingA {
private:
    const int valueSimple = 10;
    const int valueDiagonal = 14;
    int limitsAt = 9;
    int matrix [9][9];
    int matrix_names[9][9];
    int positionAt[2];
    int goal[2];
    bool obstacles[9][9];
    void setMatrix();
    void setObstacles(int obstacles);
    int calculateHeuristics(int di, int dj);
    void getNewELements(LinkedList * currentOpen, int id);
    void printMatrix();

public:
    string result;
    PathfindingA();
    LinkedList getPath(int di, int dj);


};


#endif //PROYECTO2_PATHFINDINGA_H
