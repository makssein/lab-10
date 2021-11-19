#include "classes.hpp"

namespace myClasses{
    Rectangle::Rectangle(int x, int y, int w, int h, float velocity){
        m_x = x;
        m_y = y;
        m_w = w;
        m_h = h;
        m_velocity = velocity;
        m_rectangle = new sf::RectangleShape(sf::Vector2f(m_w, m_h));
        m_rectangle->setOrigin(m_w/2, 0);
        m_rectangle->setFillColor(sf::Color::Green);
        m_rectangle->setPosition(m_x, m_y);
    }
    Rectangle::~Rectangle(){
        delete m_rectangle;
    }

    sf::RectangleShape* Rectangle::Get() { return m_rectangle; }

    void Rectangle::Move(){
        m_x += m_velocity;
        m_rectangle->setPosition(m_x, m_y);
    }

    int Rectangle::GetX() { return m_x; }

    void Rectangle::Stop(){
        m_rectangle->setPosition(1920,m_y);
    }
}
