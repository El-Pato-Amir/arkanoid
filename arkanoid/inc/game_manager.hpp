#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include "levels_manager.hpp"
#include "graphics.hpp"
#include "player_info.hpp"
#include "file_manager.hpp"
#include "sound_manager.hpp"

#include <SFML/Window/Window.hpp> // window
#include <vector> // for scoreboard



//TODO: maybe use sf::String for player name instead of std::string
namespace arkanoid {

class GameManager {
public:
    explicit GameManager(int a_num_of_levels);
    ~GameManager();

    void game_screen();

private:
    Level create_level(shapes::BrickContainer& a_layout);

    bool run_game(Level& a_level,bool& a_escape);

    void score_board(sf::Time a_time);

private:
    LevelsManager m_levels;
    FileManager m_file;
    Graphics m_graphics;
    SoundManager m_sounds;
    size_t m_curr_score;
    sf::RenderWindow m_window;
    std::vector<PlayerInfo> m_score_board;
};

} // namespace arkanoid

#endif // GAME_MANAGER_HPP