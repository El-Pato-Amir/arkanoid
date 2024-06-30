#include "brick_resilient.hpp"

namespace shapes {

ResilientBrick::ResilientBrick(sf::Vector2f a_location, int a_pops, arkanoid::Color a_color)
: Brick{a_color,a_location,0}
, m_pops{a_pops}
{
}

bool ResilientBrick::is_popable() noexcept
{
    return --m_pops == 0;
}

} // namespace shapes
