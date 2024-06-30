#include "event_handler.hpp"
#include "global_standarts.hpp"

namespace arkanoid {

EventHandler::EventHandler(SoundManager& a_sound) noexcept
: m_sound{a_sound}
{
}

bool EventHandler::handle_game_screen(sf::RenderWindow& a_window,sf::Event const& a_event,bool & a_run)
{
    switch (a_event.type) {
        case sf::Event::Closed:
            a_run = false;
            return false;


        case sf::Event::KeyPressed:
            switch (a_event.key.code) {
                case sf::Keyboard::Escape:
                return false;
            
            default:
                return false;
            }

        case sf::Event::MouseButtonPressed:
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::RectangleShape play{shapes::button};
                    sf::RectangleShape exit{play};
                    play.setPosition(shapes::play_button_position);
                    exit.setPosition(shapes::exit_button_position);
                    auto mouse_x = sf::Mouse::getPosition(a_window).x;
                    auto mouse_y = sf::Mouse::getPosition(a_window).y;
                    if (play.getGlobalBounds().contains(mouse_x,mouse_y)) {
                        m_sound.play_sound(Sounds::Button);
                        return true;
                    }
                    if (exit.getGlobalBounds().contains(mouse_x,mouse_y)) {
                        m_sound.play_sound(Sounds::Button);
                        a_run = false;
                        return false;
                    }

            }
            return false;


        default:
            return false;
    }
}

bool EventHandler::handle_event(sf::Event const& a_event, sf::Vector2f &a_movement, bool& a_launch_flag, bool& a_level_up)
{
    switch (a_event.type) {
        case sf::Event::Closed:
            return false;

        case sf::Event::KeyPressed:
            switch (a_event.key.code) {
                case sf::Keyboard::Escape:
                    return false;

                case sf::Keyboard::Space:
                    a_launch_flag = true;
                    return true;

                case sf::Keyboard::Right:
                    a_movement.x = shapes::paddle_speed;
                    return true;

                case sf::Keyboard::Left:
                    a_movement.x = shapes::paddle_speed*-1;
                    return true;
                default:
                    return true;
                }
                
                return true;
        case sf::Event::TextEntered:
            if (a_event.text.unicode == 'q' || a_event.text.unicode == 'Q') {
                m_sound.mute_button();
            } else if (a_event.text.unicode == 'l' || a_event.text.unicode == 'L') {
                a_level_up = true;
            }
            return true;

        case sf::Event::KeyReleased:
            if (a_event.key.code == sf::Keyboard::Right || a_event.key.code == sf::Keyboard::Left) {
                a_movement.x = 0;
            }
            return true;

        default:
            return true;
    }
}

void EventHandler::handle_player_name(sf::Event const& a_event, sf::String& a_name,bool& a_stop)
{
    if (a_event.type == sf::Event::TextEntered) {
        if (a_event.text.unicode == '\b') {
            if (a_name.getSize() > 0) {
                a_name.erase(a_name.getSize() - 1,1);
            }
            return;
        }
        a_name += a_event.text.unicode;
        if (a_name.getSize() >= 16) {
            a_stop = true;
            return;
        }
        return;
    }
    if (a_event.type == sf::Event::KeyPressed) {
        if (a_event.key.code == sf::Keyboard::Enter) {
            if (a_name.getSize() > 0) {
                a_stop = true;
                return;
            }
        }
        if(a_event.key.code == sf::Keyboard::BackSpace && a_name.getSize() > 0) {
            a_name.erase(a_name.getSize() - 1,1);
        }
    }
    return;
}

} // namespace arkanoid
