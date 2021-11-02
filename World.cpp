#include "World.h"
using namespace borgo;

World::World(float blockSize, unsigned int width, unsigned int height, sf::Vector2f position)
	: Block_base(blockSize, width, height, position) 
{
	backgroundColor = sf::Color::Black;
}
World::World(const World& other) 
	: Block_base(other)
{
	
}

void World::addObject(const std::map<std::pair<int, int>, sf::Color>& posColors) 
{	
	for (auto p : posColors) {
		std::pair<int, int> pf = p.first;
		worldMap[pf.second][pf.first] = 1;
		colorMap[pf.second][pf.first] = p.second;
	}
}

void World::addObject(const std::set<std::pair<int, int>>& pos)
{
	for (auto p : pos) {
		worldMap[p.second][p.first] = 1;
		colorMap[p.second][p.first] = DEFAULT_COLOR;
	}
}
void World::clearObject(const std::set<std::pair<int, int>>& pos) 
{
	for (auto p : pos) {
		worldMap[p.second][p.first] = 0;
		colorMap[p.second][p.first] = backgroundColor;
	}
}

void World::transformObject(const std::set<std::pair<int, int>>& from, const std::map<std::pair<int, int>, sf::Color>& to)
{
	clearObject(from);
	addObject(to);
}

bool World::transformObject(const std::set<std::pair<int, int>>& from, const int direction, const int step)
{
	std::map<std::pair<int, int>, sf::Color> to;

	for (auto p : from) {
		std::pair<int, int> newPos;
		switch (direction) {
		case TransformDirection::Left:
			newPos.first = p.first - step;
			break;
		case TransformDirection::Right:
			newPos.first = p.first + step;
			break;
		case TransformDirection::Top:
			newPos.second = p.second - step;
			break;
		case TransformDirection::Bottom:
			newPos.second = p.second + step;
			break;
		case TransformDirection::Top|TransformDirection::Left:
			newPos.first = p.first - step;
			newPos.second = p.second - step;
			break;
		case TransformDirection::Top | TransformDirection::Right:
			newPos.first = p.first + step;
			newPos.second = p.second - step;
			break;
		case TransformDirection::Bottom | TransformDirection::Left:
			newPos.first = p.first - step;
			newPos.second = p.second + step;
			break;
		case TransformDirection::Bottom | TransformDirection::Right:
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
	texture.clear(backgroundColor);
	sf::RectangleShape blockShape(sf::Vector2f(blockSize, blockSize));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			blockShape.setPosition(j * blockSize, i * blockSize);
			if(worldMap[i][j]) blockShape.setFillColor(colorMap[i][j]);
			else blockShape.setFillColor(backgroundColor);
			texture.draw(blockShape);
		}
	}
	texture.display();
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite sprite(texture.getTexture());
	sprite.setPosition(position);
	target.draw(sprite, states);
}
