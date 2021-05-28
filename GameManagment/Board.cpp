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
    this->turnPlayers = true;
    this->scores = new Scores();
    this->obstaclesNum = 6;
    this->setObstacles(6);
    this->puck = new Movement(scores, this->obstacles);
    int numAt = 1;
    for (int i=0; i<this->limitsAt; i++){
        for (int j=0; j<this->limitsAt; j++){
            this->matrix_names[i][j] = numAt;
            cout<< numAt << " ";
            numAt++;
        }
        cout << endl;
    }
    //obstacles, portería 47,
    backTrackingSearch = new BackTrackingSearch(obstacles);
    this->pathfinder1 = new PathfindingA(this->obstacles, goal_init1);
    this->pathfinder2 = new PathfindingA(this->obstacles, goal_init2);
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
        int num1 = rand()%this->limitsAt;
        int num2 = rand()%this->limitsAt;
        if (!this->obstacles[num1][num2] && this->goals[0] != num1 && this->goals[1] != num2 && this->goals[2] != num1 && this->goals[3] != num2 && num1 != 4 && num2 != 4){
            this->obstacles[num1][num2] = true;
            obstaclesLeft--;
        }
    }
}

LinkedList * Board::getPathPlayer(int y, int x) {
    return this->pathfinder1->getPath(y/this->grid_y, x/this->grid_x);
}

LinkedList * Board::getPathComputer(int y, int x) {
    return this->pathfinder2->getPath(y/this->grid_y, x/this->grid_x);
}