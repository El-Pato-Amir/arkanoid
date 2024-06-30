#include "player.hpp"
#include "global_standarts.hpp"

namespace arkanoid {

Player::Player(shapes::Paddle const& a_paddle)
: m_paddle{a_paddle}
, m_time_out{}
, m_lives{3}
, m_time{false}
{
}

int Player::lives() const noexcept
{
    return m_lives;
}

bool Player::lose_life() noexcept
{
    return --m_lives > 0;
}

void Player::draw_paddle(sf::RenderWindow& a_window) const noexcept
{
    a_window.draw(m_paddle);
}


shapes::Paddle Player::paddle() const noexcept
{
    return m_paddle;
}

void Player::update_paddle(sf::Vector2f a_movement) noexcept
{
    m_paddle.update_movement(a_movement);
}

void Player::move_paddle() noexcept
{
    m_paddle.move_paddle();
}

void Player::power_up(PowerUp a_power) noexcept
{
    sf::Vector2f size = m_paddle.getSize();
    switch (a_power) {
        case PowerUp::Life:
            ++m_lives;
            break;

        case PowerUp::Time:
            m_time_out.restart();
            m_time = !m_time;
            break;

        case PowerUp::Width:
            size.x += shapes::resize_factor;
            m_paddle.setSize(size);
            break;

        default:
            break;
    }
}

bool Player::is_dilation() const noexcept
{
    return m_time;
}

sf::Time Player::since_dilation() const noexcept
{
    return m_time_out.getElapsedTime();
}


} // namespace arkanoid
