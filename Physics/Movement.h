//
// Created by anthony on 17/5/21.
//

#ifndef PROYECTO2_MOVEMENT_H
#define PROYECTO2_MOVEMENT_H

#include <string>
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "../GameManagment/Scores.h"
#include <iostream>


#define PI 3.14159265

using namespace std;
using namespace sf;
class Movement {
private:
    const int grid_x = 90;
    const int grid_y = 70;
    bool obstacles[9][9];
    int goals[4];
    bool collide = false;
    Scores * scores;
    bool goalScored(bool team) ; //Es un bool para saber si en el movimiento se anota

public:
    float x;
    float y;
    int a = -1;
    int b = -1;
    Movement(Scores * currentScores, bool obstacles[9][9]);
    void performLaunch(int force, float angle, float init_x, float init_y, Sprite * puck);
    bool checkObstacleCollision(bool dir);
    bool checkInGoal(int x, int y);
};


#endif //PROYECTO2_MOVEMENT_H
