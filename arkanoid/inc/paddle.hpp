#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics/RectangleShape.hpp>

namespace shapes{

class Paddle : public sf::RectangleShape {
public:
    explicit Paddle(sf::Vector2f a_position) noexcept;
    ~Paddle() noexcept = default;

    void update_movement(sf::Vector2f a_direction) noexcept;

    void move_paddle() noexcept;

    sf::Vector2f current_speed() const noexcept;

private:
    sf::Vector2f m_direction;  
};

} // namespace shapes

#endif // RECTANGLE_HPP