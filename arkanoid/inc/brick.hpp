#ifndef BRICK_HPP
#define BRICK_HPP

#include "layout_formatting.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

namespace shapes {
class Brick : public sf::RectangleShape {
public:    
    explicit Brick(arkanoid::Color a_color, sf::Vector2f a_location,int a_level_number);
    //for shape manager check
    Brick();

    ~Brick() = default;

    size_t score() const noexcept;

    arkanoid::Color type() const noexcept;

    virtual bool is_popable() noexcept;

private:
    arkanoid::Color m_color;
    size_t m_score;
    bool m_popable;
};

bool operator==(Brick const& a_left,Brick const& a_right) noexcept;

}// namespace shapes

#endif // BRICK_HPP