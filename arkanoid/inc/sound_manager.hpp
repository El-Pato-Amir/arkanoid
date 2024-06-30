#ifndef SOUND_MANAGER_HPP
#define SOUND_MANAGER_HPP

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include <map> // sounds map

namespace arkanoid {

enum class Sounds {

    Reg_brick,
    Gold_brick,
    Paddle,
    Wall,
    Fall,
    Button,
    Level_up

};

class SoundManager {
public:
    SoundManager();
    ~SoundManager();

    void play_background_music(int a_num_of_level);

    void close_background_music() noexcept;

    void mute_button() noexcept;

    void play_sound(Sounds a_sound);

private:
    std::map<Sounds,sf::SoundBuffer> m_sounds;
    sf::Music m_music;
    sf::Sound m_play;
    bool m_mute;
    
};

}

#endif //SOUND_MANAGER_HPP