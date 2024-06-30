#include "graphics.hpp"
#include "event_handler.hpp"
#include "global_standarts.hpp"

#include <string> // to string
#include <exception>

//TODO: replace with assist func in all functions
//TODO: make the game look less like shit
//TODO: make scoreboard visible in level 4-6
//TODO: add some stuff to make it prettier


namespace arkanoid {

namespace {

sf::Text make_text(std::string const& a_text,sf::Color a_color, float a_size, sf::Font const& a_font)
{
    sf::Text text;
    text.setCharacterSize(a_size);
    text.setFillColor(a_color);
    text.setFont(a_font);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(shapes::font_outline);
    sf::String string{a_text};
    text.setString(a_text);
    return text;

}

} //namespace

Graphics::Graphics(sf::Color a_background)
: m_background_color(a_background)
{
    if (not m_main_screen.loadFromFile("background.jpg")) {
        throw std::runtime_error("unable to load background");
    }
    if (not m_font.loadFromFile("arial.ttf")) {
        throw std::runtime_error("unable to load font");
    }
    if (not m_back_ground.loadFromFile("level_background.png")) {
        throw std::runtime_error("unable to load background");
    }
}

void Graphics::draw_start_screen(sf::RenderWindow& a_window) const
{
    sf::RectangleShape start_button{shapes::button};
    start_button.setFillColor(shapes::button_color);
    start_button.setOutlineThickness(shapes::button_outline_size);
    start_button.setOutlineColor(sf::Color::Black);
    sf::RectangleShape exit_button{start_button};
    start_button.setPosition(shapes::play_button_position);
    exit_button.setPosition(shapes::exit_button_position);

    sf::String play_string{"      Play"};
    sf::String exit_string("      Exit");
    sf::String title_text("Arkanoid!1!1!");

    sf::Text play = make_text(play_string,shapes::text_color,shapes::font_size,m_font);
    play.setPosition(shapes::play_button_position);

    sf::Text exit = make_text(exit_string, shapes::text_color, shapes::font_size,m_font);
    exit.setPosition(shapes::exit_button_position);

    sf::Text title = make_text(title_text,shapes::title_color,shapes::title_font_size,m_font);

    title.setPosition(shapes::title_position);

    sf::Sprite background;
    background.setTexture(m_main_screen);
    background.setOrigin(sf::Vector2f(shapes::window_width/2,shapes::window_height/2));
    // background.setScale(sf::Vector2f(shapes::window_width,shapes::window_height));
    // background.setPosition()
    a_window.clear(m_background_color);
    a_window.draw(background);
    a_window.draw(title);
    a_window.draw(start_button);
    a_window.draw(exit_button);
    a_window.draw(play);
    a_window.draw(exit);
    a_window.display();
    
}

void Graphics::draw_game(sf::RenderWindow& a_window,shapes::ShapeManager const& a_shapes, size_t a_score, int a_lives) const
{
    std::string lives_string{"Lives: "};
    std::string num_lives = std::to_string(a_lives);
    lives_string += num_lives;
    sf::Text lives = make_text(lives_string,shapes::text_color,shapes::font_size,m_font);
    lives.setPosition(shapes::lives_position);
    lives.setString(lives_string);

    std::string score_string{"Score: "};
    std::string score = std::to_string(a_score);
    score_string += score;
    sf::Text score_line = make_text(score_string,shapes::text_color,shapes::font_size,m_font);
    score_line.setPosition(shapes::score_position);
    score_line.setCharacterSize(shapes::font_size);
    score_line.setFillColor(shapes::text_color);
    score_line.setFont(m_font);

    sf::Sprite background;
    background.setTexture(m_back_ground);
    background.setPosition(sf::Vector2f(0,0));
    background.setScale(shapes::background_x_scale,shapes::background_y_scale);
    a_window.clear();
    a_window.draw(background);
    a_window.draw(lives);
    a_window.draw(score_line);
    a_shapes.draw_all_shapes(a_window);
    a_window.display();
}

void Graphics::draw_endgame(sf::RenderWindow& a_window, std::string a_message, sf::Color a_color,size_t a_score) const
{   
    sf::String score_string{"Score: " + std::to_string(a_score)};
    sf::Text score = make_text(score_string,shapes::text_color,shapes::font_size,m_font);
    score.setPosition(shapes::endgame_score_position);
    score.setString(score_string);    

    sf::Text endgame_message = make_text(a_message, a_color, shapes::font_size, m_font);
    endgame_message.setPosition(shapes::endgame_message_position);
    sf::String endgame_string{a_message};
    endgame_message.setString(endgame_string);

    sf::Sprite background;
    background.setTexture(m_back_ground);
    background.setPosition(sf::Vector2f(0,0));
    background.setScale(shapes::background_x_scale,shapes::background_y_scale);

    a_window.clear(m_background_color);
    a_window.draw(background);
    a_window.draw(score);
    a_window.draw(endgame_message);
    a_window.display();  
}

std::string Graphics::player_name_prompt(sf::RenderWindow& a_window, SoundManager& a_sounds)
{
    sf::String player_name;
    sf::Text enter_name = make_text("Enter your name: ",sf::Color::White,shapes::font_size,m_font);
    sf::Text name = make_text(player_name.toAnsiString(),sf::Color::White,shapes::font_size,m_font);
    enter_name.setPosition(shapes::play_button_position);
    name.setPosition(shapes::exit_button_position);
    arkanoid::EventHandler handler{a_sounds};
    sf::Event event;
    bool stop = false;

    sf::Sprite background;
    background.setTexture(m_back_ground);
    background.setPosition(sf::Vector2f(0,0));
    background.setScale(shapes::background_x_scale,shapes::background_y_scale);    

    while (a_window.isOpen()) {
        while (a_window.pollEvent(event)) {
            handler.handle_player_name(event,player_name,stop);
        }
        name.setString(player_name);
        a_window.clear(m_background_color);
        a_window.draw(background);
        a_window.draw(enter_name);
        a_window.draw(name);
        [[maybe_unused]]std::string for_test = player_name.toAnsiString();
        a_window.display();
        if (stop) {
            break;
        }
    }
    return player_name.toAnsiString();

}

void Graphics::draw_and_display(sf::RenderWindow& a_window, PlayerInfo const& a_player, sf::Vector2f a_location) const
{
    std::string name_with_delim{a_player.m_name};
    name_with_delim.append(" : ");
    sf::Text name = make_text(name_with_delim,sf::Color::White,shapes::font_size,m_font);
    sf::Text score = make_text(std::to_string(a_player.m_score),sf::Color::White,shapes::font_size,m_font);
    name.setPosition(a_location);
    sf::Vector2f score_location(a_location);
    score_location.x += 200;
    score.setPosition(score_location);
    a_window.draw(name);
    a_window.draw(score);
    
}

void Graphics::draw_score_board(sf::RenderWindow& a_window,std::vector<PlayerInfo> const& a_score_board) const
{
    float y_location = shapes::window_height - (shapes::font_size)*10;
    float x_location = shapes::window_width / 2 - ((shapes::font_size)*13 / 2);
    a_window.clear(m_background_color);
    int index = 10;

    sf::Sprite background;
    background.setTexture(m_back_ground);
    background.setPosition(sf::Vector2f(0,0));
    background.setScale(shapes::background_x_scale,shapes::background_y_scale);    

    a_window.draw(background);
    for (auto it : a_score_board) {
        std::string index_string{std::to_string(index) + "  "};
        
        sf::Text num = make_text(index_string,sf::Color::White,shapes::font_size,m_font);
        num.setPosition(x_location,y_location);
        a_window.draw(num);
        draw_and_display(a_window,it,sf::Vector2f(x_location + 50,y_location));
        y_location -= 50;
        --index;
    }
    a_window.display();
}

} // namespace arkanoid
