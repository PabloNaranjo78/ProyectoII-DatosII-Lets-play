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

    //GUI load
    Vector2f size(1000,730);
    this->background.setSize(size);
    this->background.setPosition(0,0);
    this->background.setFillColor(Color(198, 204, 201,255));

    this->filebotton = new Button(100,100,150,50,&this->font,"Load Image",
    Color(177, 206, 252,200),
    Color(151, 171, 201,200),
    Color(99, 109, 125,200));

}
void GeneticDisplay::update(Vector2f mousepos) {

    //BUTTONS
    this->filebotton->update(mousepos);
}

void GeneticDisplay::render() {
    this->Gwindow->draw(this->background);
    this->filebotton->render(this->Gwindow);
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
        cout<<mousepos.x<<" | "<<mousepos.y<<endl;
        update(mousepos);
        render();
        this->Gwindow->display();
    }
}

GeneticDisplay::~GeneticDisplay() {
    delete this->filebotton;
}


