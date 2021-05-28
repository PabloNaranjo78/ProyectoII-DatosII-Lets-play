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

/**
 * Implementacion de las fisicas para BP game
 */
class Movement {
private:
    const int grid_x = 90;
    const int grid_y = 70;
    bool obstacles[9][9];
    int goals[4];
    bool collide = false;
    Scores * scores;
    /**
     * Verifica si se anota un tanto
     * @param team equipo al que se debe consultar
     * @return valor de verdad que indica si se efectua un tanto en dicho movimiento
     */
    bool goalScored(bool team); //Es un bool para saber si en el movimiento se anota

public:
    float x;
    float y;
    int a = -1;
    int b = -1;
    /**
     * Constructor de la clase
     * @param currentScores gestor del marcador
     * @param obstacles matriz que contiene los obstaculos
     */
    Movement(Scores * currentScores, bool obstacles[9][9]);
    /**
     * Configura la variables requeridas para generar un lanzamiento
     */
    void setUpLaunch();
    /**
     * Realiza un lanzamiento del puck segun las condiciones especificadas
     * @param force fuerza con la que se lanza
     * @param angle angulo de lanzamiento
     * @param init_x posicion inicial en x
     * @param init_y posicion inicial en y
     * @param puck objeto de la clase Puck
     * @return booleano que indica si se marca un tanto
     */
    bool performLaunch(int force, float angle, float init_x, float init_y, Sprite * puck);
    /**
     * Revisa si ocurre una colision en el lanzamiento
     * @param dir direccion en la que ocurre la colision (vertical u horizontal)
     * @return valor de verdad que indica si colisiona
     */
    bool checkObstacleCollision(bool dir);
    /**
     * Indica si el puck se encuentra en alguna porteria
     * @param x posicion en x
     * @param y posicion en y
     * @return valor de verdad que indica si esta en alguna porteria
     */
    bool checkInGoal(int x, int y);
};


#endif //PROYECTO2_MOVEMENT_H
