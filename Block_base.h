#pragma once
#include <SFML/Graphics.hpp>

class Block_base
{
protected:

	const sf::Color DEFAULT_COLOR = sf::Color::White;
	const sf::Color DEFAULT_BACKGROUND = sf::Color::Transparent;

	float blockSize;
	int width, height;
	sf::Vector2f position;
	std::vector<std::vector<bool>> worldMap;
	std::vector<std::vector<sf::Color>> colorMap;
	sf::RenderTexture texture;  // Everything drawn here first

public:
	Block_base(float blockSize, unsigned int width, unsigned int height, sf::Vector2f position);
	Block_base(const Block_base& other);
	virtual void update() = 0;

	// Excecptions
	class OutOfBound {
	};
	class TextureNotCreated {
	};

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

