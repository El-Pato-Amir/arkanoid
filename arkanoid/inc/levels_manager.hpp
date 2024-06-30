#ifndef LEVELS_MANAGER_HPP
#define LEVELS_MANAGER_HPP

#include "level_layout.hpp"
#include "level.hpp"

namespace arkanoid {

class LevelsManager {
public:
    explicit LevelsManager(int a_num_of_levels);

    Level load_level(int a_level_number,SoundManager& a_sounds,size_t& a_score);

    int num_of_levels() const noexcept;

private:
    std::vector<LevelLayout> m_levels;
    int m_num_of_levels;
};

} // namespace arkanoid

#endif // LEVELS_MANAGER_HPP