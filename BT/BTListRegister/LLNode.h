//
// Created by pablo on 18/5/21.
//

#ifndef BACKTRACKING_LLNODE_H
#define BACKTRACKING_LLNODE_H
#include "iostream"
using namespace std;

class LLNode {
public:
    /***
     * @brief consturctur de los Nodos para la lista
     */
    LLNode();

  //  int getData();
    /***
     * @brief Define los valores que guarda el nodo, estos serían la matriz de este momento, el registro del movimiento
     * realizado y la posición en la que se hizo el movimiento
     * @param _data matriz de 9x9 que se desea guardar
     * @param movement movimiento que se hizo en esta desición, por ejemplo "-x" para cuando se hace un movimiento
     * de restar en x
     * @param pos posición de la matriz de posiciones del número al que se movió.
     */
    void setData(int _data[9][9], string movement, int pos);
    string movement;
    LLNode *prev = NULL;
    int data[9][9];
    int posMove = 0;

};


#endif //BACKTRACKING_LLNODE_H
