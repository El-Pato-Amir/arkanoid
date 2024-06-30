#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "shape_manager.hpp"
#include "player_info.hpp"

#include <SFML/Window/Window.hpp> // window ref
#include <string> //string

namespace arkanoid {

class Graphics {
public:
    Graphics(sf::Color a_background);
    ~Graphics() = default;

    void draw_start_screen(sf::RenderWindow& a_window) const;

    void draw_game(sf::RenderWindow& a_window,shapes::ShapeManager const& a_shapes, size_t a_score, int a_lives) const;

    void draw_endgame(sf::RenderWindow& a_window, std::string a_message,sf::Color a__color, size_t a_score) const;

    std::string player_name_prompt(sf::RenderWindow& a_window, SoundManager& a_sounds);

    void draw_score_board(sf::RenderWindow& a_window, std::vector<PlayerInfo> const& a_score_board) const;

private:
    void draw_and_display(sf::RenderWindow& a_window, PlayerInfo const& a_player, sf::Vector2f a_location) const;

private:
    sf::Color m_background_color;
    sf::Texture m_main_screen;
    sf::Texture m_back_ground;
    sf::Font m_font;

};

} // namespace arkanoid

#endif // GRAPHICS_HPP