#pragma once
#include "World.h"
#include "ScoreBoard.h"

class Engine
{
protected:
	sf::RenderWindow window;
	World world;
	ScoreBoard scoreboard;

public:
	Engine();
	Engine(float, unsigned int, unsigned int, sf::Vector2f&);

	std::vector<std::vector<bool>>& getWorldMap();
	std::vector<std::vector<sf::Color>>& getColorMap();

	// virtual functions
	virtual void start();
	virtual void input();
	virtual void update(float&);
	virtual void render();

	// pure virtual functions
	virtual std::set<std::pair<int, int>> getPlayerPosition() = 0;
};

