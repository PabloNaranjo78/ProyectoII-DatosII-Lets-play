
#ifndef PROYECTO2_GENETICDISPLAY_H
#define PROYECTO2_GENETICDISPLAY_H
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <string>

#include "../ImageLoading/FileLoader.h"
#include "../ImageLoading/FileLoader.cpp"
#include "../ImageCutting/Cutter.h"
#include "../ImageCutting/Cutter.cpp"
#include "../AlgoritmoG/Genetic.h"
#include "../AlgoritmoG/Genetic.cpp"
#include "Button.h"
#include "Button.cpp"

using namespace std;
using namespace sf;

class GeneticDisplay {

    //window
    RenderWindow* Gwindow;
    bool keepOpen;
    int width;
    int height;

    //UTILITY
    FileLoader* filer;
    Cutter* cutter;

    //VARIABLES
    Texture ptexture;
    Sprite complete;
    vector<Sprite> puzzle;
    bool draw_image;
    bool draw_puzzle;

    //IMAGE DIVDER
    Vector2u psize;
    float divx;
    float divy;
    vector<Vector2u> positions;

    //GUI PARTS
    RectangleShape background;
    RectangleShape imagebackground;

    //BUTTONS
    Button* backbutton;
    Button* fowardbutton;
    Button* filebutton;
    Button* divisionbutton;
    Button* startGbutton;

    //FONT
    Font font;

    //GENETIC ALGORITHM
    vector<vector<string>> generations;
    vector<string> fittest;
    Genetic* genetic;

public:
    GeneticDisplay();
    virtual ~GeneticDisplay();
    void rungenetic();
    void render();
    void update(Vector2f mousepos);
    void cut_display_image();

};


#endif //PROYECTO2_GENETICDISPLAY_H
