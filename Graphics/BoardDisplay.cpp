//
// Created by anthony on 18/5/21.
//

#include "BoardDisplay.h"


BoardDisplay::BoardDisplay() {
    this->keepOpen = true;
    this->board = new Board();
    this->bpGame = new RenderWindow(VideoMode(810,630), "BP Game: Hockey Edition");
    this->bpGame->setFramerateLimit(60);
    this->events = new Event();

}

void BoardDisplay::checkEvents() {
    while(this->bpGame->pollEvent(*events)){
        switch (events->type) {
            case Event::Closed:
                this->bpGame->close();
                exit(1);
                break;
        }

    }
}

void BoardDisplay::runGame() {

    Texture * backgroundImage = new Texture;
    backgroundImage->loadFromFile("../estadio.png");
    Sprite * bg = new Sprite;
    bg->setTexture(*backgroundImage);
    bg->setPosition(0.f,0.f);

    Texture * p1Image = new Texture;
    p1Image->loadFromFile("../player1.png");
//    Sprite * p1 = new Sprite;
//    p1->setTexture(*p1Image);

    Texture * p2Image = new Texture;
    p2Image->loadFromFile("../player2.png");
//    Sprite * p2 = new Sprite;
//    p2->setTexture(*p2Image);

    Sprite * obstacles[this->board->obstaclesNum];
    int indexAt = 0;
    cout << "Paso 1" << endl;
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if (this->board->obstacles[i][j] && i != 0 && j != 0 && i != 8 && j != 8){
                cout << "Found obstacle" << endl;
                obstacles[indexAt] = new Sprite;
                if (indexAt < this->board->obstaclesNum/2){
                    obstacles[indexAt]->setTexture(*p1Image);

                }else{
                    obstacles[indexAt]->setTexture(*p2Image);
                }
                obstacles[indexAt]->setPosition(float(j*this->grid_x), float(i*this->grid_y));
                indexAt++;
            }
        }
    }
    cout << "Paso 2" << endl;

    Texture * puckImage = new Texture();
    puckImage->loadFromFile("../puck.png");
    Sprite * puck = new Sprite;
    puck->setTexture(*puckImage);
    puck->setPosition(385,290);
    int force = 18;
    int out_when = 0;

    while (this->keepOpen){
        this->checkEvents();
        this->bpGame->clear(Color::White);
        this->bpGame->draw(*bg);
        this->bpGame->draw(*puck);
        if (force > 0 && out_when > 100){
            this->board->puck->performLaunch(force, -30, puck->getPosition().x, puck->getPosition().y, puck);
            force --;
        }
        for (int i=0; i<this->board->obstaclesNum; i++){
            this->bpGame->draw(*obstacles[i]);
        }
        out_when ++;
        this->bpGame->display();
    }
}