#pragma once
#include "World.h"

class Engine
{
private:
	sf::RenderWindow window;
	World world;

public:
	Engine();
	Engine(float, unsigned int, unsigned int, sf::Vector2f&);
	void start();
	void input();
	void update(float&);
	void render();
};

