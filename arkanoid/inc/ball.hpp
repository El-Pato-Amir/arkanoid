#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics/CircleShape.hpp> // circle shape

namespace shapes {

class Ball : public sf::CircleShape {
public:
    Ball(float a_start_position_x,float a_start_position_y) noexcept;
    Ball(sf::Vector2f const& a_position) noexcept;

    void update_movement(sf::Vector2f const& a_vector) noexcept;
    sf::Vector2f const& curr_movement() const noexcept;

    void move_ball() noexcept;
    
private:
    sf::Vector2f m_movement;
};

} // namespace shapes

#endif // BALL_HPP