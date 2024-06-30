#include "levels_manager.hpp"
#include "global_standarts.hpp"

#include <exception> //exceptions

namespace arkanoid {

LevelsManager::LevelsManager(int a_num_of_levels)
: m_levels{}
, m_num_of_levels(a_num_of_levels)
{
    for (int i = 0; i < m_num_of_levels; ++i) {
        LevelLayout level(i+1);
        m_levels.push_back(level);
    }
}

Level LevelsManager::load_level(int a_level_number,SoundManager& a_sounds,size_t& a_score)
{
    if (a_level_number > m_num_of_levels || a_level_number == 0) {
        throw std::domain_error("level number out of range");
    }
    shapes::BrickContainer container = m_levels.at(a_level_number-1).create_level();
    shapes::ShapeManager manager{std::move(container),shapes::paddle_start_location,shapes::ball_start_location};
    Level level{std::move(manager),a_sounds,a_score};
    return level;
}

int LevelsManager::num_of_levels() const noexcept
{
    return m_num_of_levels;
}


} //namespace arkanoid
