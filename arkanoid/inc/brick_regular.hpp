#ifndef BRICK_REGULAR_HPP
#define BRICK_REGULAR_HPP

#include "brick.hpp"
#include "global_standarts.hpp"

namespace shapes {

//TODO: make default ctor
class RegularBrick : public Brick {
public:
    RegularBrick(sf::Color a_brick_color, sf::Vector2f a_location) noexcept;
    RegularBrick() noexcept;

};

} // namespace shapes

#endif // BRICK_REGULAR_HPP