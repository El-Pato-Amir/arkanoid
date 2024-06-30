#ifndef BRICKS_POWERS_HPP
#define BRICKS_POWERS_HPP

#include "powers_graphics.hpp"

namespace arkanoid {

class BricksPowers : public PowerUps {
public:
    BricksPowers(sf::Vector2f a_location);
    ~BricksPowers() = default;

    void draw_this(sf::RenderWindow& a_game_window) override;
};

}

#endif // BRICKS_POWERS_HPP