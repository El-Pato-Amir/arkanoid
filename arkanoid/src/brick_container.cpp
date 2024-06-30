#include "brick_container.hpp"
#include "brick_explosive.hpp"
#include "physics.hpp"

namespace shapes {

BrickContainer::BrickContainer() noexcept
: m_active_bricks{}
{
}

BrickContainer::BrickContainer(BrickContainer&& a_container)
: m_bricks{std::move(a_container.m_bricks)}
, m_active_bricks(a_container.m_active_bricks)
{
}

BrickContainer& BrickContainer::add_brick(std::unique_ptr<Brick>&& a_brick)
{
    if (a_brick->type() != arkanoid::Color::gold) {
        ++m_active_bricks;
    }
    m_bricks.emplace_back(std::move(a_brick));
    return *this;
}

size_t BrickContainer::special_bricks(std::unique_ptr<Brick>& a_brick,arkanoid::Player& a_player)
{
    switch (a_brick->type()) {
        case arkanoid::Color::explosive:
            return explosive_brick(a_brick, a_player);
        
        case arkanoid::Color::life:
            a_player.power_up(arkanoid::PowerUp::Life);
            return 50;

        case arkanoid::Color::width:
            a_player.power_up(arkanoid::PowerUp::Width);
            return 50;            

        case arkanoid::Color::time:
            a_player.power_up(arkanoid::PowerUp::Time);
            return 50;                        
        default:
            return 0;
    }
}

//TODO: break into functions
size_t BrickContainer::explosive_brick(std::unique_ptr<Brick>& a_brick, arkanoid::Player& a_player)
{
    size_t score = 0;
    auto brick = dynamic_cast<ExplosiveBrick*>(a_brick.get());
    std::list<sf::FloatRect> explosions;
    explosions.push_back(physics::calculate_explosion(brick->explosion_radius(),a_brick->getPosition()));
    m_bricks.remove(a_brick);
    auto begin = m_bricks.begin();
    auto end = m_bricks.end();
    auto exp_begin = explosions.begin();
    auto exp_end = explosions.end();
    while (exp_begin != exp_end) {
        while (begin != end) {
            if (exp_begin->intersects(begin->get()->getGlobalBounds()) && begin->get()->is_popable()) {
                score += begin->get()-> score();
                auto temp = begin++;
                if (temp->get()->type() == arkanoid::Color::explosive) {
                    auto ex_brick = dynamic_cast<ExplosiveBrick*>(temp->get());
                    explosions.push_back(physics::calculate_explosion(ex_brick->explosion_radius(),ex_brick->getPosition()));
                } else if (brick->type() < arkanoid::Color::gold) {
                    special_bricks(*temp,a_player);
                }
                m_bricks.remove(*temp);
                --m_active_bricks;
                continue;
            }
            ++begin;
        }
        begin = m_bricks.begin();
        ++exp_begin;
    }
    return score;
}

//TODO: return an optional brick
size_t BrickContainer::check_collision(Ball& a_ball, arkanoid::SoundManager& a_sounds,arkanoid::Player& a_player)
{
    size_t score = 0;
    for (auto& brick : m_bricks) {
        if (brick->getGlobalBounds().intersects(a_ball.getGlobalBounds())) {
            physics::calculate_collision(a_ball,brick->getGlobalBounds());
            if (brick->is_popable()) {
                if (brick->type() < arkanoid::Color::gold) {
                    score = special_bricks(brick,a_player);
                } else {
                    score = brick->score();
                }
                --m_active_bricks;
                m_bricks.remove(brick);
                a_sounds.play_sound(arkanoid::Sounds::Reg_brick);
            } else {
                a_sounds.play_sound(arkanoid::Sounds::Gold_brick);
            }
            return score;
        }
    }
    return 0;
}

void BrickContainer::draw_container(sf::RenderWindow& a_window) const noexcept
{
    for (auto& brick : m_bricks) {
        a_window.draw(*brick);
    }
}

bool BrickContainer::is_empty() const noexcept
{
    return m_active_bricks == 0;
}

} //namespace shapes
