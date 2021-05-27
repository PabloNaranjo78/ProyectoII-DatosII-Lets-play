
#ifndef PROYECTO2_GENETICDISPLAY_H
#define PROYECTO2_GENETICDISPLAY_H
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <string>

#include "../ImageLoading/FileLoader.h"
#include "../ImageCutting/Cutter.h"
#include "../AlgoritmoG/Genetic.h"
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
    FileLoader filer;
    Cutter cutter;


    //GUI PARTS
    RectangleShape background;

    //BUTTONS
    Button* backbotton;
    Button* fowardbotton;
    Button* filebotton;

    //FONT
    Font font;

    //GENETIC ALGORITHM
    vector<Sprite> puzzle;
    vector<string> generations;
    Genetic* genetic;

public:
    GeneticDisplay();
    virtual ~GeneticDisplay();
    void rungenetic();
    void render();
    void update(Vector2f mousepos);
};


#endif //PROYECTO2_GENETICDISPLAY_H
