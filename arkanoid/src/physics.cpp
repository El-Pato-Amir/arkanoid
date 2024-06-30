#include "physics.hpp"
#include "global_standarts.hpp"

#include <random>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace physics {

namespace {

bool check_corners(shapes::Ball & a_ball, sf::FloatRect a_bound) noexcept
{
    auto ball_pos = a_ball.getPosition();
    auto ball_speed = a_ball.curr_movement();
    auto ball_bounds = a_ball.getGlobalBounds();
    if (ball_bounds.contains(a_bound.top,a_bound.left)) {
        if (-ball_pos.x / ball_speed.x < ball_pos.y / ball_speed.y) {
            ball_speed.x *= -1;
            a_ball.update_movement(ball_speed);
        } else {
            ball_speed.y *= -1;
            a_ball.update_movement(ball_speed);
        }
        return true;
    }
    if (ball_bounds.contains(a_bound.top + a_bound.height,a_bound.left)) {
        if (-ball_pos.x / ball_speed.x < ball_pos.y / ball_speed.y) {
            ball_speed.x *= -1;
            a_ball.update_movement(ball_speed);
        } else {
            ball_speed.y *= -1;
            a_ball.update_movement(ball_speed);
        }
        return true;
    }
    if (ball_bounds.contains(a_bound.top ,a_bound.left + a_bound.width)) {
        if (ball_pos.x / ball_speed.x < ball_pos.y / ball_speed.y) {
            ball_speed.x *= -1;
            a_ball.update_movement(ball_speed);
        } else {
            ball_speed.y *= -1;
            a_ball.update_movement(ball_speed);
        }
        return true;
    }       
    if (ball_bounds.contains(a_bound.top + a_bound.height ,a_bound.left + a_bound.width)) {
        if (ball_pos.x / ball_speed.x < ball_pos.y / ball_speed.y) {
            ball_speed.x *= -1;
            a_ball.update_movement(ball_speed);
        } else {
            ball_speed.y *= -1;
            a_ball.update_movement(ball_speed);
        }
        return true;
    }
    return false;            
}

sf::FloatRect get_intersection(sf::FloatRect a_ball,sf::FloatRect a_bound)
{
    float left = 0;
    float top = 0;
    float height = 0;
    float width = 0;

    if (a_ball.left > a_bound.left) {
        left = a_ball.left;
        width = a_bound.left + a_bound.width - left;
    } else {
        left = a_bound.left;
        width = a_ball.left + a_ball.width - left;
    }
    if (a_ball.top > a_bound.top) {
        top = a_ball.top;
        height = a_bound.top + a_bound.height - a_ball.top;
    } else {
        top = a_bound.top;
        height = a_ball.top + a_ball.height - a_bound.top;
    }
    sf::FloatRect collision(left,top,width,height);
    return collision;
}

}

void calculate_collision(shapes::Ball& a_ball, sf::FloatRect a_bound) noexcept
{
    auto ball_bounds = a_ball.getGlobalBounds();
    auto ball_curr_movement = a_ball.curr_movement();
    if (check_corners(a_ball,a_bound)) {
        return;
    }

    sf::FloatRect collision = get_intersection(ball_bounds, a_bound);
    if (collision.height > collision.width) {
        ball_curr_movement.x *= -1;
    } else {
        ball_curr_movement.y *= -1;
    }
    a_ball.update_movement(ball_curr_movement);            

    while (a_ball.getGlobalBounds().intersects(a_bound)) {
        a_ball.move(ball_curr_movement.x / 5.0f, ball_curr_movement.y / 5.0f);
    }
}

void calculate_collision(shapes::Ball & a_ball, shapes::Paddle const& a_paddle) noexcept
{   
    calculate_collision(a_ball,a_paddle.getGlobalBounds());
    auto ball_speed = a_ball.curr_movement();
    auto paddle_speed = a_paddle.current_speed();
    ball_speed.x += paddle_speed.x / shapes::ball_speed_refactor;
    
    auto new_speed = std::sqrt((ball_speed.x*ball_speed.x) + (ball_speed.y*ball_speed.y));

    ball_speed.x = ball_speed.x * shapes::ball_initial_speed_factor/new_speed;
    ball_speed.y = ball_speed.y * shapes::ball_initial_speed_factor/new_speed;



    if (ball_speed.y > -0.001 && ball_speed.y < 0.001) {
        ball_speed.y = shapes::ball_initial_speed_factor;
    }
    a_ball.update_movement(ball_speed);
}

bool is_in_bounds(shapes::Ball & a_ball) noexcept
{
    auto ball_position = a_ball.getGlobalBounds();
    bool check = false;
    if (ball_position.left <= 0 || ball_position.left + ball_position.width >= shapes::window_width) {
        auto speed = a_ball.curr_movement();
        speed.x *= -1;
        a_ball.update_movement(speed);
        check = true;
    }
    
    if (ball_position.top <= 0) {
        auto speed = a_ball.curr_movement();
        speed.y *= -1;
        a_ball.update_movement(speed);
        check = true;
    }
    return check;
}

void launch_ball(shapes::Ball & a_ball) noexcept
{
    std::random_device new_seed;
    std::uniform_real_distribution<double> dist(60.0,120.1);
    double angle = dist(new_seed);
    double pi = 3.14159265359;
    double denom = 180.0;
    double radians = angle * (pi / denom);
    float x_value = ::cos(radians)*shapes::ball_initial_speed_factor;
    float y_value = -1*::sin(radians)*shapes::ball_initial_speed_factor;
    sf::Vector2f initial_movement(x_value,y_value);
    a_ball.update_movement(initial_movement);
}

sf::FloatRect calculate_explosion(float a_radius, sf::Vector2f a_original_position)
{
    sf::CircleShape explosion{a_radius};
    auto explosion_position = a_original_position;
    explosion_position.x -= a_radius;
    explosion_position.y -= a_radius; 
    explosion.setPosition(explosion_position);
    auto explosion_field = explosion.getGlobalBounds();
    return explosion_field;    
}

} // namespace physics
