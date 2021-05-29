//
// Created by david on 28/5/21.
//

#ifndef PROYECTO2_MENU_H
#define PROYECTO2_MENU_H

//#include "GameManagment/Board.h"
#include "../Graphics/BoardDisplay.h"
#include "../BT/BackTrackingSearch.h"
#include <SFML/Graphics.hpp>
#include "../Graphics/GeneticDisplay.h"
#include "../Graphics/GeneticDisplay.cpp"
#include "../Graphics/Button.h"


class Menu {
public:
    int width;
    int height;

    //window
    RenderWindow* window;

    //GUI
    RectangleShape background;

    //FONTS
    Font font;

    //TEXT
    Text title;

    //BUTTONS
    Button* BPbutton;
    Button* Gbutton;
    Button* Outbutton;

    //Variables
    bool keepOpen;

    Menu();
    void run();
    void update(Vector2f mousepos);
    void render();

};


#endif //PROYECTO2_MENU_H
