//
// Created by pablo on 18/5/21.
//

#ifndef BACKTRACKING_LINKEDLIST_H
#define BACKTRACKING_LINKEDLIST_H


#include "LLNode.h"
#include "iostream"
#include "../../PathfindingA/LinkedList.h"

using namespace std;
class BTLinkedList {
public:
    /***
     * @brief Constructor de la clase para la lista enlazada para el backtracking.
     */
    BTLinkedList();
    /***
     * @brief Anade un elemento nuevo a la lista enlazada
     * @param _data matriz de 9x9 que se quiere guardar
     * @param movement movimiento que se realiza en esta desición
     * @param x punto en x en donde se movió
     * @param y punto en y en donde se movió
     */
    void addToList(int _data[9][9],string movement, int x, int y);
    /***
     * @brief Imprime la lista enlazada en consola
     */
    void printList();
    /***
     * @brief Toma un valor entero y lo pone en todas las matrices que se guardan en la lista enlazada
     * @param num numero que se quiere sustituir
     * @param x posición en x de donde se quiere poner el número
     * @param y posición en y de donde se queire poner el número
     */
    void replaceInALl(int num,int x, int y);
    /***
     * @brief Se utiliza para retornar el último elemento de la lista enlazada y a su vez elimina el
     * elemento retornado de la lista
     * @return retorna un nodo de la lista enlazada
     */
    LLNode *getLastElement();
    /***
     * @brief Retorna en forma de string el último movimiento realizado
     * @return string con el último movimiento realizado
     */
    string getLastMovement();
    //void printPostList();
    LinkedList* getPostList();
private:
    LLNode *thisData = NULL;
    LLNode *firstData;
    int matrix_names[9][9];
    LinkedList *regList;
};


#endif //BACKTRACKING_LINKEDLIST_H
