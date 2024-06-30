#include "level_layout.hpp"
#include "brick_resilient.hpp"
#include "brick_explosive.hpp"
#include "global_standarts.hpp"

//TODO: change to YAML
//TODO: make explosive brick's

namespace arkanoid {

LevelLayout::LevelLayout(int a_level_num)
: m_level_num{a_level_num}
, m_file{std::string("level-" + std::to_string(a_level_num) + ".dat")}
{
    m_file.load_from_layout(m_bricks_location,m_colors);
    m_num_of_bricks = m_bricks_location.size();
}

shapes::BrickContainer LevelLayout::create_level() noexcept
{
    shapes::BrickContainer level;
    for (int i = 0; i < m_num_of_bricks; ++i) {
        switch (m_colors[i]) {
            case arkanoid::Color::resilient:
                level.add_brick(std::make_unique<shapes::ResilientBrick>(shapes::ResilientBrick(m_bricks_location.at(i),3,m_colors.at(i))));
                break;

            case arkanoid::Color::explosive:
                level.add_brick(std::make_unique<shapes::ExplosiveBrick>(shapes::ExplosiveBrick(m_bricks_location.at(i),1,shapes::brick_width)));
                break;

            default:
                level.add_brick(std::make_unique<shapes::Brick>(shapes::Brick(m_colors.at(i),m_bricks_location.at(i),m_level_num)));            
                break;
            }
    }
    return level;
}

} //namespace arkanoid
