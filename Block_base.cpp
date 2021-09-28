#include "Block_base.h"

Block_base::Block_base(float blockSize, unsigned int width, unsigned int height, sf::Vector2f position)
	: blockSize(blockSize), width(width), height(height), position(position) {
	worldMap = std::vector<std::vector<bool>>(height, std::vector<bool>(width, 0));
	colorMap = std::vector<std::vector<sf::Color>>(height, std::vector < sf::Color >(width, sf::Color::Black));

	sf::Vector2f resolution(blockSize * width, blockSize * height);
	if (!texture.create(resolution.x, resolution.y))
		throw TextureNotCreated();
}

Block_base::Block_base(const Block_base& other)
	: blockSize(other.blockSize), width(other.width), height(other.height), position(other.position),
	worldMap(other.worldMap), colorMap(other.colorMap)
{
	/**
	* @Copy Constructor
	* -sf::RenderTexture type texture object has deleted copy constructor
	* -new texture object of same dimension is created
	*/
	if (!texture.create(blockSize * width, blockSize * height))
		throw TextureNotCreated();
}

void Block_base::setBlockSize(float bSize)
{
	this->blockSize = bSize;
}

void Block_base::setWidth(int width)
{
	this->width = width;
}

void Block_base::setHeight(int height)
{
	this->height = height;
}

void Block_base::setPosition(sf::Vector2f pos)
{
	this->position = pos;
}

void Block_base::setPosition(float x, float y)
{
	this->position = sf::Vector2f(x, y);
}

float Block_base::getBlockSize() const
{
	return blockSize;
}

int Block_base::getWidth() const
{
	return width;
}

int Block_base::getHeight() const
{
	return height;
}

sf::Vector2f Block_base::getPosition() const
{
	/**
	* @return sf::Vector2f
	* Getter for world top-left corner position
	*/
	return position;
}