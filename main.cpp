#include <SFML/Graphics.hpp>
#include <vector>
#include "car.hpp"  // <-- Add this line


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Trafic Simulator");
    sf::Clock clock;
    sf::RectangleShape horizontalRoad(sf::Vector2f(800, 100));
    horizontalRoad.setFillColor(sf::Color(50,50,50));
    horizontalRoad.setPosition(0, 250);
    sf::RectangleShape verticalRoad(sf::Vector2f(100, 600));
    verticalRoad.setFillColor(sf::Color(50,50,50));
    verticalRoad.setPosition(350, 0); 

    const float dashLength = 40.f;
    const float dashThikness = 5.f;
    const float dashSpacing = 43.f;

    std::vector<sf::RectangleShape> horizontalRoadDashes;
    for(float x = 0; x < 800; x += dashLength + dashSpacing)
    {
       sf:: RectangleShape dash(sf::Vector2f(dashLength, dashThikness));
       dash.setFillColor(sf::Color::White);
       dash.setPosition(x, 295);
       horizontalRoadDashes.push_back(dash); 
    }
    std::vector<sf::RectangleShape> verticalDashes;
    for(float y = 0; y<600; y +=dashLength + dashSpacing)
    {
       sf:: RectangleShape dash(sf::Vector2f(dashThikness, dashLength));
       dash.setFillColor(sf::Color::White);
       dash.setPosition(395, y);
       verticalDashes.push_back(dash);
    }
    std::vector<Car> cars;
    cars.emplace_back(-50.f, 255.f, sf::Color::Red);    // Slightly above road center
    cars.emplace_back(-200.f, 255.f, sf::Color::Blue);  // Centered
    cars.emplace_back(-350.f, 310.f, sf::Color::Green); // Slightly below
    cars.emplace_back(370.f, -50.f, sf::Color::Yellow, true); // Vertical car
    cars.emplace_back(370.f, -200.f, sf::Color::Magenta, true); // Vertical car



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        float deltaTime  = clock.restart().asSeconds();
        for (auto& car : cars)
        {
            car.update();
        }
        

        window.clear(sf::Color::Black);
        window.draw(horizontalRoad);
        window.draw(verticalRoad);

        for (auto& dash : horizontalRoadDashes)
        {
            window.draw(dash);
        }
        for (auto& dash : verticalDashes)
        {
            window.draw(dash);
        }

        for (auto& car : cars)
        {
            car.draw(window);
        }


        window.display();
    }

    return 0;
}
