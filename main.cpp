#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include "classes.hpp"
#include <vector>

using namespace std::chrono_literals;

int main()
{
    srand(time(0));

    sf::Texture texture;
    if (!texture.loadFromFile("back.jpg"))
    {
        std::cout << "ERROR: not found back.jpg" << std::endl;
        return -1;
    }

    sf::Sprite background(texture);

    const int width = 1920;
    const int height = 1080;
    const int N = 40;

    // Создание окна с известными размерами и названием
    sf::RenderWindow window(sf::VideoMode(width, height), L"Первая программа!");

    // 1
    std::vector<mt::Circle*> circles;
    for (int i = 0; i <= width; i += width / N)
        circles.push_back(new mt::Circle(i, 0, 15, rand() % 5 + 1)); // a = rand() дает от 0 до 32767, a % 5 + 1


    // Цикл работает до тех пор, пока окно открыто
    while (window.isOpen())
    {
        // Переменная для хранения события
        sf::Event event;
        // Цикл по всем событиям
        while (window.pollEvent(event))
        {
            // Обработка событий
            // Если нажат крестик, то
            if (event.type == sf::Event::Closed)
                // окно закрывается
                window.close();
        }

        // 2 Обработка
        for (const auto& circle : circles)
        {
            circle->Move();
            if (circle->GetY() > height)
            {
                circle->SetVelocity(rand() % 5 + 1);
                circle->SetY(0);
            }
        }

        // Очистить окно от всего
        window.clear();

        // 3
        // Фон
        window.draw(background);
        // Перемещение фигуры в буфер
        for (const auto& circle : circles)
            window.draw(*circle->Get());

        // Отобразить на окне все, что есть в буфере
        window.display();

        std::this_thread::sleep_for(40ms);
    }

    for (const auto& circle : circles)
        delete circle;
    circles.clear();

    return 0;
}
