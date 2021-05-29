#include "GeneticDisplay.h"




GeneticDisplay::GeneticDisplay() {
    this->keepOpen = true;
    this->width = 1200;
    this->height = 800;
    this->Gwindow = new RenderWindow(VideoMode(this->width,this->height), "Genetic Image Puzzle");
    this->Gwindow->setFramerateLimit(60);

    // Load it from a file
    if (!this->font.loadFromFile("../fonts/arial.ttf"))
        cout << "Couldn't load font" << endl;

    //UTILITY LOAD
    this->filer = new FileLoader();
    this->cutter = new Cutter();

    //VARIABLES
    this->draw_image = false;
    this->draw_puzzle = false;
    this->genindex = 0;
    this->trad['0'] = 0;
    this->trad['1'] = 1;
    this->trad['2'] = 2;
    this->trad['3'] = 3;
    this->trad['4'] = 4;
    this->trad['5'] = 5;
    this->trad['6'] = 6;
    this->trad['7'] = 7;
    this->trad['8'] = 8;
    this->trad['9'] = 9;
    this->trad['a'] = 10;
    this->trad['b'] = 11;
    this->trad['c'] = 12;
    this->trad['d'] = 13;
    this->trad['e'] = 14;
    this->trad['f'] = 15;
    this->trad['g'] = 16;
    this->trad['h'] = 17;
    this->trad['i'] = 18;
    this->trad['j'] = 19;
    this->trad['k'] = 20;
    this->trad['l'] = 21;
    this->trad['m'] = 22;
    this->trad['n'] = 23;
    this->trad['o'] = 24;

    //GUI load
    this->background.setSize(Vector2f(this->width,this->height));
    this->background.setPosition(0,0);
    this->background.setFillColor(Color(198, 204, 201,255));

    this->imagebackground.setSize(Vector2f(700,600));
    this->imagebackground.setPosition(this->width/2-700/2,50);
    this->imagebackground.setFillColor(Color(219, 219, 219,255));

    //BUTTONS
    //file button
    this->filebutton = new Button(50,300,150,50,&this->font,"Load Image",
    Color(109, 172, 199,200),
    Color(151, 171, 201,200),
    Color(99, 109, 125,200));

    //divsion button
    this->divisionbutton = new Button(50,400,150,50,&this->font,"# of Divisions",
                                      Color(109, 172, 199,200),
                                      Color(151, 171, 201,200),
                                      Color(99, 109, 125,200));
    this->divisionbutton->disabled = true;

    //start button
    this->startGbutton = new Button(50,500,150,50,&this->font,"Start Solving",
                                      Color(109, 172, 199,200),
                                      Color(151, 171, 201,200),
                                      Color(99, 109, 125,200));
    this->startGbutton->disabled = true;

    this->fowardbutton = new Button(this->width/2+250,700,150,50,&this->font,"NEXT",
                                    Color(109, 172, 199,200),
                                    Color(151, 171, 201,200),
                                    Color(99, 109, 125,200),30);
    this->fowardbutton->disabled = true;
}

void GeneticDisplay::gnome_to_image() {

    string gnome = this->fittest[this->genindex];
    if(gnome == get_target()){
        this->startGbutton->disabled = false;
        this->divisionbutton->disabled = false;
        this->filebutton->disabled = false;
    }

    int Garray[this->filer->divisions];

    for(int i = 0; i < this->filer->divisions ; i++ ){
        Garray[i] = this->trad[gnome[i]];
    }
    cout<<Garray[0]<<" | "<<Garray[1]<<endl;

    for(int u = 0; u < this->filer->divisions; u++){
        this->puzzle.at(Garray[u]).setPosition(this->positions[u].x,this->positions[u].y);
    }
}

void GeneticDisplay::cut_display_image() {
    this->puzzle.clear();
    this->positions.clear();
    //valores iniciales
    int x = 0;
    int y = 0;

    //offset
    int aux = this->width/2-(this->psize.x*0.6)/2;
    int auy = 50;

    //Cut image
    while(y < this->psize.y-5){//until y is bigger that the image height

        if(x < this->psize.x-5){//unitl x is bigger that the image width

            Sprite p1;
            p1.setTexture(this->ptexture);
            p1.setTextureRect(IntRect(x,y,divx,divy));
            p1.setScale(0.6,0.6);
            p1.setPosition(aux,auy);

            this->positions.push_back(Vector2u(aux,auy));//get all positions
            this->puzzle.push_back(p1);//get all tiles
            x+= this->divx;
            aux += (this->divx*0.6)+5;
        }
        else{
            y+= this->divy;
            auy += (this->divy*0.6)+5;
            x=0;
            aux = this->width/2-(psize.x*0.6)/2;
        }
    }
}


string GeneticDisplay::get_target() {

    string target = "0123456789abcdefghijklmno";
    while(target.size() != this->filer->divisions){
        target.pop_back();
    }
    return target;
}


/**
 * @brief jsonReviever se encarga de desempaquetar el mensaje JSON del cliente
 * @param packet paquete que envio el cliente
 * @return un documento donde se pueden extraer las variables
 */
Document jsonReceiver(Packet packet)
{
    string pet;
    Document petD;

    packet >> pet;
    cout << pet << endl;
    const char* petChar = pet.c_str();
    petD.Parse(petChar);

    return petD;
}

/**
 * @brief jsonSender se encarga de formatear los mensajes de servidor-> cliente
 * @param memory espacio de memoria alocada
 * @param value valor de la variable
 * @param variable nombre de la variable
 * @param ref cantiad de referencias
 * @return un string en formato JSON listo para enviar
 */
string jsonSender(string type, string action)
{
    string jsonStr = R"({"type":")"+ type + R"(","action":")" + action + "\"}";
    return jsonStr;
}

string jsonSenderG(string type, string action, string target)
{
    string jsonStr = R"({"type":")"+ type + R"(","action":")" + action + R"(","target":")" + target + "\"}";
    return jsonStr;
}


void GeneticDisplay::update(Vector2f mousepos,TcpSocket* socket) {
    //sockets
    Packet packetS;
    string json;

    //BUTTONS
    this->filebutton->update(mousepos);
    this->divisionbutton->update(mousepos);
    this->startGbutton->update(mousepos);
    this->fowardbutton->update(mousepos);


    //START ALGORITHM BUTTON
    if(this->startGbutton->is_pressed() && !this->startGbutton->disabled){
        this->draw_image = false;
        cut_display_image();
        cout<<"Amount of positions: "<<this->positions.size()<<endl;
        this->draw_puzzle = true;
        this->startGbutton->disabled = true;
        this->divisionbutton->disabled = true;
        this->filebutton->disabled = true;
        json = jsonSenderG("startG","start",get_target());
        packetS << json;//empaqueta el json
        socket->send(packetS);//manda el json a cliente
        packetS.clear();//vacia los packets

    }


    //DIVSION BUTTON PRESS
    if(this->divisionbutton->is_pressed() && !this->divisionbutton->disabled){
        //get amount of division from user

        this->filer->getimagedivisions();
        cout<<this->filer->divisions<<endl;

        //calculate amount of pieces
        this->cutter->getdivision(this->filer->divisions,2);
        cout<<"Divisions: "<<this->cutter->divs.x<<" | "<<this->cutter->divs.y<<endl;

        //calculate image divisions
        this->divx = this->psize.x/this->cutter->divs.x;
        this->divy = this->psize.y/this->cutter->divs.y;
        cout<<"SIZE PER PIECE: "<< this->divx<<" | "<< this->divy<<endl;
        this->startGbutton->disabled = false;

    }

    //FILE BUTTON PRESS
    if(this->filebutton->is_pressed() && !this->filebutton->disabled){
        this->draw_puzzle = false;
        this->draw_image = false;
        this->filer->load_image();
        if(this->filer->image != ""){
            this->complete.setScale(1,1);
            if(!this->ptexture.loadFromFile(this->filer->image)){
                this->filer->error();
            }
            else{
                //draw image
                this->draw_image = true;
                //set image texture
                this->complete.setTexture(this->ptexture);
                //calculate size
                this->psize.x = this->complete.getTexture()->getSize().x;
                this->psize.y = this->complete.getTexture()->getSize().y;
                cout<<"SIZE: "<< this->psize.x<<" | "<< this->psize.x<<endl;

                //scale image
                this->complete.setScale(0.6,0.6);
                //set image positions
                this->complete.setPosition(this->width/2-(psize.x*0.6)/2,50);
                //enable divisions
                this->divisionbutton->disabled = false;
            }
        }
    }
}

void GeneticDisplay::render() {
    this->Gwindow->draw(this->background);
    this->Gwindow->draw(this->imagebackground);
    this->filebutton->render(this->Gwindow);
    this->divisionbutton->render(this->Gwindow);
    this->startGbutton->render(this->Gwindow);
    this->fowardbutton->render(this->Gwindow);

    if (this->draw_image){
        this->Gwindow->draw(this->complete);
    }

    if (this->draw_puzzle){
        for(auto i = this->puzzle.begin();i!=this->puzzle.end();++i){
            this->Gwindow->draw(*i);
        }
    }
}



void GeneticDisplay::rungenetic() {

    //Se definen la variables necesarias para la comunicacion por sockets
    IpAddress ip = IpAddress::getLocalAddress();
    TcpSocket socket;
    size_t received;
    Packet packetR;

    //Se conecta el cliente al socket
    socket.connect(ip, 8080);
    socket.setBlocking(false);

    while (this->keepOpen) {

        Event event;
        while (this->Gwindow->pollEvent(event)) {
            if (event.type == Event::Closed) {
                socket.disconnect();
                Gwindow->close();
                this->keepOpen = false;

            }
            if (event.type == Event::MouseButtonPressed) {
                cout << "--------------------" << endl;
                cout << "X: " << event.mouseButton.x << " | Y: " << event.mouseButton.y << endl;
            }
        }

        socket.receive(packetR);
        if (packetR.getData() != NULL) {
            Document petition = jsonReceiver(packetR);//desempaqueta el JSON

            //separa el json en variables
            string type = petition["type"].GetString();
            string content = petition["gnome"].GetString();
            if(type == "gnome"){
                cout << content <<endl;
                this->fittest.push_back(content);
                cout << this->fittest[0]<<endl;
                gnome_to_image();
                this->genindex++;
            }
        }

        packetR.clear();
        this->Gwindow->clear(Color::White);
        Vector2f mousepos = this->Gwindow->mapPixelToCoords(Mouse::getPosition(*this->Gwindow));

        update(mousepos,&socket);
        render();
        this->Gwindow->display();
    }
}

GeneticDisplay::~GeneticDisplay() {
    delete this->filebutton;
}


