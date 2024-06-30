#include "powers_graphics.hpp"
#include "global_standarts.hpp"

namespace arkanoid {

PowerUps::PowerUps()
: m_timer{}
{
}

bool PowerUps::draw_power(sf::RenderWindow& a_window)
{
    draw_this(a_window);
    return m_timer.getElapsedTime() <= shapes::powers_life_span; 
}


} // namespace arkanoid
