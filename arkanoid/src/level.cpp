#include "level.hpp"
#include "global_standarts.hpp"

#include <SFML/Window/Window.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace arkanoid {

Level::Level(shapes::ShapeManager&& a_manager, SoundManager& a_sounds,size_t& a_score_board) noexcept
: m_shapes{std::move(a_manager)}
, m_sounds{a_sounds}
, m_score{a_score_board}
{
}

//TODO: break into functions
bool Level::run_level(sf::RenderWindow& a_game_window, Graphics const& a_graphics)
{
    arkanoid::EventHandler handler{m_sounds};
    bool launch_flag = false;
    bool pause_flag = false;
    bool endgame = true;
    bool level_up = false;
    sf::Clock timer;
    while (endgame)
    {
        sf::Vector2f player_movement(0,0);
        sf::Event event;
        while (a_game_window.pollEvent(event))
        {
            if (not handler.handle_event(event,player_movement,launch_flag, level_up)) {
                return false;
            }
            m_shapes.update_player(player_movement);
            if (launch_flag && m_shapes.is_launched()) {
                launch_flag = false;
                pause_flag = !pause_flag;
            }
        }
        // idea - maybe add it to move shapes somehow
        if (not pause_flag) {
            if (timer.getElapsedTime() >= shapes::game_frame) {
                if (launch_flag) {
                    m_shapes.launch_ball();
                    launch_flag = false;
                }
                m_shapes.move_shapes();
                endgame = m_shapes.update_shapes(m_score,m_sounds);
                timer.restart();
            }
        }
        a_graphics.draw_game(a_game_window,m_shapes,m_score,m_shapes.lives());
        if (m_shapes.is_finished() || level_up) {
            return true;
        }
    }
    return false;
}

int Level::lives() const noexcept
{
    return m_shapes.lives();
}

} // namespace arkanoid
