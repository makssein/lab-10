#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{
    class Circle
    {
    public:
        Circle(int x, int y, float r, float velocity);

        ~Circle();

        sf::CircleShape* Get();

        void Move();

        void SetY(int y);

        int GetY();

        void SetVelocity(int velocity);

    private:
        int m_x, m_y;
        float m_r;
        float m_velocity;
        sf::CircleShape* m_shape;
    };

}
