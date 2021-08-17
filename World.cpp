#include "World.h"
World::World(float blockSize, unsigned int width, unsigned int height, sf::Vector2f position)
	: blockSize(blockSize), width(width), height(height), position(position) {
	worldMap = std::vector<std::vector<bool>>(height, std::vector<bool>(width, 0));
	colorMap = std::vector<std::vector<sf::Color>>(height, std::vector < sf::Color >(width, sf::Color::Black));

	blockShape.setSize(sf::Vector2f(blockSize, blockSize));

	sf::Vector2f resolution(blockSize * width, blockSize * height);
	if (!texture.create(resolution.x, resolution.y))
		exit(1);
}
void World::addObject(std::map<std::pair<int, int>, sf::Color>& posColors) {
	for (auto p : posColors) {
		std::pair<int, int> pf = p.first;
		worldMap[pf.second][pf.first] = 1;
		colorMap[pf.second][pf.first] = p.second;
	}
}
void World::clearObject(std::set<std::pair<int, int>>& pos) {
	for (auto p : pos) {
		worldMap[p.second][p.first] = 0;
		colorMap[p.second][p.first] = sf::Color::Black;
	}
}

void World::transformObject(std::set<std::pair<int, int>>& from, std::map<std::pair<int, int>, sf::Color>& to)
{
	clearObject(from);
	addObject(to);
}

void World::update()
{
	texture.clear(sf::Color::Transparent);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			blockShape.setPosition(j * blockSize, i * blockSize);
			blockShape.setFillColor(colorMap[i][j]);
			texture.draw(blockShape);
		}
	}
	texture.display();
}

void World::setBlockSize(float bSize)
{
	this->blockSize = bSize;
}

void World::setWidth(int width)
{
	this->width = width;
}

void World::setHeight(int height)
{
	this->height = height;
}

void World::setPosition(sf::Vector2f& pos)
{
	this->position = pos;
}

void World::setPosition(float x, float y)
{
	this->position = sf::Vector2f(x, y);
}

float World::getBlockSize() const
{
	return blockSize;
}

int World::getWidth() const
{
	return width;
}

int World::getHeight() const
{
	return height;
}

sf::Vector2f World::getPosition() const
{
	/**
	* @return sf::Vector2f
	* Getter for world top-left corner position
	*/
	return position;
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	/**
	* @return void
	* Overridden draw function
	* Draw contents of texture to target
	*/
	sf::Sprite sprite(texture.getTexture());
	sprite.setPosition(position);
	target.draw(sprite, states);
}
