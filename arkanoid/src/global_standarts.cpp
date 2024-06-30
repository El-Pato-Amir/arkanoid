#include "global_standarts.hpp"

namespace shapes {

//file
extern const std::string score_file_name = "top10.dat";
const uint32_t number_of_levels = 3;
//if you change this change the necessary functions in file manager
const uint32_t max_bricks = 256;

//windows
const float window_height = 768;
const float window_width = 1024;
const float free_space = window_height - 168;
const unsigned int frame_limit = 120;

//mechanics
const sf::Time game_frame = sf::seconds(1 / static_cast<float>(frame_limit));
const float paddle_speed = (window_width / 2) * game_frame.asSeconds();

const float ball_initial_speed_factor = (window_height * 0.6f) * game_frame.asSeconds();

const float elastic_modifier = 0.5;

//TODO: make actual calculation!
const float ball_speed_refactor = 10.0f;

//bricks
const float brick_outline_size = 1;

const float brick_height = (window_height - free_space) / 12;
const float brick_width = window_width / 15;

const sf::Vector2f default_brick_location(brick_width / 4, window_height - free_space);

const sf::Color brick_outline_color(sf::Color::Black);


//bricks types
const std::map<arkanoid::Color,sf::Color> color_code
{
    {arkanoid::Color::grey,sf::Color(192,192,192)},
    {arkanoid::Color::gold,sf::Color(255,215,0)},
    {arkanoid::Color::white,sf::Color::White},
    {arkanoid::Color::peach,sf::Color(255,165,0)},
    {arkanoid::Color::azure,sf::Color(0,255,255)},
    {arkanoid::Color::green,sf::Color::Green},
    {arkanoid::Color::red,sf::Color::Red},
    {arkanoid::Color::blue,sf::Color::Blue},
    {arkanoid::Color::pink,sf::Color(255,192,203)},
    {arkanoid::Color::orange,sf::Color(255,140,0)},
    {arkanoid::Color::resilient,sf::Color(127,0,255)},
    {arkanoid::Color::explosive,sf::Color(255,99,71)},
    {arkanoid::Color::life,sf::Color(255,192,203)},
    {arkanoid::Color::width,sf::Color(255,192,203)},
    {arkanoid::Color::time,sf::Color(255,192,203)},
};


//paddle
const float paddle_height = 15;
const float paddle_width = 150;
const float resize_factor = paddle_width / 4;
const float chasm_height = window_height - 20;

const float paddle_start_y = 550;
const float paddle_start_x = 200;

const sf::Vector2f paddle_start_location(window_width / 2, chasm_height - paddle_height);

const float paddle_outline_size = 2; 

const sf::Color paddle_color(255, 215, 0, 200);
const sf::Color paddle_outline(sf::Color::Black);

//ball
const float ball_radius = 5.0;

const sf::Vector2f ball_start_location(paddle_start_location.x + paddle_width / 2 - ball_radius, paddle_start_location.y - ball_radius*2 - ball_outline_size - 1);

const sf::Time time_dilation_time_out = sf::seconds(3);

const float time_dilation_factor = 3;

const float ball_outline_size = 1.5;

const sf::Color ball_color(sf::Color::Magenta);
const sf::Color ball_outline_color(sf::Color::Black);

//graphics

const float title_font_size = 56;

const sf::Vector2f title_position{(window_width / 2) - ((title_font_size*7) / 2)  , 100};

const float background_x_scale = window_width / 256.0f;
const float background_y_scale = window_height / 192.0f;

const float title_outline_size = 8;

const sf::Color title_color{sf::Color::Magenta};

const sf::Vector2f lives_position{5,5};
const sf::Vector2f score_position{window_width - 174,5};

const sf::Color text_color{sf::Color::White};
const sf::Color background_color{72,77,255};

extern const unsigned int font_size = 24;
extern const unsigned int font_outline = 2;


const float button_width = brick_width * 2;
const float button_height = font_size*1.5;

const sf::Vector2f endgame_message_position{window_width / 2 - font_size*4, window_height /2 - font_size*5};
const sf::Vector2f endgame_score_position{window_width / 2 - font_size*4, window_height /2 - font_size*4 + 5};
const sf::Vector2f play_button_position{window_width / 2 - (button_width/1.5f), window_height / 2 - 50};
const sf::Vector2f exit_button_position{window_width / 2 - (button_width/1.5f), window_height / 2};

const float button_outline_size = 4;

const sf::Color button_color{0, 127, 255};

const sf::Vector2f button{button_width,button_height};

//power ups

const float powers_speed = (window_height / 14) / frame_limit;
const float powers_radius = brick_width*1.5;

const sf::Time powers_life_span = sf::seconds(2);



} // namespace shapes