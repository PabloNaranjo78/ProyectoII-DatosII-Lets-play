

#ifndef PROYECTO2_CUTTER_H
#define PROYECTO2_CUTTER_H
#include <iostream>

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Cutter {

public:
    Vector2u divs;

    Vector2u getdivision(int div, int max);

};


#endif //PROYECTO2_CUTTER_H
