//
// Created by anthony on 18/5/21.
//

#ifndef PROYECTO2_BOARD_H
#define PROYECTO2_BOARD_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "../PathfindingA/PathfindingA.h"
#include "../Physics/Movement.h"
#include "Scores.h"
#include "../BT/BackTrackingSearch.h"

class Board {
private:
    const int grid_x = 90;
    const int grid_y = 70;
    int limitsAt;
    int goals[4];
    PathfindingA * pathfinder1;
    //PathfindingA * pathfinder2;
    Scores * scores;
    void setObstacles(int obstacles);
    BackTrackingSearch * backTrackingSearch;

public:
    Board();
    Movement * puck;
    bool turnPlayers;
    int obstaclesNum;
    int matrix_names[9][9];
    bool obstacles[9][9];
    LinkedList * getPathPlayer(int y, int x);


};


#endif //PROYECTO2_BOARD_H
