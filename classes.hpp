#pragma once
#include <SFML/Graphics.hpp>

namespace myClasses
{
    class Rectangle{
    public:
        Rectangle(int x, int y, int m_w, int m_h, float velocity);

        ~Rectangle();

        sf::RectangleShape* Get();

        void Move();

        int GetX();

        void Stop();

    private:
        int m_x, m_y, m_w, m_h;
        float m_velocity;
        sf::RectangleShape* m_rectangle;
    };

}
