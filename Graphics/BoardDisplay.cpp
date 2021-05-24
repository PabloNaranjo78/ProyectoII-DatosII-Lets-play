//
// Created by anthony on 18/5/21.
//

#include "BoardDisplay.h"


BoardDisplay::BoardDisplay() {
    this->keepOpen = true;
    this->bpGame = new RenderWindow(VideoMode(810,630), "BP Game: Hockey Edition");
    this->bpGame->setFramerateLimit(60);

}

void BoardDisplay::runGame() {
    while (this->keepOpen){
        this->bpGame->clear(Color::White);
        this->bpGame->display();
    }
}