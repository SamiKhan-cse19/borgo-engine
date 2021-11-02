#pragma once
#include <SFML/Graphics.hpp>
namespace borgo
{
	class Block_base
	{
	protected:

		const sf::Color DEFAULT_COLOR = sf::Color::White;   // Default object color
		const sf::Color DEFAULT_BACKGROUND = sf::Color::Transparent;  // Default background color

		float blockSize;
		int width, height;
		sf::Vector2f position;
		std::vector<std::vector<bool>> worldMap;
		std::vector<std::vector<sf::Color>> colorMap;
		sf::RenderTexture texture; 
		sf::Color backgroundColor;

	public:
		/**
		* Constructor for Block_base type object
		* 
		* @param blockSize the length of a block in pixels
		* @param width the width of object in blocks
		* @param height the height of object in blocks
		* @param position position of object inside window, calculated in pixels from (0,0)
		*/
		Block_base(float blockSize, unsigned int width, unsigned int height, sf::Vector2f position);

		/**
		* Copy constructor for Block_base type object
		* 
		* @param pass by reference Block_base type object 
		*/
		Block_base(const Block_base& other);

		/**
		* Pure virtual function
		* updates any changes done in the map in texture variable
		*/
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

		/**
		* Get or set background color
		* Default value set to sf::Color::Black
		*/
		void setBackgroundColor(sf::Color bgColor);
		sf::Color getBackgroundColor() const;

	};

}


