#ifndef GLOBAL_STANDARTS_HPP
#define GLOBAL_STANDARTS_HPP

#include "layout_formatting.hpp"

#include <map> // color map
#include <cstddef> // size_t
#include <SFML/Graphics/RectangleShape.hpp> // colors and shapes
#include <SFML/Graphics/Color.hpp> // colors
#include <SFML/System/Time.hpp> // time
#include <SFML/Graphics/Text.hpp> // text

namespace shapes {

//files
extern const std::string score_file_name;
extern const uint32_t number_of_levels;
extern const uint32_t max_bricks;

//windows
extern const float window_height;
extern const float window_width;
extern const float free_space;
extern const unsigned int frame_limit;

//mechanics
extern const sf::Time game_frame;
extern const float paddle_speed;

extern const float ball_initial_speed_factor;
extern const float ball_speed_refactor;

extern const float elastic_modifier;

//bricks
extern const float brick_height;
extern const float brick_width;

extern const sf::Vector2f default_brick_location;

extern const float brick_outline_size;

extern const sf::Color brick_outline_color; 

//bricks types
extern const std::map<arkanoid::Color,sf::Color> color_code;

//paddle
extern const float paddle_height;
extern const float paddle_width;
extern const float resize_factor;
extern const float chasm_height;

extern const sf::Vector2f paddle_start_location;

extern const float paddle_start_y;
extern const float paddle_start_x;

extern const float paddle_outline_size;
extern const sf::Color paddle_color;
extern const sf::Color paddle_outline;

//ball
extern const float ball_radius;

extern const sf::Vector2f ball_start_location;

extern const sf::Time time_dilation_time_out;

extern const float time_dilation_factor;


extern const float ball_outline_size;
extern const sf::Color ball_color;
extern const sf::Color ball_outline_color;

//graphics

extern const float background_x_scale;
extern const float background_y_scale;

extern const sf::Vector2f title_position;

extern const float title_font_size;

extern const float title_outline_size;

extern const sf::Color title_color;

extern const sf::Vector2f lives_position;
extern const sf::Vector2f score_position;

extern const sf::Color text_color;
extern const sf::Color background_color;

extern const sf::Font text_font;

extern const unsigned int font_size;
extern const unsigned int font_outline;

extern const sf::Vector2f endgame_score_position;

extern const sf::Vector2f endgame_message_position;

extern const sf::Vector2f play_button_position;

extern const sf::Vector2f exit_button_position;

extern const float button_width;

extern const float button_height;

extern const float button_outline_size;

extern const sf::Color button_color;

extern const sf::Vector2f button;

//power ups

extern const float powers_speed;
extern const float powers_radius;

extern const sf::Time powers_life_span;


} // namespace shapes

#endif // GLOBAL_STANDARTS_HPP