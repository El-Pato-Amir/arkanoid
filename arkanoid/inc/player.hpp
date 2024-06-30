#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "paddle.hpp"

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

namespace arkanoid {

enum class PowerUp {

    Life,
    Time,
    Width,

};

class Player {
public:    
    Player(shapes::Paddle const& a_paddle);
    ~Player() = default;

    void draw_paddle(sf::RenderWindow& a_window) const noexcept;
    shapes::Paddle paddle() const noexcept;
    void update_paddle(sf::Vector2f a_movement) noexcept;
    void move_paddle() noexcept;

    int lives() const noexcept;
    //will return false when no lives are left
    bool lose_life() noexcept;

    void power_up(PowerUp a_power) noexcept;
    bool is_dilation() const noexcept;
    sf::Time since_dilation() const noexcept;

private:
    shapes::Paddle m_paddle;
    sf::Clock m_time_out;
    int m_lives;
    bool m_time;
    
};

} // namespace arkanoid

#endif // PLAYER_HPP