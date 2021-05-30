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
                        cout << "1" << endl;
                        if (this->angle < 360){
                            this->angle+=10;
                        }
                    }
                    //Down button angle
                    else if (this->pos_mouse.x >= 900 && this->pos_mouse.x <= 950 && this->pos_mouse.y >= 165 && this->pos_mouse.y <= 200){
                        cout << "2" << endl;
                        if (this->angle > -90){
                            this->angle-=10;
                        }
                    }
                    //Up button force
                    else if (this->pos_mouse.x >= 900 && this->pos_mouse.x <= 950 && this->pos_mouse.y >= 280 && this->pos_mouse.y <= 315){
                        cout << "3" << endl;
                        if (this->force < 15){
                            this->force++;
                        }
                    }
                    //Down button force
                    else if (this->pos_mouse.x >= 900 && this->pos_mouse.x <= 950 && this->pos_mouse.y >= 385 && this->pos_mouse.y <= 420){
                        cout << "4" << endl;
                        if (this->force > 0){
                            this->force--;
                        }
                    }
                    //Launch Button
                    else if (this->pos_mouse.x >= 850 && this->pos_mouse.x <= 1015 && this->pos_mouse.y >= 485 && this->pos_mouse.y <= 535){
                        cout << "5" << endl;
                        if (!this->launching && this->board->turnPlayers){
                            this->launching = true;
                        }
                    }
                    //Step Button
                    else if (this->pos_mouse.x >= 850 && this->pos_mouse.x <= 1015 && this->pos_mouse.y >= 545 && this->pos_mouse.y <= 595){
                        cout << "6" << endl;
                        this->step++;
                    }

                }
                break;
        }

    }
}

string jsonSender(string type, int x, int y)
{
    string jsonStr = R"({"type":")"+ type + R"(","x":")" + to_string(x)  + R"(","y":")" + to_string(y) + "\"}";
    return jsonStr;
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
                cout << "Found obstacle" << this->board->matrix_names[i][j] << endl;
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

    Texture * direct2 = new Texture;
    direct2->loadFromFile("../redDirection.png");

    this->font = new Font;
    this->font->loadFromFile("../colleges.ttf");

    this->score = new Text;
    this->score->setFont(*this->font);
    this->score->setPosition(400.f, 15.f);
    this->score->setCharacterSize(25);
    this->score->setFillColor(Color::White);

    this->angleT = new Text;
    this->angleT->setFont(*this->font);
    this->angleT->setPosition(890.f, 115.f);
    this->angleT->setCharacterSize(22);
    this->angleT->setFillColor(Color::Yellow);

    this->forceT = new Text;
    this->forceT->setFont(*this->font);
    this->forceT->setPosition(890.f, 335.f);
    this->forceT->setCharacterSize(22);
    this->forceT->setFillColor(Color::Yellow);

    Text * winner = new Text;
    winner->setFont(*this->font);
    winner->setPosition(300.f, 590.f);
    winner->setCharacterSize(40);
    winner->setFillColor(Color::Black);

    String winnerStr = "";

    this->force = 8;
    this->angle = 40;
    int out_when = 0;
    this->launching = false;
    bool calculating = true;
    bool first_in = true;
    this->step = 1;

    IpAddress ip = IpAddress::getLocalAddress();
    TcpSocket socket;
    size_t received;
    Packet packetR;

    //Se conecta el cliente al socket
    socket.connect(ip, 8080);
    socket.setBlocking(false);
    string json;

    while (this->keepOpen){


        this->checkMousePosition();
        this->checkEvents();
        this->bpGame->clear(Color::White);
        this->bpGame->draw(*bg);
        this->bpGame->draw(*puck);
        this->bpGame->draw(*panel);
        this->bpGame->draw(*this->score);

        this->score->setString(this->board->scores->getCurrentScore());
        this->bpGame->draw(*this->score);

        this->forceT->setString(to_string(this->force));
        this->bpGame->draw(*this->forceT);

        this->angleT->setString(to_string(this->angle));
        this->bpGame->draw(*this->angleT);

        winner->setString(winnerStr);
        this->bpGame->draw(*winner);

        if (calculating && this->board->turnPlayers && !this->launching){
            //cout << "Error here" << endl;
            this->listPathPlayer = NULL;
            json = jsonSender("startPathF", this->puck->getPosition().x+25,this->puck->getPosition().y+25);
            this->listPathPlayer = this->board->getPathPlayer(this->puck->getPosition().y+25, this->puck->getPosition().x+25);
            this->board->puck->setUpLaunch();
            calculating = false;
        }
        if (!this->launching && this->board->turnPlayers){
            cout << "length" <<  listPathPlayer->length << endl;
            if (this->listPathPlayer->length > 0) {
                Sprite *dirB[this->listPathPlayer->length];
                for (int x = 0; x < (this->listPathPlayer->length) - 1; x++) {
                    dirB[x] = new Sprite;
                    dirB[x]->setTexture(*direct);
                    for (int i = 0; i < 9; i++) {
                        for (int j = 0; j < 9; j++) {
                            if (this->listPathPlayer->getValueAt(x) == this->board->matrix_names[i][j]) {
                                dirB[x]->setPosition(j * grid_x + 10, i * grid_y);
                                this->bpGame->draw(*dirB[x]);
                            }
                        }
                    }
                }
                RectangleShape line(sf::Vector2f(7*this->force, 10));
                line.rotate(this->angle + 180);
                line.setFillColor(Color::Black);
                line.setPosition(this->puck->getPosition().x + 25, this->puck->getPosition().y + 25);
                this->bpGame->draw(line);
            }

        }else if (!this->launching && !this->board->turnPlayers){
            if (this->step == 1){
            //    cout << "step 1" << endl;
                if (first_in){
                    this->listComputerPath = NULL;
                    this->listComputerPath = this->board->getPathComputer(this->puck->getPosition().y+25, this->puck->getPosition().x+25);
                    json = jsonSender("startBackT", this->puck->getPosition().x+25, this->puck->getPosition().y+25);
                    this->listComputerPath->printList();
                    cout<<"****************************************************************"<<endl;
                    cout<<this->listComputerPath->getListString()<<endl;

                    int i = this->puck->getPosition().y/grid_y;
                    int j = this->puck->getPosition().x/grid_x;
                    this->board->puck->setUpLaunch();
                    if (this->board->matrix_names[i][j] != this->listComputerPath->getValueAt(this->listComputerPath->length-1)){
                        this->searchAngleStart(this->board->matrix_names[i][j], this->listComputerPath->getValueAt(this->listComputerPath->length-1));
                    }else{
                        this->searchAngleStart(this->board->matrix_names[i][j], this->listComputerPath->getValueAt(this->listComputerPath->length-2));
                    }
                    this->force = 8;
                    first_in = false;
                }

            }else if (this->step == 2){
//                cout << "step 2" << endl;
//                cout << "comp path len" << this->listComputerPath->length << endl;
                Sprite * dirB[this->listComputerPath->length];
             //   cout << "sprites created" << endl;
                for (int x=0; x<(this->listComputerPath->length); x++){
                    dirB[x] = new Sprite;
                    dirB[x]->setTexture(*direct2);
                    for (int i=0; i<9; i++){
                        for (int j=0; j<9; j++){
                            if (this->listComputerPath->getValueAt(x) == this->board->matrix_names[i][j]){
                                dirB[x]->setPosition(j*grid_x+10, i*grid_y);
                                this->bpGame->draw(*dirB[x]);
                            }
                        }
                    }
                }
                RectangleShape line(sf::Vector2f(7*this->force, 10));
                line.rotate(this->angle+180);
                line.setFillColor(Color::Black);
                line.setPosition(this->puck->getPosition().x+25, this->puck->getPosition().y+25);
                this->bpGame->draw(line);

            }else if (this->step == 3){
                this->launching = true;
            }
        }

        if (this->force > 0 && this->launching) {
            cout << "Here" << endl;
            if (this->board->puck->performLaunch(this->force, this->angle, this->puck->getPosition().x, this->puck->getPosition().y, this->puck)){
                this->puck->setPosition(385.f, 290.f);
                if (this->board->scores->getMatchFinishedP1()){
                    winnerStr = "You won";
                }else if (this->board->scores->getMatchFinishedP2()){
                    winnerStr = "Computer won";
                }
            }
            this->force--;

        }else if (this->launching && this->force <= 0){
            this->launching = false;
            this->board->turnPlayers = !this->board->turnPlayers;
            if (this->board->turnPlayers){
                this->angle = 40;
                this->force = 11;
                calculating = true;
            }else{
                this->step = 1;
                first_in = true;
            }
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

void BoardDisplay::searchAngleStart(int current_pos, int first_on_path) {
    int i1 = 0;
    int j1 = 0;
    int i2 = 0;
    int j2 = 0;
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if (this->board->matrix_names[i][j] == current_pos){
                i1 = i;
                j1 = j;
            }else if (this->board->matrix_names[i][j] == first_on_path){
                i2 = i;
                j2 = j;
            }
        }
    }
    cout << "current, next" << this->board->matrix_names[i1][j1] << "," << this->board->matrix_names[i2][j2] << endl;

    if (j1 == j2){
        if (i1 > i2){
            this->angle = 90;
        }else{
            this->angle = 270;
        }
    }else if (i1 == i2){
        if (j1 > j2){
            this->angle = 0;
        }else{
            this->angle = 180;
        }
    }else{
        if (j2<j1 && i2<i1){
            this->angle = 50;
        }else if (j2<j1 && i2>i1){
            this->angle = 320;
        }else if (j2>j1 && i2<i1){
            this->angle = 140;
        }else if (j2>j1 && i2>i1){
            this->angle = 220;
        }
    }



}