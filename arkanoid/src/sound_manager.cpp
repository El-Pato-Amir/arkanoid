#include "sound_manager.hpp"

#include <exception>
#include <stdexcept>


namespace arkanoid {

SoundManager::SoundManager()
: m_mute(false)
{
    //TODO: check for open
    m_sounds[Sounds::Reg_brick].loadFromFile("sounds/reg_brick_sound.ogg");
    m_sounds[Sounds::Gold_brick].loadFromFile("sounds/gold_brick_sound.wav");
    m_sounds[Sounds::Paddle].loadFromFile("sounds/paddle_sound.wav");
    m_sounds[Sounds::Wall].loadFromFile("sounds/wall_sound.ogg");
    m_sounds[Sounds::Fall].loadFromFile("sounds/fall_sound.wav");
    if (not m_sounds[Sounds::Button].loadFromFile("sounds/button_sound.wav")) {
        throw std::runtime_error("unable to load font");
    }
    m_sounds[Sounds::Level_up].loadFromFile("sounds/win_sound.wav");
    m_play.setVolume(50);
}

SoundManager::~SoundManager()
{
    m_music.stop();
}

void SoundManager::play_background_music(int a_num_of_level)
{
    int level_num = a_num_of_level % 3;
    if (level_num == 0) {
        level_num = 3;
    }
    std::string file_name{"sounds/level_" + std::to_string(level_num) + ".ogg"};
    if (m_music.openFromFile(file_name)) {
        m_music.setVolume(25);
        if (not m_mute) {
            m_music.play();
        }
    }

}

void SoundManager::close_background_music() noexcept
{
    m_music.stop();
}

void SoundManager::mute_button() noexcept 
{
    if (m_mute) {
        m_music.play();
        m_mute = false;

    } else {
        m_music.pause();
        m_mute = true;
    }
}

void SoundManager::play_sound(Sounds a_sound)
{
    if (m_mute) {
        return;
    }
    m_play.setBuffer(m_sounds.at(a_sound));
    m_play.play();
}

} // namespace arkanoid
