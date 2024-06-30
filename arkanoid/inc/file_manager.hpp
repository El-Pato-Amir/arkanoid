#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include "player_info.hpp"
#include "layout_formatting.hpp" // enum colors

#include <iostream> // filestream
#include <fstream> // fstream
#include <vector> // vector
#include <SFML/Graphics.hpp> // sf::vector2f

namespace arkanoid {

//TODO: read and create level from json

class FileManager {
public:
    FileManager(std::string const& a_file_name);
    ~FileManager();

    void save_score_board(std::vector<PlayerInfo>& a_score_board);

    std::vector<PlayerInfo> load_score_board();

    bool save_layout(std::vector<sf::Vector2f>& a_locations,std::vector<Color>& a_colors,int a_bricks_num);

    bool load_from_layout(std::vector<sf::Vector2f>& a_locations,std::vector<Color>& a_colors);

private:
    std::string m_name;
    
};

} // namespace arkanoid

#endif // FILE_MANAGER_HPP