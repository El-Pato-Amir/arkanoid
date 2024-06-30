#include "brick.hpp"
#include "global_standarts.hpp"

namespace shapes {

Brick::Brick(arkanoid::Color a_color, sf::Vector2f a_location, int a_level_number)
: RectangleShape(sf::Vector2f(shapes::brick_width,shapes::brick_height))
, m_color(a_color) 
{
    setPosition(a_location);
    setFillColor(shapes::color_code.at(a_color));
    setOutlineThickness(shapes::brick_outline_size);
    setOutlineColor(sf::Color::Black);
    if (m_color == arkanoid::Color::grey) {
        m_score = 50*a_level_number;
    } else if (m_color < arkanoid::Color::gold) {
        m_score = 50;
    } else {
        m_score = static_cast<size_t>(m_color);
    }
    if (m_color == arkanoid::Color::gold) {
        m_popable = false;
    } else {
        m_popable = true;
    }
}

Brick::Brick()
: RectangleShape{}
, m_color(arkanoid::Color::grey)
, m_score(0)
, m_popable(false)
{
}

size_t Brick::score() const noexcept
{
    return m_score;
}

arkanoid::Color Brick::type() const noexcept
{
    return m_color;
}

bool Brick::is_popable() noexcept
{
    return m_popable;
}

bool operator==(Brick const& a_left,Brick const& a_right) noexcept
{
    return a_left.getPosition() == a_right.getPosition();
}

} // namespace shapes
