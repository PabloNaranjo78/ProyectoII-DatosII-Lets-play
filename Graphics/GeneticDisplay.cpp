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
    this->genetic = new Genetic();

    //VARIABLES
    this->draw_image = false;
    this->draw_puzzle = false;

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
}


void GeneticDisplay::cut_display_image() {
    this->puzzle.clear();
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





void GeneticDisplay::update(Vector2f mousepos) {

    //BUTTONS
    this->filebutton->update(mousepos);
    this->divisionbutton->update(mousepos);
    this->startGbutton->update(mousepos);


    //START ALGORITHM BUTTON
    if(this->startGbutton->is_pressed() && !this->startGbutton->disabled){
        this->draw_image = false;
        cut_display_image();
        cout<<"Amount of positions: "<<this->positions.size()<<endl;
        this->draw_puzzle = true;
        this->startGbutton->disabled = true;
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
    while (this->keepOpen) {

        Event event;
        while (this->Gwindow->pollEvent(event)) {
            if (event.type == Event::Closed) {
                Gwindow->close();
                this->keepOpen = false;

            }
            if (event.type == Event::MouseButtonPressed) {
                cout << "--------------------" << endl;
                cout << "X: " << event.mouseButton.x << " | Y: " << event.mouseButton.y << endl;
            }

        }

        this->Gwindow->clear(Color::White);

        Vector2f mousepos = this->Gwindow->mapPixelToCoords(Mouse::getPosition(*this->Gwindow));
        update(mousepos);
        render();
        this->Gwindow->display();
    }
}

GeneticDisplay::~GeneticDisplay() {
    delete this->filebutton;
}


