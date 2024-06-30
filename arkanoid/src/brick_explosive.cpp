#include "brick_explosive.hpp"

namespace shapes {

ExplosiveBrick::ExplosiveBrick(sf::Vector2f a_location, int a_pops,float a_radius)
: ResilientBrick{a_location,a_pops,arkanoid::Color::explosive}
, m_radius(a_radius)
{
}

float ExplosiveBrick::explosion_radius() const noexcept
{
    return m_radius;
}

} // namespace shapes
