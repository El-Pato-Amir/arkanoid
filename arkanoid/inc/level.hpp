#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "shape_manager.hpp"
#include "event_handler.hpp"
#include "graphics.hpp"
#include "sound_manager.hpp"
#include "player.hpp"

#include <SFML/Window/Window.hpp> //window

#include <cstddef> // size_t

namespace arkanoid {

class Level {
public:
    //TODO: ctor from level layout
    explicit Level(shapes::ShapeManager&& a_manager, SoundManager& a_sounds,size_t& a_score_board) noexcept;
    Level(Level&& a_level);
    ~Level() = default;

    bool run_level(sf::RenderWindow& a_game_window, Graphics const& a_graphics);

    int lives() const noexcept;
private:
    shapes::ShapeManager m_shapes;
    SoundManager& m_sounds;
    size_t& m_score;
};

} // namespace arkanoid

#endif // LEVEL_HPP