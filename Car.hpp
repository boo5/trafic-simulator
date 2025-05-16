#pragma once
#include <SFML/Graphics.hpp>

class Car{
    public:
        Car(float x , float y, sf::Color color, bool vertical = false);

        void update ();
        void draw(sf::RenderWindow& window);
    private:
        sf::RectangleShape shape;
        float speed;
        bool isVertical;
};

