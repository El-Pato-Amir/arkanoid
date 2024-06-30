#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "ball.hpp"
#include "brick.hpp"
#include "paddle.hpp"

#include <memory>

namespace physics {

void calculate_collision(shapes::Ball & a_ball, sf::FloatRect a_bound) noexcept;

void calculate_collision(shapes::Ball & a_ball, shapes::Paddle const& a_paddle) noexcept;

bool is_in_bounds(shapes::Ball & a_ball) noexcept;

void launch_ball(shapes::Ball & a_ball) noexcept;

sf::FloatRect calculate_explosion(float a_radius, sf::Vector2f a_original_position);

} // namespace physics

#endif // PHYSICS_HPP