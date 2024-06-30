#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include "sound_manager.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics.hpp>

namespace arkanoid {

class EventHandler {
public:
    explicit EventHandler (SoundManager& a_sound) noexcept;
    ~EventHandler() = default;

    bool handle_game_screen(sf::RenderWindow& a_window,sf::Event const& a_event,bool & a_run);

    bool handle_event(sf::Event const& a_event, sf::Vector2f &a_movement, bool& a_launch_flag, bool& a_level_up);

    void handle_player_name(sf::Event const& a_event, sf::String& a_name,bool& a_stop);

private:
    SoundManager& m_sound;
};

} //namespace arkanoid

#endif // EVENT_HANDLER_HPP