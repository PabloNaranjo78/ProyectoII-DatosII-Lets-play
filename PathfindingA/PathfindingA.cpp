//
// Created by anthony on 9/5/21.
//

#include "PathfindingA.h"

PathfindingA::PathfindingA(){

    this->result = "";
    this->goal[0] = 4;
    this->goal[1] = 8;
    this->setMatrix();
    //this->setObstacles(8);

}

void PathfindingA::setInitial(int di, int dj) {
    this->positionAt[0] = di;
    this->positionAt[1] = dj;
}

int PathfindingA::calculateHeuristics(int di, int dj) {
    int heuristic = abs(this->goal[0]-di) + abs(this->goal[1]-dj);
    return heuristic;
}

void PathfindingA::setMatrix() {
    for (int i = 0; i<this->limitsAt; i++){
        for (int j = 0; j<this->limitsAt; j++){
            this->matrix[i][j] = calculateHeuristics(i,j);
            this->obstacles[i][j] = false;
        }
    }
    this->printMatrix();
}

void PathfindingA::printMatrix() {
    cout << "Matriz:" << endl;
    for (int i = 0; i<this->limitsAt; i++) {
        for (int j = 0; j < this->limitsAt; j++) {
            cout << this->matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Obstaculos:" << endl;
    for (int i = 0; i<this->limitsAt; i++) {
        for (int j = 0; j < this->limitsAt; j++) {
            cout << this->obstacles[i][j] << " ";
        }
        cout << endl;
    }
}