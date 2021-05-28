//
// Created by anthony on 18/5/21.
//

#ifndef PROYECTO2_BOARD_H
#define PROYECTO2_BOARD_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "../PathfindingA/PathfindingA.h"
#include "../Physics/Movement.h"
#include "Scores.h"
#include "../BT/BackTrackingSearch.h"

/**
 * Clase gestora
 */
class Board {
private:
    const int grid_x = 90;
    const int grid_y = 70;
    int limitsAt;
    int goals[4];
    PathfindingA * pathfinder1;
    /**
     * Genera una cantidad de obstaculos en posiciones aleatorias
     * @param obstacles numero de obstaculos
     */
    void setObstacles(int obstacles);
    BackTrackingSearch * backTrackingSearch;

public:
    Board();
    Movement * puck;
    Scores * scores;
    bool turnPlayers;
    int obstaclesNum;
    int matrix_names[9][9];
    bool obstacles[9][9];
    /**
     * Retorna la lista que contiene el camino que se sugiere al jugador
     * @param y posicion en y del puck
     * @param x posicion en x del puck
     * @return lista enlazada que contiene el camino encontrado (en enteros)
     */
    LinkedList * getPathPlayer(int y, int x);
    /**
     * Retorna la lista que contiene el camino que sera seguido para la computadora
     * @param y posicion en y del puck
     * @param x posicion en x del puck
     * @return lista enlazda que contiene el camino encontrado (en enteros)
     */
    LinkedList * getPathComputer(int y, int x);

};


#endif //PROYECTO2_BOARD_H
