#ifndef POWERS_GRAPHICS_HPP
#define POWERS_GRAPHICS_HPP

#include <SFML/Graphics/CircleShape.hpp> // circle shape
#include <SFML/Window/Window.hpp> // clock
#include <SFML/Graphics/RenderWindow.hpp> // render window

//TODO: make power ups act like in the original arkanoid

namespace arkanoid {

class PowerUps : public sf::CircleShape {
public:
    PowerUps();
    ~PowerUps() = default;

    bool draw_power(sf::RenderWindow& a_window);

    virtual void draw_this(sf::RenderWindow& a_window) = 0;

private:
    sf::Clock m_timer;
};

} // namespace arkanoid

#endif // POWERS_GRAPHICS_HPP