#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include "classes.hpp"
#include <vector>

using namespace std::chrono_literals;

int main()
{
    srand(time(0));

    sf::Texture texture;
    if (!texture.loadFromFile("../img/back.jpg"))
    {
        std::cout << "ERROR: not found back.jpg" << std::endl;
        return -1;
    }

    sf::Sprite background(texture);

    const int width = 1920;
    const int height = 1080;
    const int N = 10;

    sf::RenderWindow window(sf::VideoMode(width, height), L"Гонки прямоугольников");

    std::vector<myClasses::Rectangle*> rectangles;
    for (int i = 0; i <= height; i += height / N)
        rectangles.push_back(new myClasses::Rectangle(0, i, 150, 50, rand() % 5 + 1));

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        for (const auto& rectangle : rectangles){
            rectangle->Move();
            if (rectangle->GetX() > width){
                rectangle->Stop();
            }
        }
        window.clear();
        window.draw(background);

        for (const auto& circle : rectangles)
            window.draw(*circle->Get());

        window.display();

        std::this_thread::sleep_for(20ms);
    }

    for (const auto& rectangle : rectangles)
        delete rectangle;
    rectangles.clear();

    return 0;
}
