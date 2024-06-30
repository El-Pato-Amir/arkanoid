#include "shape_manager.hpp"
#include "global_standarts.hpp"
#include "physics.hpp"

namespace shapes {

ShapeManager::ShapeManager(BrickContainer && a_container, sf::Vector2f a_paddle_position, sf::Vector2f a_ball_position) noexcept
: m_container{std::move(a_container)}
, m_player{shapes::Paddle{a_paddle_position}}
, m_ball{a_ball_position}
, m_is_launched(false)  
{
}

void ShapeManager::draw_all_shapes(sf::RenderWindow& a_window) const noexcept
{
    m_container.draw_container(a_window);
    m_player.draw_paddle(a_window);
    a_window.draw(m_ball);
}

void ShapeManager::update_player(sf::Vector2f a_movement) noexcept
{
    m_player.update_paddle(a_movement);
}

//TODO: break into functions
void ShapeManager::move_shapes() noexcept
{
    if (m_player.is_dilation()) {
        if (m_player.since_dilation() <= shapes::time_dilation_time_out) {
            sf::Vector2f ball_movement = m_ball.curr_movement();
            ball_movement.x /= time_dilation_factor;
            ball_movement.y /= time_dilation_factor;
            m_ball.move(ball_movement);
        } else {
            m_player.power_up(arkanoid::PowerUp::Time);
        }
    } else {
        m_ball.move_ball();
    }
    auto paddle = m_player.paddle();
    auto paddle_bounds = paddle.getGlobalBounds();
    auto paddle_speed = paddle.current_speed();
    if (paddle_speed.x < 0 && paddle_bounds.left <= 0) {
        return;
    }
    if (paddle_speed.x > 0 && paddle_bounds.left + paddle_bounds.width >= shapes::window_width) {
        return;
    }
    m_player.move_paddle();
    if (not m_is_launched) {
        m_ball.setPosition(sf::Vector2f{m_player.paddle().getPosition().x + paddle_width / 2 - ball_radius, paddle_start_location.y - ball_radius*2 - ball_outline_size - 1});
    }
}

bool ShapeManager::update_shapes(size_t & a_score, arkanoid::SoundManager& a_sounds)
{
    if (not m_is_launched) {
        return true;
    }
    a_score += m_container.check_collision(m_ball, a_sounds,m_player);
    auto ball_position = m_ball.getGlobalBounds();
    if (m_player.paddle().getGlobalBounds().intersects(ball_position)) {
        a_sounds.play_sound(arkanoid::Sounds::Paddle);
        physics::calculate_collision(m_ball,m_player.paddle());
        return true;
    }
    if (ball_position.top + ball_position.height >= window_height) {
        a_sounds.play_sound(arkanoid::Sounds::Fall);
        reset_shapes(ball_start_location, paddle_start_location);
        return m_player.lose_life();
    }
    if(physics::is_in_bounds(m_ball)) {
        a_sounds.play_sound(arkanoid::Sounds::Wall);
    }
    return true;
}

void ShapeManager::reset_shapes(sf::Vector2f a_ball_location, sf::Vector2f a_paddle_location)
{
    m_ball.setPosition(a_ball_location);
    m_ball.update_movement(sf::Vector2f(0,0));
    m_player.paddle().setPosition(a_paddle_location);
    m_player.update_paddle(sf::Vector2f(0,0));
    m_is_launched = false;
}

void ShapeManager::launch_ball() noexcept
{
    if (m_is_launched) {
        return;
    }
    physics::launch_ball(m_ball);
    m_is_launched = true;
}

bool ShapeManager::is_launched() const noexcept
{
    return m_is_launched;
}

bool ShapeManager::is_finished() const noexcept
{
    return m_container.is_empty();
}

int ShapeManager::lives() const noexcept
{
    return m_player.lives();
}

} //namespace shapes
