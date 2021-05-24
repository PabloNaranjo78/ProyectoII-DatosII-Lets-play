//
// Created by anthony on 18/5/21.
//

#ifndef PROYECTO2_BOARDDISPLAY_H
#define PROYECTO2_BOARDDISPLAY_H
#include <SFML/Graphics.hpp>

using namespace sf;

class BoardDisplay {
private:
    RenderWindow * bpGame;
    bool keepOpen;
public:
    BoardDisplay();
    void runGame();
};


#endif //PROYECTO2_BOARDDISPLAY_H
