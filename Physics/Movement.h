//
// Created by anthony on 17/5/21.
//

#ifndef PROYECTO2_MOVEMENT_H
#define PROYECTO2_MOVEMENT_H

#include <string>
#include <iostream>
#include <math.h>
#include "../GameManagment/Scores.h"

#define PI 3.14159265

class Movement {
private:
    const int grid_x = 50;
    const int grid_y = 70;
    int x;
    int y;
    bool obstacles[9][9];
    Scores * scores;
    bool goalScored(bool team) ; //Es un bool para saber si en el movimiento se anota
public:
    Movement(Scores * currentScores);
    void setObstacles(bool matrix[9][9]);
    void performLaunch(int force, int angle);
};


#endif //PROYECTO2_MOVEMENT_H
