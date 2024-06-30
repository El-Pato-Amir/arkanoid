#ifndef LEVEL_LAYOUT_HPP
#define LEVEL_LAYOUT_HPP

#include "brick_container.hpp"
#include "file_manager.hpp"

#include "layout_formatting.hpp"

#include <vector> // vector

namespace arkanoid {

class LevelLayout {
public:
    explicit LevelLayout(int a_level_num);
    ~LevelLayout() = default;

    shapes::BrickContainer create_level() noexcept;

    //void load_level();

//TODO: put the file manager somewhere else
private:
    int m_level_num;
    int m_num_of_bricks;
    FileManager m_file;
    std::vector<Color> m_colors;
    std::vector<sf::Vector2f> m_bricks_location;
};

} // namespace arkanoids

#endif // LEVEL_LAYOUT_HPP