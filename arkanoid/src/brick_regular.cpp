#include "brick_regular.hpp"
#include "global_standarts.hpp"

namespace shapes {

RegularBrick::RegularBrick(sf::Color a_brick_color, sf::Vector2f a_location) noexcept
: Brick(shapes::regular_brick_score,true,a_location,a_brick_color)
{
    setOutlineThickness(shapes::brick_outline_size);
    setOutlineColor(shapes::brick_outline_color);
}

RegularBrick::RegularBrick() noexcept
: Brick(shapes::regular_brick_score,true,shapes::default_brick_location,sf::Color::Blue)
{
}

} // namespace shapes
