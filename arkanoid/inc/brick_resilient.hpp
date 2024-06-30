#ifndef RESILIENT_BRICK_HPP
#define RESILIENT_BRICK_HPP

#include "brick.hpp"

namespace shapes {

class ResilientBrick : public Brick {
public:
    explicit ResilientBrick(sf::Vector2f a_location, int a_pops = 3, arkanoid::Color a_color = arkanoid::Color::resilient);

    bool is_popable() noexcept override;
    
private:
    int m_pops;
};

} // namespace shapes


#endif // RESILIENT_BRICK_HPP