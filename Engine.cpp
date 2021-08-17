#include "Engine.h"

Engine::Engine() : world(World(40.0f, 8, 8, sf::Vector2f(150.f, 50.f)))
{
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;
    
    window.create(sf::VideoMode(resolution.x, resolution.y),
        "Simple Game Engine",
        sf::Style::Titlebar | sf::Style::Close);

    window.setFramerateLimit(30);
}

Engine::Engine(float bSize, unsigned int wWidth, unsigned int wHeight, sf::Vector2f& wPosition) 
    : world(World(bSize, wWidth, wHeight, wPosition))
{
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    window.create(sf::VideoMode(resolution.x, resolution.y),
        "Simple Game Engine",
        sf::Style::Titlebar | sf::Style::Close);

    window.setFramerateLimit(30);
}

void Engine::start()
{
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time dt = clock.restart();

        float seconds = dt.asSeconds();

        input();
        update(seconds);
        render();

    }
}

void Engine::input()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
       
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        
    }
}

void Engine::update(float& dt)
{
    /**
    * @return void
    * -parameter type float dt references time passed (seconds)
    * after last update
    * -update variables and call member update functions of objects
    */

    world.update();

}

void Engine::render()
{
    /**
    * @return void
    * - clear window for rendering
    * - pass drawable components to RenderWindow type object window
    * - display contents of window
    */
    window.clear();

    window.draw(world);

    window.display();

}
