
#include "Menu.h"

Menu::Menu() {
    this->keepOpen = true;
    this->width = 800;
    this->height = 600;
    this->window = new RenderWindow(VideoMode(width,height), "Let's Play!!!");

    //GUI
    this->background.setSize(Vector2f(800,600));
    this->background.setFillColor(Color(118, 154, 232,255));
    this->background.setPosition(0,0);

    //FONT
    if (!this->font.loadFromFile("../fonts/NewAmsterdam.ttf"))
        cout << "Couldn't load font" << endl;

    //TEXT
    this->title.setFont(font);
    this->title.setString("Let's Play!!!");
    this->title.setCharacterSize(80);
    this->title.setPosition(width/2-title.getGlobalBounds().width/2,50);

    this->BPbutton = new Button(width/2-150,200,300,50,&font,"BP Game",
                                Color(209, 110, 48,255),
                                Color(201, 120, 68,255),
                                Color(84, 63, 50,255),40);

    this->Gbutton = new Button(width/2-150,350,300,50,&font,"Genetic P",
                               Color(209, 110, 48,255),
                               Color(201, 120, 68,255),
                               Color(84, 63, 50,255),40);

    this->Outbutton = new Button(width/2-150,500,300,50,&font,"Salir",
                               Color(209, 110, 48,255),
                               Color(201, 120, 68,255),
                               Color(84, 63, 50,255),40);
}

void Menu::render() {

    this->window->draw(this->background);

    this->BPbutton->render(this->window);

    this->Gbutton->render(this->window);
    this->Outbutton->render(this->window);

    this->window->draw(this->title);

}

void Menu::update(Vector2f mousepos) {

    this->BPbutton->update(mousepos);
    this->Gbutton->update(mousepos);
    this->Outbutton->update(mousepos);

    if(this->BPbutton->is_pressed()){
        BoardDisplay * bpGame = new BoardDisplay();
        this->keepOpen = false;
        this->window->close();
        bpGame->runGame();

    }
    if(this->Gbutton->is_pressed()){
        GeneticDisplay* gen = new GeneticDisplay();
        this->keepOpen = false;
        this->window->close();
        gen->rungenetic();

    }
    if(Outbutton->is_pressed()){
        this->keepOpen = false;
    }

}

void Menu::run() {
    cout<<"RUN"<<endl;
    while (this->keepOpen) {

        Event event;
        while (this->window->pollEvent(event)) {
            if (event.type == Event::Closed) {
                this->window->close();
                this->keepOpen = false;

            }
            if (event.type == Event::MouseButtonPressed) {
                cout << "--------------------" << endl;
                cout << "X: " << event.mouseButton.x << " | Y: " << event.mouseButton.y << endl;
            }
        }


        this->window->clear(Color::White);
        Vector2f mousepos = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));

        update(mousepos);

        render();
        this->window->display();
    }
}