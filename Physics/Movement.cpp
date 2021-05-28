//
// Created by anthony on 17/5/21.
//

#include "Movement.h"


Movement::Movement(Scores *currentScores, bool obstacles[9][9]) {
    this->scores = currentScores;
    this->x = 600;
    this->y = 300;
    this->goals[0] = 4;
    this->goals[1] = 1;
    this->goals[2] = 4;
    this->goals[3] = 7;
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            this->obstacles[i][j] = obstacles[i][j];
        }
    }

}

void Movement::setUpLaunch() {
    this->a = -1;
    this->b = -1;
    this->collide = false;
}

bool Movement::performLaunch(int force, float angle, float init_x, float init_y, Sprite * puck) {
    this->x = init_x;
    this->y = init_y;
    cout << "a, b" << a << "," << b << endl;
    this->x = this->x+(this->a*force*cos(angle*PI/180.f));
    this->y = this->y+(this->b*force*sin(angle*PI/180.f));
    if (this->checkObstacleCollision(true) && !this->collide){
        cout << "Value changed A" << endl;
        this->b *= -1;
        this->collide = true;
    }else if (this->checkObstacleCollision(false) && !this->collide){
        cout << "Value changed B" << endl;
        this->a *= -1;
        this->collide = true;
    }
    puck->setPosition(this->x, this->y);
    if (this->checkInGoal(this->x, this->y)){
        return true;
    }
    return false;
    //sleep(0.001);
}

bool Movement::checkObstacleCollision(bool dir) {
    bool result = false;
    if (dir){
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (this->obstacles[i][j] == true){
                    if ((this->x+25 >= j*grid_x-10 && this->x+25 <= (j+1)*grid_x+10 && this->y >= i*grid_y+50 && this->y <= (i+1)*grid_y+10)){
                        result = true;
                    }else if ((this->x+25 >= j*grid_x-10 && this->x+25 <= (j+1)*grid_x+10 && this->y+50 >= i*grid_y-10 && this->y+50 <= i*grid_y+20)){
                        result = true;
                    }
                }
            }
        }

    }else{
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (this->obstacles[i][j] == true){
                    if ((this->y+25 >= i*grid_y-10 && this->y+25 <= (i+1)*grid_y+10 && this->x >= j*grid_x+70 && this->x <= (j+1)*grid_x+10)){
                        result = true;
                    }else if ((this->y+25 >= i*grid_y-10 && this->y+25 <= (i+1)*grid_y+10 && this->x+50 >= j*grid_x-10 && this->x+50 <= j*grid_x+20)){
                        result = true;
                    }
                }
            }
        }
    }

    return result;

}

bool Movement::checkInGoal(int x, int y) {
    if (x+25 >= this->grid_x*(this->goals[1]) && x+25 <= this->grid_x*(this->goals[1]+1) && y+25 >= this->grid_y*(this->goals[0]) && y+25 <= this->grid_y*(this->goals[0]+1)){
        this->scores->scoreFor(true);
        return true;
    }else if (x+25 >= this->grid_x*(this->goals[3]) && x+25 <= this->grid_x*(this->goals[3]+1) && y+25 >= this->grid_y*(this->goals[2]) && y+25 <= this->grid_y*(this->goals[2]+1)){
        this->scores->scoreFor(false);
        return true;
    }

    return false;

}