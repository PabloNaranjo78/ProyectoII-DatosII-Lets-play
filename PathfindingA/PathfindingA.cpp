//
// Created by anthony on 9/5/21.
//

#include "PathfindingA.h"

PathfindingA::PathfindingA(bool obstacles[9][9], int goal[2]){

    this->result = "";
    this->goal[0] = goal[0];
    this->goal[1] = goal[1];
    for (int i=0; i<this->limitsAt; i++){
        for (int  j=0; j<this->limitsAt; j++){
            this->obstacles[i][j] = obstacles[i][j];
        }
    }
    this->setMatrix();
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
        if (!this->obstacles[num1][num2] && this->goal[0] != num1 && this->goal[1] != num2){
            this->obstacles[num1][num2] = true;
            obstaclesLeft--;
        }
    }
}

bool PathfindingA::getObstacleFrom(int id) {
    cout << "function called with" << id << endl;
    bool valueReturn = false;
    for (int i=0; i<this->limitsAt; i++){
        for (int j=0; j<this->limitsAt; j++){
            if (id == this->matrix_names[i][j]){
                cout << "Found at" << i << j << endl;
                valueReturn = this->obstacles[i][j];
                break;
            }
        }
    }
    return valueReturn;
}

int PathfindingA::getValueFrom(int id) {
    int valueReturn;
    for (int i=0; i<this->limitsAt; i++){
        for (int j=0; j<this->limitsAt; j++){
            if (id == this->matrix_names[i][j]){
                valueReturn = this->matrix[i][j];
                break;
            }
        }
    }

    return valueReturn;
}

void PathfindingA::getNewELements(LinkedList * currentOpen, LinkedList * currentClosed, int id) {
    //Para un id, se buscan los adyacentes
    //centro arriba y centro abajo +/- 9
    if (id-1 >= 0 && !this->getObstacleFrom(id-1) && id-1 != this->initial && !currentOpen->isIn(id-1) && !currentClosed->isIn(id-1)) {
        cout << "checking right" << endl;
        currentOpen->addValue(id-1);
        cout << "added" << endl;
        currentOpen->setParent(id, id-1);
        this->updateValue(id-1, this->getValueFrom(id) + 10, true);
    }
    else if (currentOpen->isIn(id-1)){
        cout << "into this" << endl;
        if (this->getValueFrom(id-1) > this->getValueFrom(id) + 10){
            this->updateValue(id-1, this->getValueFrom(id) + 10, false);
            currentOpen->setParent(id, id-1);
        }
    }

    cout << "first if" << endl;
    if (id+1 <= this->limitsAt * limitsAt && !this->getObstacleFrom(id+1) && id+1 != this->initial && !currentOpen->isIn(id+1) && !currentClosed->isIn(id+1)){
        currentOpen->addValue(id+1);
        currentOpen->setParent(id, id+1);
        this->updateValue(id-1, this->getValueFrom(id) + 10, true);
    }
    else if (currentOpen->isIn(id+1)){
        if (this->getValueFrom(id+1) > this->getValueFrom(id) + 10){
            this->updateValue(id+1, this->getValueFrom(id) + 10, false);
            currentOpen->setParent(id, id+1);
        }
    }


    //Agregar a los de arriba
    for (int i=0; i<3; i++){
        if (!currentOpen->isIn(id-10+i) && !currentClosed->isIn(id-10+i) && id-10+i >= 0 && !this->getObstacleFrom(id-10+i) && id-10+i != this->initial){
            currentOpen->addValue(id-10+i);
            if (i==0 || i==2){
                this->updateValue(id-10+i, this->getValueFrom(id) + 14, true);
            }else{
                this->updateValue(id-10+i, this->getValueFrom(id) + 10, true);
            }
            currentOpen->setParent(id, id-10+i);
        }
        else if (currentOpen->isIn(id-10+1)){
            if ((i==0 || i==2) && this->getValueFrom(id-10+1) > this->getValueFrom(id) + 14){
                this->updateValue(id-10+i, this->getValueFrom(id) + 14, false);
                currentOpen->setParent(id, id-10+i);
            }else if (this->getValueFrom(id-10+1) > this->getValueFrom(id) + 10){
                this->updateValue(id-10+i, this->getValueFrom(id) + 10, false);
                currentOpen->setParent(id, id-10+i);
            }
        }
    }

    for (int i=0; i<3; i++){
        if (!currentOpen->isIn(id+8+i) && !currentClosed->isIn(id+8+i) && id+8+i <= this->limitsAt * this->limitsAt && !this->getObstacleFrom(id+8+i) && id+8+i != this->initial){
            currentOpen->addValue(id+8+i);
            if (i==0 || i==2){
                this->updateValue(id+8+i, this->getValueFrom(id) + 14, true);
            }else{
                this->updateValue(id+8+i, this->getValueFrom(id) + 10, true);
            }
            currentOpen->setParent(id, id+8+i);
        }
        else if (currentOpen->isIn(id+8+1)){
            if ((i==0 || i==2) && this->getValueFrom(id+8+1) > this->getValueFrom(id) + 14){
                this->updateValue(id+8+i, this->getValueFrom(id) + 14, false);
                currentOpen->setParent(id, id+8+i);
            }else if (this->getValueFrom(id+8+1) > this->getValueFrom(id) + 10){
                this->updateValue(id+8+i, this->getValueFrom(id) + 10, false);
                currentOpen->setParent(id, id+8+i);
            }
        }
    }

    //Agregar a los de abajo
    currentOpen->printList();

}

bool PathfindingA::isGoalIn(LinkedList *list) {
    bool result = false;
    for (int i=0; i<list->length; i++){
        if (list->isIn(this->matrix_names[this->goal[0]][this->goal[1]])){
            result = true;
            break;
        }
    }
    return result;
}

void PathfindingA::updateValue(int id, int value, bool operation) {
    if (operation){
        for (int i=0; i<this->limitsAt; i++) {
            for (int j = 0; j < this->limitsAt; j++) {
                if (id == this->matrix_names[i][j]){
                    this->matrix[i][j] = this->matrix[i][j] + value;
                }
            }
        }
    }
    else{
        for (int i=0; i<this->limitsAt; i++) {
            for (int j = 0; j < this->limitsAt; j++) {
                if (id == this->matrix_names[i][j]){
                    this->matrix[i][j] = value;
                }
            }
        }
    }
}

int PathfindingA::getMin(LinkedList *listCheck) {
    listCheck->printList();
    int id_result = listCheck->getValueAt(0);
    int current_min = this->getValueFrom(listCheck->getValueAt(0));
    for (int i=0; i<listCheck->length-1; i++){
        if (this->getValueFrom(listCheck->getValueAt(i)) < current_min){
            cout << "found " << listCheck->getValueAt(i) << endl;
            current_min = this->getValueFrom(listCheck->getValueAt(i));
            id_result = listCheck->getValueAt(i);
        }
    }
    cout << "id result " << id_result << endl;
    return id_result;
}

LinkedList * PathfindingA::getPath(int di, int dj) {
    LinkedList * openList = new LinkedList();
    LinkedList * closedList = new LinkedList();
    LinkedList * pathFound = new LinkedList();

    if (this->matrix_names[di][dj] == this->matrix_names[this->goal[0]][this->goal[1]]){
        return pathFound;
    }

    closedList->addValue(this->matrix_names[di][dj]);
    this->initial = this->matrix_names[di][dj];
    cout << "id used: " << this->initial << endl;
    int id_used = this->matrix_names[di][dj];
    cout << "getting first round" << endl;
    this->getNewELements(openList, closedList,this->matrix_names[di][dj]);
    cout << "gotten!" << endl;
    this->printMatrix();
    int checking;

    while (!this->isGoalIn(openList)){

        cout << "paso 1" << endl;
        checking = this->getMin(openList);

        cout << "checking value: " << checking << endl;
        cout << "paso 2" << endl;
        closedList->addValue(checking);
        closedList->setParent(openList->getParent(checking),checking);

        cout << "paso 3" << endl;
        openList->deleteNode(checking);

        cout << "paso 4" << endl;
        this->getNewELements(openList, closedList,checking);

        cout << "paso 5" << endl;
        cout << "Open list:" << endl;
        openList->printList();
        cout << "Closed list:" << endl;
        closedList->printList();
        this->printMatrix();
    }

    int current_checking = openList->getParent(this->matrix_names[this->goal[0]][this->goal[1]]);
    pathFound->addValue(current_checking);
    cout << "primer check" << current_checking << endl;
    current_checking = closedList->getParent(current_checking);

    while (current_checking != this->matrix_names[di][dj]){
        cout << "getting path" << endl;
        pathFound->addValue(current_checking);
        current_checking = closedList->getParent(current_checking);
        cout << "checking current: " << current_checking << endl;
        if (current_checking == 0){
            break;
        }
    }
    pathFound->addValue(this->initial);
    cout << "path list:" << endl;
    pathFound->printList();
    cout << "Open list:" << endl;
    openList->printList();
    cout << "Closed list:" << endl;
    closedList->printList();
    cout << "id used: " << this->initial << endl;
    cout << "final del proceso con exito" << endl;
    cout << "len" << pathFound->length << endl;
    return pathFound;
}