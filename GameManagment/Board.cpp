//
// Created by anthony on 18/5/21.
//

#include "Board.h"

Board::Board() {
    this->limitsAt = 9;
    this->goals[0] = 4;
    this->goals[1] = 1;
    this->goals[2] = 4;
    this->goals[3] = 7;
    int goal_init1[2] = {goals[0], goals[1]};
    int goal_init2[2] = {goals[2], goals[3]};
    this->scores = new Scores();
    this->puck = new Movement(scores);
    this->setObstacles(6);
    this->pathfinder1 = new PathfindingA(this->obstacles, goal_init1);
}

void Board::setObstacles(int obstacles) {
    int obstaclesLeft = obstacles;

    for (int i=0; i<this->limitsAt; i++){
        for (int j=0; j<this->limitsAt; j++){
            if (i == 0 || j == 0 || i == this->limitsAt-1 || j == this->limitsAt-1){
                this->obstacles[i][j] = true;
            }
        }
    }

    while (obstaclesLeft > 0){
        int num1 = rand()%9;
        int num2 = rand()%9;
        if (!this->obstacles[num1][num2] && this->goals[0] != num1 && this->goals[1] != num2){
            this->obstacles[num1][num2] = true;
            obstaclesLeft--;
        }
    }
}

void Board::getPathPlayer() {
    this->pathfinder1->getPath(this->puck->y/this->grid_y, this->puck->x/this->grid_x);
}