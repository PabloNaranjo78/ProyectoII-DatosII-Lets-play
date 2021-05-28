//
// Created by anthony on 9/5/21.
//

#ifndef PROYECTO2_PATHFINDINGA_H
#define PROYECTO2_PATHFINDINGA_H
#include <iostream>
#include <string>
#include<stdlib.h>
#include<time.h>
#include "LinkedList.h"

using namespace std;
class PathfindingA {
private:
    const int valueSimple = 10;
    const int valueDiagonal = 14;
    int initial;
    int limitsAt = 9;
    int matrix [9][9];
    int matrix_names[9][9];
    bool obstacles[9][9];
    int positionAt[2];
    int goal[2];
    /**
     * Configura los valores de la matriz
     */
    void setMatrix();
    /**
     * Coloca obstaculos en ciertas poiciones de la pantalla
     * @param obstacles
     */
    void setObstacles(int obstacles);
    /**
     * Calcula el heuristico de un nodo
     * @param di columna en la matriz
     * @param dj fila en la matriz
     * @return valor del heuristico
     */
    int calculateHeuristics(int di, int dj);
    /**
     * Obtiene el valor asociado a una posicion relativa a la matriz
     * @param id posicion relativa a la matriz
     * @return valor actual
     */
    int getValueFrom(int id);
    /**
     * Verifica si hay un obstaculo en la posicion relativa a la matriz dada
     * @param id posicion relativa a la matriz
     * @return valor de verdad que indica si es un obstaculo
     */
    bool getObstacleFrom(int id);
    /**
     * Obtiene el minimo de la lista
     * @param listCheck lista de la que se obtendra el minimo
     * @return valor minimo
     */
    int getMin(LinkedList * listCheck);
    /**
     * Actualiza el valor en la matriz de posicion relativa a la matriz dad
     * @param id posicion relativa a la matriz
     * @param value valor que se desea sumar/sustituir
     * @param operation valor de verdad que indica si el valor sera sustituido o sumado
     */
    void updateValue(int id, int value, bool operation);
    /**
     * Indica si la posicion relativa a la matriz de la porteria esta en la lista
     * @param list lista a revisar
     * @return valor de verdad que indica si se tiene la porteria en la lista
     */
    bool isGoalIn(LinkedList * list);
    /**
     * Obtiene los nuevos elementos para el open list segun una posicion relativa a la matriz
     * @param currentOpen open list actual
     * @param currentClosed closed list actual
     * @param id posicion relativa a la matriz
     */
    void getNewELements(LinkedList * currentOpen, LinkedList * currentClosed, int id);
    /**
     * Muestra las matrices con las que se trabaja
     */
    void printMatrix();

public:
    string result;
    /**
     * Constructor de la clase
     * @param obstacles matriz booleana que contiene los obstaculos
     * @param goal porteria como un vector de posicion
     */
    PathfindingA(bool obstacles[9][9], int goal[2]);
    /**
     * Obtiene una lista con el camino que se debe seguir
     * @param di columna de la matriz que compone al valor
     * @param dj fila de la matriz que compone al valor
     * @return lista enlazada simple con las posiciones relativas que deben recorrerse
     */
    LinkedList * getPath(int di, int dj);


};


#endif //PROYECTO2_PATHFINDINGA_H
