#ifndef BRICK_EXPLOSIVE_HPP
#define BRICK_EXPLOSIVE_HPP

#include "brick_resilient.hpp"

namespace shapes {

class ExplosiveBrick : public ResilientBrick {
public:
    explicit ExplosiveBrick(sf::Vector2f a_location, int a_pops,float a_radius);

    float explosion_radius() const noexcept;

private:
    float m_radius;
};

} // namespace shapes

#endif // BRICK_EXPLOSIVE_HPP