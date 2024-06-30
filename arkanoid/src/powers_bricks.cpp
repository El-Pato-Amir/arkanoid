#include "powers_bricks.hpp"
#include "global_standarts.hpp"

namespace arkanoid {

BricksPowers::BricksPowers(sf::Vector2f a_location)
{
    setPosition(a_location);
    setRadius(shapes::powers_radius);
}


void BricksPowers::draw_this(sf::RenderWindow& a_window)
{
    draw(a_window);
    move(sf::Vector2f{0,-shapes::powers_speed});
}

} //  namespace arkanoid
