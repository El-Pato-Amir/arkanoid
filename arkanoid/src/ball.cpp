#include "ball.hpp"
#include "global_standarts.hpp"

namespace shapes {

Ball::Ball(float a_start_position_x,float a_start_position_y) noexcept
: CircleShape(shapes::ball_radius)
, m_movement(sf::Vector2f(0,0))
{
    setPosition(a_start_position_x,a_start_position_y);
    setFillColor(shapes::ball_color);
    setOutlineColor(shapes::ball_outline_color);
    setOutlineThickness(shapes::ball_outline_size);
}

Ball::Ball(sf::Vector2f const& a_position) noexcept
: CircleShape(shapes::ball_radius)
, m_movement(sf::Vector2f(0,0))
{
    setPosition(a_position);
    setFillColor(shapes::ball_color);
    setOutlineColor(shapes::ball_outline_color);
    setOutlineThickness(shapes::ball_outline_size);
}

void Ball::update_movement(sf::Vector2f const& a_vector) noexcept
{
    m_movement = a_vector;
}

sf::Vector2f const& Ball::curr_movement() const noexcept
{
    return m_movement;
}

void Ball::move_ball() noexcept
{
    move(m_movement);
}

} // namespace shapes
