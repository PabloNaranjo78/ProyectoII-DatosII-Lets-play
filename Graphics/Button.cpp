#include "Button.h"

Button::Button(float x, float y, float width, float height, Font *font, string text, Color idleColor, Color hoverColor,
               Color activeColor) {
    this->buttonstate = BTN_IDLE;

    this->shape.setPosition(Vector2f(x,y));
    this->shape.setSize(Vector2f(width,height));

    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(Color::White);
    this->text.setCharacterSize(12);
    this->text.setPosition(this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width/2.f,
                           this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height/2.f);

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->shape.setFillColor(this->idleColor);
}

//Accesors
const bool Button::get_pressed() const {
   if(this->buttonstate== BTN_ACTIVE){
       return true;
   }
   return false;
}

//functions

void Button::update(const Vector2f mousepos) {

    this->buttonstate = BTN_IDLE;
    //hover

    if(this->shape.getGlobalBounds().contains(mousepos)){
        cout<<"HOVER"<<endl;
        this->buttonstate = BTN_HOVER;

        //pressed
        if(Mouse::isButtonPressed(Mouse::Left)){
            this->buttonstate = BTN_ACTIVE;

        }
    }

    switch (this->buttonstate) {
        case BTN_IDLE:
            this->shape.setFillColor(this->idleColor);
            break;
        case BTN_HOVER:
            this->shape.setFillColor(this->hoverColor);
            break;
        case BTN_ACTIVE:
            this->shape.setFillColor(this->activeColor);
            break;
        default:
            this->shape.setFillColor(Color::Red);
            break;
    }

}

void Button::render(RenderTarget *target) {
    target->draw(this->shape);
    target->draw(this->text);
}