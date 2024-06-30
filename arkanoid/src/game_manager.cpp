#include "game_manager.hpp"
#include "global_standarts.hpp"


#include <thread> //sleep
#include <chrono> // sleep duration
#include <iostream> // cin
#include <algorithm> // find if

namespace arkanoid {

namespace {

//TODO: button class to check for pressing on keys


bool is_appliable(size_t a_score ,sf::Time a_time, std::vector<PlayerInfo>& a_score_board)
{
    auto reinterperted_time = static_cast<uint64_t>(a_time.asMilliseconds());
    auto compare = [a_score,reinterperted_time](PlayerInfo const& a_player) {
        if (a_player.m_score != a_score) {
            return a_player.m_score < a_score;
        }
        return a_player.m_time > reinterperted_time;
    };
    auto it = std::find_if(a_score_board.begin(),a_score_board.end(),compare);
    if (it != a_score_board.end()) {
        return true;
    }
    return false;
        
}

} // namespace

GameManager::GameManager(int a_num_of_levels)
: m_levels{a_num_of_levels}
, m_file{shapes::score_file_name}
, m_graphics{shapes::background_color}
, m_sounds{}
, m_curr_score{}
, m_window{sf::VideoMode(shapes::window_width, shapes::window_height), "Arkanoid"}
, m_score_board{m_file.load_score_board()}
{
    m_window.setFramerateLimit(shapes::frame_limit);
}

GameManager::~GameManager() noexcept
{
    m_window.close();
    m_file.save_score_board(m_score_board);
}

//TODO: break into functions
void GameManager::game_screen()
{
    bool run = true;
    bool game = false;
    arkanoid::EventHandler handler{m_sounds};
    while (run) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            game = handler.handle_game_screen(m_window,event,run);
        }
        if (game) {
            m_curr_score = 0;
            int curr_level = 1;
            sf::Clock timer;
            bool escape = false;
            while (curr_level <= m_levels.num_of_levels()) {
                m_sounds.play_background_music(curr_level);
                auto level = m_levels.load_level(curr_level,m_sounds,m_curr_score);
                if (run_game(level,escape) == true) {
                    m_sounds.play_sound(Sounds::Level_up);
                    ++curr_level;
                } else {
                    break;
                }
            }
            m_sounds.close_background_music();
            if (not escape) {
                score_board(timer.getElapsedTime());
            }
            game = false;
        }
        m_graphics.draw_start_screen(m_window);
    }
}

void GameManager::score_board(sf::Time a_time)
{    
    if (is_appliable(m_curr_score,a_time,m_score_board)) {
        std::string player_name = m_graphics.player_name_prompt(m_window,m_sounds);
        uint64_t time = static_cast<uint64_t>(a_time.asMilliseconds());
        m_score_board.at(0) = PlayerInfo{player_name,time,m_curr_score};
        std::sort(m_score_board.begin(),m_score_board.end());
    }        
    bool draw = true;
    while(draw) {
        m_graphics.draw_score_board(m_window,m_score_board);
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                draw = false;
            }
        }
    }
}

bool GameManager::run_game(Level& a_level,bool& a_escape)
{
    bool check = a_level.run_level(m_window,m_graphics);
    if (check) {
        // m_graphics.draw_endgame(m_window,"You Win!",sf::Color::Black,m_curr_score);
        // sf::sleep(sf::Time(sf::seconds(10)));
        return true;
    }
    if (not check && a_level.lives() == 0) {
        m_graphics.draw_endgame(m_window,"Game Over",sf::Color::Red,m_curr_score);
        sf::sleep(sf::Time(sf::seconds(5)));
        sf::Event event;
        while (m_window.pollEvent(event))
        {
        }
        return false;
    }
    a_escape = true;
    return false;
}




} // namespace arkanoid
