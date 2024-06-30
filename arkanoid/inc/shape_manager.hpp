#ifndef SHAPE_MANAGER_HPP
#define SHAPE_MANAGER_HPP

#include "brick_container.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "sound_manager.hpp"

#include <SFML/Window/Window.hpp> //window ref

namespace shapes {

class ShapeManager {
public:

    explicit ShapeManager(BrickContainer&& a_container, sf::Vector2f a_paddle_position, sf::Vector2f a_ball_position) noexcept;

    void draw_all_shapes(sf::RenderWindow& a_window) const noexcept;

    void update_player(sf::Vector2f a_movement) noexcept;

    void move_shapes() noexcept;

    bool update_shapes(size_t & a_score, arkanoid::SoundManager& a_sounds);

    void reset_shapes(sf::Vector2f a_ball_location, sf::Vector2f a_paddle_location);
    
    void launch_ball() noexcept;

    bool is_launched() const noexcept;

    bool is_finished() const noexcept;

    int lives() const noexcept;

private:
    BrickContainer m_container;
    arkanoid::Player m_player;
    //TODO: balls container class to replace this member
    Ball m_ball;
    bool m_is_launched;
};

} // namespace shapes

#endif // SHAPE_MANAGER_HPP