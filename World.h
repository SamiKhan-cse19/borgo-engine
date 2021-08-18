#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <set>

class World : public sf::Drawable
{
private:
	float blockSize;
	int width, height;
	sf::Vector2f position;
	std::vector<std::vector<bool>> worldMap;	
	std::vector<std::vector<sf::Color>> colorMap;
	sf::RenderTexture texture;  // Everything drawn here first
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	World(float blockSize, unsigned int width, unsigned int height, sf::Vector2f position);
	World(const World&);
	void addObject(std::map<std::pair<int, int>, sf::Color>& posColors);
	void clearObject(std::set<std::pair<int, int>>& pos);
	void transformObject(std::set<std::pair<int, int>>& from, std::map<std::pair<int, int>, sf::Color>& to);
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

};
