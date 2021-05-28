
//
// Created by anthony on 11/5/21.
//

#ifndef PROYECTO2_LINKEDLIST_H
#define PROYECTO2_LINKEDLIST_H


#include "Node.h"
#include <iostream>
#include <string>
/**
 * Implementacion de una lista enlazada simple
 */
using namespace std;
class LinkedList {
private:
    Node * head;
public:
    int length;
    /**
     * Constructor de la clase
     */
    LinkedList();
    /**
     * Agrega un valor a la lista
     * @param id identificador del valor
     */
    void addValue(int id);
    /**
     * Obtiene un valor en cierta posicion
     * @param i index que se desea consultar
     * @return identificador en dicha posicion
     */
    int getValueAt(int i);
    /**
     * Muestra los elementos de la lista
     */
    void printList();
    /**
     * Indica si el nodo se encuentra en la lista
     * @param id identificador asociado al nodo
     * @return valor de verdad para conocer si el valor ya esta asociado a un nodo
     */
    bool isIn(int id);
    /**
     * Elimina un nodo de la lista
     * @param id identificador del nodo
     */
    void deleteNode(int id);
    /**
     * Especifica el nodo padre de cierto nodo (pathfinding)
     * @param parent identificador del nodo padre
     * @param id identificador del nodo deseado
     */
    void setParent(int parent, int id);
    /**
     * Obtiene el nodo padre de cierto nodo (pathfinding)
     * @param id identificador del nodo
     * @return identificador del nodo padre
     */
    int getParent(int id);
    /**
     * Obtiene la lista en formato de string
     * @return lista en formato de string
     */
    string getListString();
};


#endif //PROYECTO2_LINKEDLIST_H
