#include "Car.hpp"

Car::Car(float x , float y, sf::Color color, bool vertical)
    :speed (1.0f), isVertical(vertical)
{
    shape.setSize(sf::Vector2f(40.f, 20.f));
    if (vertical)
       shape.setSize(sf::Vector2f(20.f, 40.f));
    shape.setPosition(x, y);
    shape.setFillColor(color);
    
}
void Car::update(){
    if(isVertical)
        shape.move(0.f, speed);
    else
        shape.move(speed,0.f);
}
void Car::draw(sf::RenderWindow& window){
    window.draw(shape);
}