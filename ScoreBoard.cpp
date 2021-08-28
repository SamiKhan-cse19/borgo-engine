#include "ScoreBoard.h"

void ScoreBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

ScoreBoard::ScoreBoard(int width, int height, sf::Vector2f position)
	: width(width), height(height), position(position)
{
	if (!texture.create(width, height))
		exit(1);
}

ScoreBoard::ScoreBoard(const ScoreBoard& other)
	: width(other.width), height(other.height), position(other.position)
{
	if (!texture.create(width, height))
		exit(1);
}

void ScoreBoard::update()
{
	texture.clear(DEFAULT_BACKGROUND);
	//TODO: draw texts from scores vector
	texture.display();
}

void ScoreBoard::addScore(const std::pair<std::string, int>& newScore)
{
	/**
	* @return void
	* inserts new score key and value at the end
	*/
	scoreKeys.push_back(newScore.first);
	scoreValues.insert(newScore);
}

void ScoreBoard::addScore(const std::pair<std::string, int>& newScore, int index)
{
	/**
	* @return void
	* inserts new score key and value at position index
	*/
	scoreKeys.insert(scoreKeys.begin() + index, newScore.first);
	scoreValues.insert(newScore);
}

void ScoreBoard::addScoreList(const std::list<std::pair<std::string, int>>& newScoreList)
{
	/**
	* @return void
	* adds a list of score key value pairs to this->scores 
	*/
	for (auto p : newScoreList) {
		scoreKeys.push_back(p.first);
		scoreValues.insert(p);
	}
}

int ScoreBoard::getScore(const int index) const
{
	/**
	* @return int
	* returns the score value at index 'index'
	*/
	return scoreValues.at(scoreKeys.at(index));
}

int ScoreBoard::getScore(const std::string key) const
{
	/**
	* @return int
	* returns score value for key 'key'
	*/
	return scoreValues.at(key);
}

void ScoreBoard::setWidth(int width)
{
	this->width = width;
}

void ScoreBoard::setHeight(int height)
{
	this->height = height;
}

void ScoreBoard::setPosition(sf::Vector2f pos)
{
	this->position = pos;
}

void ScoreBoard::setPosition(float x, float y)
{
	this->position = sf::Vector2f(x, y);
}

int ScoreBoard::getWidth() const
{
	return width;
}

int ScoreBoard::getHeight() const
{
	return height;
}

sf::Vector2f ScoreBoard::getPosition() const
{
	return position;
}
