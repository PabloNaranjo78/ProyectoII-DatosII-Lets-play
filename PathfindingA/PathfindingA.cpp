//
// Created by anthony on 9/5/21.
//

#include "PathfindingA.h"

PathfindingA::PathfindingA(){

    this->result = "";
    this->goal[0] = 4;
    this->goal[1] = 8;
    this->setMatrix();
    this->setObstacles(8);
    this->printMatrix();

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
    int numAt = 1;
    for (int i = 0; i<this->limitsAt; i++) {
        for (int j = 0; j < this->limitsAt; j++) {
            this->matrix_names[i][j] = numAt;
            numAt++;
        }
    }
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
    cout << "Nombres:" << endl;
    for (int i = 0; i<this->limitsAt; i++) {
        for (int j = 0; j < this->limitsAt; j++) {
            cout << this->matrix_names[i][j] << " ";
        }
        cout << endl;
    }
}

void PathfindingA::setObstacles(int obstacles) {
    int obstaclesLeft = obstacles;
    while (obstaclesLeft > 0){
        int num1 = rand()%9;
        int num2 = rand()%9;
        if (!this->obstacles[num1][num2] && this->goal[0] != num1 && this->goal[1] != num2){
            this->obstacles[num1][num2] = true;
            obstaclesLeft--;
        }
    }
}

void PathfindingA::getNewELements(LinkedList *currentOpen, int id) {
    //Para un id, se buscan los adyacentes
    //centro arriba y centro abajo +/- 9
}

LinkedList PathfindingA::getPath(int di, int dj) {
    LinkedList * openList = new LinkedList();
    LinkedList * closedList = new LinkedList();
    LinkedList * pathFound = new LinkedList();
    closedList->addValue(0,this->matrix_names[di][dj]);
    bool found_path = false;
    //while (!found_path){

    //}
}