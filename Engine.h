#pragma once
#include "World.h"
#include "ScoreBoard.h"

namespace borgo
{
	class Engine
	{
	protected:
		sf::RenderWindow window;
		World world;
		ScoreBoard scoreboard;

	public:
		Engine();
		Engine(float, unsigned int, unsigned int, sf::Vector2f&);
		Engine(World&, ScoreBoard&);

		std::vector<std::vector<bool>>& getWorldMap();
		std::vector<std::vector<sf::Color>>& getColorMap();

		// virtual functions
		virtual void start() = 0;
		virtual void input() = 0;
		virtual void update(float&) = 0;
		virtual void render() = 0;

	};


}
