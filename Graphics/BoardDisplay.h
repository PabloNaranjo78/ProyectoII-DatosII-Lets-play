//
// Created by anthony on 18/5/21.
//
#ifndef PROYECTO2_BOARDDISPLAY_H
#define PROYECTO2_BOARDDISPLAY_H
#include <SFML/Graphics.hpp>
#include "../GameManagment/Board.h"
#include <SFML/Network.hpp>
#include "rapidjson/document.h"

using namespace sf;
using namespace rapidjson;


/**
 * Interfaz grafica para BP game
 */
class BoardDisplay {
private:
    const int grid_x = 90;
    const int grid_y = 70;
    int angle;
    int force;
    int step;
    Text * score;
    Text * angleT;
    Text * forceT;
    bool launching;
    RenderWindow * bpGame;
    Board * board;
    Event * events;
    Sprite * puck;
    bool keepOpen;
    Vector2i pos_mouse;
    Font * font;
    LinkedList * listPathPlayer;
    LinkedList * listComputerPath;


public:
    /**
     * Constructor de la clase
     */
    BoardDisplay();
    /**
     * Ciclo de juego en el que los valores cambian internamente
     */
    void runGame();
    /**
     * Revisa los eventos relacionados al mouse o la ventana
     */
    void checkEvents();
    /**
     * Revisa la posicion del mouse y la actualiza
     */
    void checkMousePosition();
    /**
     * Revisa las colisiones con los bordes y los obstaculos
     */
    void checkCollisions();
    /**
     * Busca el camino que se sugiere al jugador
     */
    void setPlayerPath();
    /**
     * Busca el camino que debe seguir el lanzamiento de la computadora
     */
    void setComputerPath();
    /**
     * Busca el angulo donde inicia el lanzamiento
     * @param current_pos posicion inicial relativa a la matriz
     * @param first_on_path primera posicion a la que se va
     */
    void searchAngleStart(int current_pos, int first_on_path);
};


#endif //PROYECTO2_BOARDDISPLAY_H
