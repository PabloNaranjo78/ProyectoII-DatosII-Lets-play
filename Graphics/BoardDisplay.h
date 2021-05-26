//
// Created by anthony on 18/5/21.
//
#ifndef PROYECTO2_BOARDDISPLAY_H
#define PROYECTO2_BOARDDISPLAY_H
#include <SFML/Graphics.hpp>
#include "../GameManagment/Board.h"

using namespace sf;

class BoardDisplay {
private:
    const int grid_x = 90;
    const int grid_y = 70;
    RenderWindow * bpGame;
    Board * board;
    Event * events;
    bool keepOpen;
    Vector2i pos_mouse;
public:
    BoardDisplay();
    void runGame();
    void checkEvents();
    void checkMousePosition();
    void checkCollisions();
    void checkMouse();
};


#endif //PROYECTO2_BOARDDISPLAY_H
