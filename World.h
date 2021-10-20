#pragma once
#include <vector>
#include <map>
#include "Block_base.h"
#include <set>

class Engine; // Forward Declaration of Engine class

class World : public sf::Drawable, public Block_base
{
private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	friend class Engine;
public:
	World(float blockSize, unsigned int width, unsigned int height, sf::Vector2f position);
	World(const World&);
	void addObject(const std::map<std::pair<int, int>, sf::Color>& posColors);
	void addObject(const std::set<std::pair<int, int>>& posColors);
	void clearObject(const std::set<std::pair<int, int>>& pos);
	void transformObject(const std::set<std::pair<int, int>>& from, 
		const std::map<std::pair<int, int>, sf::Color>& to);
	bool transformObject(const std::set<std::pair<int, int>>& from, const int direction, const int step);
	void update();

	const enum TransformDirection {
		Right = 1,
		Left = 1 << 1,
		Top = 1 << 2,
		Bottom = 1 << 3
	};

};
