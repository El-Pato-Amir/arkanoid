#ifndef BRICK_CONTAINER_HPP
#define BRICK_CONTAINER_HPP

#include "sound_manager.hpp"
#include "ball.hpp"
#include "brick.hpp"
#include "player.hpp"


//TODO: make way to save different kind of bricks without shooting yourself in the leg!!
//TODO: think about how to make the collision check inside the brick
#include <list> // list
#include <functional> // hash
#include <cstddef> // size_t
#include <memory> // unique pointer
#include <SFML/Graphics.hpp> // window class

namespace shapes {

class BrickContainer {
public:
    //TODO: after implementing some sort of level layout class
    // make a ctor that recieves layout and creates the container
    BrickContainer() noexcept;
    ~BrickContainer() = default;

    BrickContainer(BrickContainer&& a_container);

    BrickContainer& add_brick(std::unique_ptr<Brick>&& a_brick);

    size_t check_collision(Ball& a_ball, arkanoid::SoundManager& a_sounds,arkanoid::Player& a_player);    

    void draw_container(sf::RenderWindow& a_window) const noexcept;

    bool is_empty() const noexcept;

private:
    size_t special_bricks(std::unique_ptr<Brick>& a_brick, arkanoid::Player& a_player);
    size_t explosive_brick(std::unique_ptr<Brick>& a_brick, arkanoid::Player& a_player);

private:
    //TODO: in the future, try to implement that map stuff
    std::list<std::unique_ptr<Brick>> m_bricks;
    // number of popable bricks in container
    int m_active_bricks;

};


} // namespace shapes

#endif // BRICK_CONTAINER_HPP