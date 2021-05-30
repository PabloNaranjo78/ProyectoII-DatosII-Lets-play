//
// Created by pablo on 17/5/21.
//

#ifndef BACKTRACKING_BACKTRACKINGSEARCH_H
#define BACKTRACKING_BACKTRACKINGSEARCH_H


#include "BTListRegister/BTLinkedList.h"

class BackTrackingSearch {
public:
    /***
     * @brief Constructor de la clase BackTracking, en esta se definen los obstáculos que hay en el tablero
     * @param obstacles esta es una matriz booleana en donde vienen representados los obstáculos del tablero
     */
    BackTrackingSearch(bool obstacles[9][9]);
    /***
     * @brief imprime la matriz acual
     */
    void printMatrix();
    /***
     * @brief Se encarga de llamar las funciones para generar un camino entre los puntos iniciales y finales
     * @param x posición en x del punto inicial
     * @param y posición en y del punto inicial
     * @return retorna una lista enlazada con el camino de la solución
     */
    LinkedList* getPath(int x, int y);
    /***
     * @brief Imprime en consola las posiciones de la solución final
     */
    void printPostList();
private:
    /***
     * @brief Añade una matriz de 9x9 a la clase, esta clase ya contiene el punto inicial, final y obstáculos,
     * los obstáculos se representan con un 4, el punto inicial con un 3 y el final con un 2
     * @param _matrix matriz de 9x9 con obstáculos, punto inicial y final.
     */
    void add(int _matrix[9][9]);
    /***
     * @brief Busca una solución en el camino entre el punto inicial y final
     * @return retorna lista enlazada con las soluciones finales
     */
    LinkedList* searchOnePath();
    /***
     * @brief Limpia la matriz, haciendo que los valores de la matriz sean 0 y también vuele a pones los obstáculos
     */
    void clearMatrix();
    /***
     * @brief Busca el punto de inicio de la matriz
     */
    void searchStart();
    /***
     * @brief Verifica si se ha llegado a un punto en el que se debe retornar a la solución anterior, esto
     * sucede cuando se está en un punto sin salida.
     * @param x Punto en x a evaluar
     * @param y Punto en y a evaluar
     * @return retorna true si se está en un punto que necesitar retornar y false si no
     */
    bool closePath(int x, int y);
    int matrix[9][9];
    bool obstacles[9][9];
    int startRow = 0;
    int startColumn = 0;
    LinkedList * getPostList();
    BTLinkedList* list;
    string result = "";
    LinkedList* regList;

};


#endif //BACKTRACKING_BACKTRACKINGSEARCH_H
