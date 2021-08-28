#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <set>


class World : public sf::Drawable
{
private:

	const sf::Color DEFAULT_COLOR = sf::Color::White;
	const sf::Color DEFAULT_BACKGROUND = sf::Color::Transparent;

	float blockSize;
	int width, height;
	sf::Vector2f position;
	std::vector<std::vector<bool>> worldMap;	
	std::vector<std::vector<sf::Color>> colorMap;
	sf::RenderTexture texture;  // Everything drawn here first
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	World(float blockSize, unsigned int width, unsigned int height, sf::Vector2f position);
	World(const World&);
	void addObject(const std::map<std::pair<int, int>, sf::Color>& posColors);
	void addObject(const std::set<std::pair<int, int>>& posColors);
	void clearObject(const std::set<std::pair<int, int>>& pos);
	void transformObject(const std::set<std::pair<int, int>>& from, const std::map<std::pair<int, int>, sf::Color>& to);
	bool transformObject(const std::set<std::pair<int, int>>& from, const int direction, const int step);
	void update();

	// Getters and Setters
	void setBlockSize(float bSize);
	void setWidth(int width);
	void setHeight(int height);
	void setPosition(sf::Vector2f pos);
	void setPosition(float x, float y);
	float getBlockSize() const;
	int getWidth() const;
	int getHeight() const;
	sf::Vector2f getPosition() const;

	const enum TransformDirection {
		RIGHT = 1,
		LEFT = 1 << 1,
		TOP = 1 << 2,
		BOTTOM = 1 << 3
	};

};
