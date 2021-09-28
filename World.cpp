#include "World.h"

World::World(float blockSize, unsigned int width, unsigned int height, sf::Vector2f position)
	: Block_base(blockSize, width, height, position) {
	
}
World::World(const World& other) 
	: Block_base(other)
{
	
}
void World::addObject(const std::map<std::pair<int, int>, sf::Color>& posColors) {
	/**
	* @return void
	* -add new object to the world window
	* -set user defined color
	*/
	for (auto p : posColors) {
		std::pair<int, int> pf = p.first;
		worldMap[pf.second][pf.first] = 1;
		colorMap[pf.second][pf.first] = p.second;
	}
}
void World::addObject(const std::set<std::pair<int, int>>& pos)
{
	/**
	* @return void
	* -add new object to the world window
	* -set default color white
	*/
	for (auto p : pos) {
		worldMap[p.second][p.first] = 1;
		colorMap[p.second][p.first] = DEFAULT_COLOR;
	}
}
void World::clearObject(const std::set<std::pair<int, int>>& pos) {
	/**
	* @return void
	* -clear object position in world
	*/
	for (auto p : pos) {
		worldMap[p.second][p.first] = 0;
		colorMap[p.second][p.first] = DEFAULT_BACKGROUND;
	}
}

void World::transformObject(const std::set<std::pair<int, int>>& from, const std::map<std::pair<int, int>, sf::Color>& to)
{
	clearObject(from);
	addObject(to);
}

bool World::transformObject(const std::set<std::pair<int, int>>& from, const int direction, const int step)
{
	/**
	* @return bool
	* -copy object to step times direction
	* -return if successful or not
	*/

	std::map<std::pair<int, int>, sf::Color> to;

	for (auto p : from) {
		std::pair<int, int> newPos;
		switch (direction) {
		case TransformDirection::LEFT:
			newPos.first = p.first - step;
			break;
		case TransformDirection::RIGHT:
			newPos.first = p.first + step;
			break;
		case TransformDirection::TOP:
			newPos.second = p.second - step;
			break;
		case TransformDirection::BOTTOM:
			newPos.second = p.second + step;
			break;
		case TransformDirection::TOP|TransformDirection::LEFT:
			newPos.first = p.first - step;
			newPos.second = p.second - step;
			break;
		case TransformDirection::TOP | TransformDirection::RIGHT:
			newPos.first = p.first + step;
			newPos.second = p.second - step;
			break;
		case TransformDirection::BOTTOM | TransformDirection::LEFT:
			newPos.first = p.first - step;
			newPos.second = p.second + step;
			break;
		case TransformDirection::BOTTOM | TransformDirection::RIGHT:
			newPos.first = p.first + step;
			newPos.second = p.second + step;
			break;
		default:
			newPos = p;
		}
		if (newPos.first < 0 || newPos.first >= width || newPos.second < 0 || newPos.second >= height)
			return false;
		to.insert(make_pair(newPos, colorMap[p.second][p.first]));
	}
	transformObject(from, to);
	return true;
}

void World::update()
{
	texture.clear(DEFAULT_BACKGROUND);
	sf::RectangleShape blockShape(sf::Vector2f(blockSize, blockSize));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			blockShape.setPosition(j * blockSize, i * blockSize);
			blockShape.setFillColor(colorMap[i][j]);
			texture.draw(blockShape);
		}
	}
	texture.display();
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
