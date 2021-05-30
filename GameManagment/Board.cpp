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


    for (int i=0; i<this->limitsAt; i++){
        for (int j=0; j<this->limitsAt; j++){
            this->obstacles[i][j] = false;
        }
    }

    this->setObstacles(6);
    this->turnPlayers = true;
    this->scores = new Scores();
    this->obstaclesNum = 6;
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
    this->backTrackingSearch = new BackTrackingSearch(this->obstacles);
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
    int num1, num2;
    srand((unsigned)(time(0)));
    while (obstaclesLeft > 0){
        num1 = rand()%9;
        num2 = rand()%9;
        cout << "Num1 " << num1 << "Num2 "<< num2 << endl;
        if (!this->obstacles[num1][num2] && this->goals[0] != num1 && this->goals[1] != num2 && this->goals[2] != num1 && this->goals[3] != num2 && num1 != 4 && num2 != 4){
            cout << "obstacle set" << endl;
            this->obstacles[num1][num2] = true;
            obstaclesLeft--;
        }
    }
    cout << "obstaculos" << endl;
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            cout << this->obstacles[i][j] << " ";
        }
        cout << endl;
    }
}

LinkedList * Board::getPathPlayer(int y, int x) {
    int goal_init1[2] = {goals[0], goals[1]};
    this->pathfinder1 = new PathfindingA(this->obstacles, goal_init1);
    return this->pathfinder1->getPath(y/this->grid_y, x/this->grid_x);
}

LinkedList * Board::getPathComputer(int y, int x) {
    return this->backTrackingSearch->getPath(x/this->grid_x, y/this->grid_y);
}