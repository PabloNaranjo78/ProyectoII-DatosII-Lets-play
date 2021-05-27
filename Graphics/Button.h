

#ifndef PROYECTO2_BUTTON_H
#define PROYECTO2_BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
using namespace sf;
using namespace std;

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button {
private:
    short unsigned buttonstate;

    RectangleShape shape;
    Font* font;
    Text text;

    Color idleColor;
    Color hoverColor;
    Color activeColor;

public:
    Button(float x, float y, float width, float height, Font* font, string text,
           Color idleColor, Color hoverColor, Color activeColor);
    //functions
    void render(RenderTarget* target);
    void update(const Vector2f mousepos);
    const bool get_pressed()const;

};


#endif //PROYECTO2_BUTTON_H
