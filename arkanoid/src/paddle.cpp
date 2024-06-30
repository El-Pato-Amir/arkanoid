#include "paddle.hpp"
#include "global_standarts.hpp"

namespace shapes {

Paddle::Paddle(sf::Vector2f a_position) noexcept
: RectangleShape(sf::Vector2f(shapes::paddle_width,shapes::paddle_height))
, m_direction()
{
    setPosition(a_position);
    setFillColor(shapes::paddle_color);
    setOutlineColor(shapes::paddle_outline);
    setOutlineThickness(shapes::paddle_outline_size);
}


void Paddle::update_movement(sf::Vector2f a_direction) noexcept
{
    m_direction = a_direction;    
}

void Paddle::move_paddle() noexcept
{
    move(m_direction);
}

sf::Vector2f Paddle::current_speed() const noexcept
{
    return m_direction;
}


} // namepsace shapes
