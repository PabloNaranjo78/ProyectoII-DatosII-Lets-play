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
    BoardDisplay();
    void runGame();
    void checkEvents();
    void checkMousePosition();
    void checkCollisions();
    void setPlayerPath();
    void setComputerPath();
    void searchAngleStart(int current_pos, int first_on_path);
};


#endif //PROYECTO2_BOARDDISPLAY_H
