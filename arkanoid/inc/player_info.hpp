#ifndef PLAYER_INFO_HPP
#define PLAYER_INFO_HPP

#include <string> // for names
#include <SFML/System/Time.hpp> // sf::Time

namespace arkanoid {

struct PlayerInfo {

    explicit PlayerInfo(std::string const& a_name, uint64_t a_time, size_t a_score) noexcept;


    ~PlayerInfo() = default;

    bool operator<(PlayerInfo const& a_other) const;

public:
    uint64_t m_time;
    size_t m_score;
    std::string m_name;
};

} // namespace arkanoid

#endif // PLAYER_INFO_HPP