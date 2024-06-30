#include "file_manager.hpp"
#include "global_standarts.hpp"

#include <cstring> //memcpy
#include <cstdint> //int types
#include <cassert> // for check
#include <filesystem> // file_size
#include <exception> // exception

 

namespace arkanoid {

namespace {

void format_name(std::string& a_name, char* a_dest)
{       
    a_name.resize(32);
    ::memcpy(a_dest,a_name.c_str(),32);
}

void delete_unnecessary_nulls(std::string& a_string) 
{
    size_t index = a_string.find_first_of('\0');
    a_string = a_string.substr(0,index);
}

void format_names(char * a_buffer, std::string a_names[])
{
    for (size_t i = 0; i < 10; ++i) {
        std::string new_name{};
        for (size_t j = 0; j < 32; ++j) {
            new_name.push_back(a_buffer[i*32 + j]);
        }
        delete_unnecessary_nulls(new_name);
        a_names[i] = new_name;
        new_name.clear();
    }
}

} //namespace


FileManager::FileManager(std::string const& a_file_name)
: m_name(a_file_name)
{
}

FileManager::~FileManager()
{
}

void FileManager::save_score_board(std::vector<PlayerInfo>& a_score_board)
{
    char names[10][32];
    uint32_t scores[10];
    uint64_t times[10];
    for (size_t i = 0; i < 10; ++i) {
        format_name(a_score_board.at(i).m_name,names[i]);
        uint32_t score = static_cast<uint32_t>(a_score_board.at(i).m_score);
        scores[i] = score;
        uint64_t time = a_score_board.at(i).m_time;
        times[i] = time;        
    }
    std::ofstream file{m_name,std::ios::binary | std::ios::trunc};
    if (file.is_open()) {
        file.write(reinterpret_cast<char*>(names),32*10);
        file.write(reinterpret_cast<char*>(scores),10*sizeof(uint32_t));
        file.write(reinterpret_cast<char*>(times),10*sizeof(uint64_t));
        file.close();
    }
}

std::vector<PlayerInfo> FileManager::load_score_board()
{
    std::ifstream file{m_name,std::ios::binary};
    if (file.peek() == file.eof()) {
        std::vector<PlayerInfo> new_score_board;
        for (size_t i = 0; i < 10; ++i) {
            new_score_board.push_back(PlayerInfo{"no player",0,0});
        }
        return new_score_board;        
    }
    std::string player_names[10];
    uint32_t scores[10];
    uint64_t times[10];
    if (file.is_open()) {
        char names[320];
        file.read(names,320);
        format_names(names,player_names);
        file.read(reinterpret_cast<char*>(scores),10*sizeof(uint32_t));
        file.read(reinterpret_cast<char*>(times),10*sizeof(uint64_t));
        //assert(file.eof());
    }
    std::vector<PlayerInfo> score_board;
    for (size_t i = 0; i < 10; ++i) {
        PlayerInfo player{player_names[i],times[i],scores[i]};
        score_board.push_back(player);
    }
    file.close();
    return score_board;
}

bool FileManager::save_layout(std::vector<sf::Vector2f>& a_locations,std::vector<Color>& a_colors,int a_bricks_num)
{
    if (a_locations.size() != a_colors.size()) {
        return false;
    }
    //max number of bricks
    if (a_locations.size() != static_cast<size_t>(a_bricks_num) || a_bricks_num > 256) {
        return false;
    }
    std::ofstream file{m_name,std::ios::binary | std::ios::trunc};
    if (file.is_open()) {
        uint64_t num_of_bricks = static_cast<uint64_t>(a_bricks_num);
        file.write(reinterpret_cast<char*>(&num_of_bricks),sizeof(u_int64_t));
        float coordinates[256*2];
        for (int i = 0; i < a_bricks_num; ++i) {
            coordinates[i] = a_locations.at(i).x;
            coordinates[i + num_of_bricks] = a_locations.at(i).y;
        }
        file.write(reinterpret_cast<char*>(coordinates),num_of_bricks*2*sizeof(float));
        arkanoid::Color colors[256];
        for (int i = 0; i < a_bricks_num; ++i) {
            colors[i] = a_colors.at(i);
        }
        file.write(reinterpret_cast<char*>(colors),num_of_bricks*sizeof(Color));
        return true;
    } else {
        return false;
    }
}


bool FileManager::load_from_layout(std::vector<sf::Vector2f>& a_locations, std::vector<Color>& a_colors)
{
    std::ifstream file{m_name,std::ios::binary};
    if (file.peek() == file.eof()) {
        return false;
    }
    float coordinates[256*2];
    Color colors[256];
    uint64_t number_of_bricks{};
    file.read(reinterpret_cast<char*>(&number_of_bricks),sizeof(uint64_t));
    file.read(reinterpret_cast<char*>(coordinates),(number_of_bricks*2)*sizeof(float));
    file.read(reinterpret_cast<char*>(colors),(number_of_bricks)*sizeof(Color));
    for (size_t i = 0; i < number_of_bricks; ++i) {
        sf::Vector2f brick_coordinate{coordinates[i],coordinates[i + number_of_bricks]};
        a_locations.push_back(brick_coordinate);
    }
    for (size_t i = 0; i < number_of_bricks; ++i) {
        Color color{colors[i]};
        a_colors.push_back(color);
    }
    file.close();
    return true;
}

} // namespace arkanoid
