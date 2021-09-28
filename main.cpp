#include <iostream>
#include "World.h"
#include "Engine.h"

int main() {
	/*Engine engine;

	engine.start();
	*/

	// For Debugging purposes on Scoreboard
	ScoreBoard sb(3.f, 400, 80, sf::Vector2f(0, 0));
	sb.setPadding(1);
	std::pair<std::string, int> sc1("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0);
	std::pair<std::string, int> sc2("abcdefghijklmnopqrstuvwxyz", 1);

	sb.addScore(sc1);
	sb.addScore(sc2);

	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	sf::RenderWindow window(sf::VideoMode(800, 800),
		"Simple Game Engine",
		sf::Style::Titlebar | sf::Style::Close);

	window.setFramerateLimit(30);
	while (window.isOpen()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		try {
			sb.update();
		}
		catch (ScoreBoard::Error) {
			std::cout << "ColorMap out of range" << std::endl;
			window.close();
		}
		window.clear();
		window.draw(sb);
		window.display();
	}

}