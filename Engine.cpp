#include "Engine.h"
using namespace borgo;

Engine::Engine() : world(World(40.0f, 8, 8, sf::Vector2f(50.f, 50.f))), 
    scoreboard(ScoreBoard(4.f, 80, 80, sf::Vector2f(370.f, 50.f)))
{
    // set up window
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;
    
    window.create(sf::VideoMode(resolution.x, resolution.y),
        "Borgo",
        sf::Style::Titlebar | sf::Style::Close);

    window.setFramerateLimit(60);
}

Engine::Engine(float bSize, unsigned int wWidth, unsigned int wHeight, sf::Vector2f& wPosition) 
    : world(World(bSize, wWidth, wHeight, wPosition)), 
    scoreboard(ScoreBoard(3.f, 400, 80, sf::Vector2f(wPosition.x+bSize*wWidth, 0)))
{
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    window.create(sf::VideoMode(resolution.x, resolution.y),
        "Borgo",
        sf::Style::Titlebar | sf::Style::Close);

    window.setFramerateLimit(60);
}

Engine::Engine(World& w, ScoreBoard& s): world(w), scoreboard(s)
{
    float wWidth = world.getBlockSize() * world.getWidth();
    float wHeight = world.getBlockSize() * world.getHeight();
    float sWidth = scoreboard.getBlockSize() * scoreboard.getWidth();
    float sHeight = scoreboard.getBlockSize() * scoreboard.getHeight();
    sf::Vector2f resolution(wWidth + sWidth,
        std::max(wHeight, sHeight));
    window.create(sf::VideoMode(resolution.x, resolution.y),
        "Borgo",
        sf::Style::Titlebar | sf::Style::Close);

    window.setFramerateLimit(60);
}

std::vector<std::vector<bool>>& Engine::getWorldMap()
{
    return world.worldMap;
}

std::vector<std::vector<sf::Color>>& Engine::getColorMap()
{
    return world.colorMap;
}
