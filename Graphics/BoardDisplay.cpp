//
// Created by anthony on 18/5/21.
//

#include "BoardDisplay.h"


BoardDisplay::BoardDisplay() {

    this->keepOpen = true;
    this->board = new Board();
    this->bpGame = new RenderWindow(VideoMode(1060,630), "BP Game: Hockey Edition");
    this->bpGame->setFramerateLimit(60);
    this->events = new Event();

    //this->board->getPathPlayer(160, 610);

}

void BoardDisplay::checkEvents() {
    while(this->bpGame->pollEvent(*events)){
        switch (events->type) {
            case Event::Closed:
                this->bpGame->close();
                exit(1);
                break;
            case Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left)){
                    //Up button angle
                    if (this->pos_mouse.x >= 900 && this->pos_mouse.x <= 950 && this->pos_mouse.y >= 50 && this->pos_mouse.y <= 90){

                    }
                    //Down button angle
                    else if (this->pos_mouse.x >= 900 && this->pos_mouse.x <= 950 && this->pos_mouse.y >= 165 && this->pos_mouse.y <= 200){

                    }
                    //Up button force
                    else if (this->pos_mouse.x >= 900 && this->pos_mouse.x <= 950 && this->pos_mouse.y >= 280 && this->pos_mouse.y <= 315){

                    }
                    //Down button force
                    else if (this->pos_mouse.x >= 900 && this->pos_mouse.x <= 950 && this->pos_mouse.y >= 385 && this->pos_mouse.y <= 420){

                    }
                    //Launch Button
                    else if (this->pos_mouse.x >= 850 && this->pos_mouse.x <= 1015 && this->pos_mouse.y >= 485 && this->pos_mouse.y <= 535){

                    }
                    //Step Button
                    else if (this->pos_mouse.x >= 850 && this->pos_mouse.x <= 1015 && this->pos_mouse.y >= 545 && this->pos_mouse.y <= 595){

                    }

                }
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
    this->puck = new Sprite;
    this->puck->setTexture(*puckImage);
    this->puck->setPosition(385,290);

    Texture * panelImage = new Texture;
    panelImage->loadFromFile("../PanelControl.png");
    Sprite * panel = new Sprite;
    panel->setTexture(*panelImage);
    panel->setPosition(810,0);

    Texture * direct = new Texture;
    direct->loadFromFile("../blueDirection.png");


    int force = 15;
    int out_when = 0;
    bool launching = !true;
    bool calculating = true;

    while (this->keepOpen){
        this->checkMousePosition();
        this->checkEvents();
        this->bpGame->clear(Color::White);
        this->bpGame->draw(*bg);
        this->bpGame->draw(*puck);
        this->bpGame->draw(*panel);
        if (calculating && this->board->turnPlayers){
            this->listPathPlayer = this->board->getPathPlayer(this->puck->getPosition().y, this->puck->getPosition().x);
            calculating = false;
        }
        if (!launching && this->board->turnPlayers){
            //cout << "into cycle" << endl;
            Sprite * dirB[this->listPathPlayer->length];
            //cout << "variable declared" << endl;
            //this->setPlayerPath();
            for (int x=0; x<(this->listPathPlayer->length)-1; x++){
                //cout << "length, at" << this->listPathPlayer->length << ":" << x << endl;
                dirB[x] = new Sprite;
                dirB[x]->setTexture(*direct);
                //cout << "Setting texture" << endl;
                for (int i=0; i<9; i++){
                    for (int j=0; j<9; j++){
                        //cout << "ValueAt, Board" << listResult->getValueAt(x) << ":" << this->board->matrix_names[i][j] << endl;
                        if (this->listPathPlayer->getValueAt(x) == this->board->matrix_names[i][j]){
                            //cout << "drawing" << endl;
                            dirB[x]->setPosition(j*grid_x+10, i*grid_y);
                            this->bpGame->draw(*dirB[x]);
                        }
                    }
                }
            }

        }else if (!launching && !this->board->turnPlayers){
            //this->setPlayerPath();
        }
        if (force > 0 && launching && out_when > 100){
            this->board->puck->performLaunch(force, 45, this->puck->getPosition().x, this->puck->getPosition().y, this->puck);
            force --;
        }
        for (int i=0; i<this->board->obstaclesNum; i++){
            this->bpGame->draw(*obstacles[i]);
        }
        out_when ++;
        this->bpGame->display();
    }
}

void BoardDisplay::checkMousePosition() {

    this->pos_mouse = Mouse::getPosition(*this->bpGame);
    this->pos_mouse = (Vector2i) this->bpGame->mapPixelToCoords(this->pos_mouse);

}

void BoardDisplay::setPlayerPath() {
    //this->listPathPlayer = this->board->getPathPlayer((float)this->puck->getPosition().y, (float)this->puck->getPosition().x);




}