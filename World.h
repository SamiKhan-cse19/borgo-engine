#pragma once
#include <vector>
#include <map>
#include "Block_base.h"
#include <set>

namespace borgo
{
	class Engine; // Forward Declaration of Engine class

	const enum TransformDirection {
		Right = 1,
		Left = 1 << 1,
		Top = 1 << 2,
		Bottom = 1 << 3
	};

	class World : public sf::Drawable, public Block_base
	{
	private:
		/**
		* Overloaded draw function of sf::Drawable class
		* 
		* Refer to documentation of sf::Drawable
		*/
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		friend class Engine;

	public:
		/**
		* Constructor of World type object
		* 
		* Refer to borgo::Block_base
		*/
		World(float blockSize, unsigned int width, unsigned int height, sf::Vector2f position);
		World(const World&);

		/**
		* Adding/removing object from the world window, Transformation of object
		* 
		* Usage:
		* clear object first from prev location, then add object to new location
		* Or, use transformObject method
		*/
		void addObject(const std::map<std::pair<int, int>, sf::Color>& posColors);
		void addObject(const std::set<std::pair<int, int>>& posColors);
		void clearObject(const std::set<std::pair<int, int>>& pos);
		void transformObject(const std::set<std::pair<int, int>>& from,
			const std::map<std::pair<int, int>, sf::Color>& to);
		bool transformObject(const std::set<std::pair<int, int>>& from, const int direction, const int step);
		
		/**
		* Draw the contents of worldMap into texture
		* Overloaded method of Block_base class
		*/
		void update();

	};
}


