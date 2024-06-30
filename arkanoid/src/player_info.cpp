#include "player_info.hpp"

namespace arkanoid {

PlayerInfo::PlayerInfo(std::string const& a_name, uint64_t a_time, size_t a_score) noexcept
: m_time(a_time) 
, m_score(a_score)
, m_name(a_name) 
{
}

bool PlayerInfo::operator<(PlayerInfo const& a_other) const
{
    if (m_score != a_other.m_score) {
        return m_score < a_other.m_score;
    }
    return m_time > a_other.m_time;
}


} // namespace arkanoid
