#include "ScoreBoard.h"
using namespace borgo;

void ScoreBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite sprite(texture.getTexture());
	sprite.setPosition(position);
	target.draw(sprite, states);
}

void ScoreBoard::drawScoreLine(std::string line, std::pair<int, int>& cursor)
{
	for (auto c : line) {
		int id = static_cast<int>(c);
		for (int i = 8; i > 0; i--) {
			for (int j = 8; j > 0; j--) {
				int px = cursor.first + 8 - i;
				int py = cursor.second + 8 - j;
				if (px < 0 || py < 0 || px >= width || py >= height) throw MapWidthExceeded();
				bool color = font[id] & (1LL << (8 * (j - 1) + i - 1));
				if (color) colorMap[py][px] = textColor;
				else colorMap[py][px] = backgroundColor;
			}
		}
		cursor.first += 8;
	}
}

void ScoreBoard::drawScoreLine(std::string line, std::pair<int, int>& cursor, sf::Color color)
{
	for (auto c : line) {
		
		int id = static_cast<int>(c);
		for (int i = 8; i > 0; i--) {
			for (int j = 8; j > 0; j--) {
				int px = cursor.first + 8 - i;
				int py = cursor.second + 8 - j;
				if (px < 0 || py < 0 || px >= width || py >= height) throw MapWidthExceeded();
				bool hasColor = font[id] & (1LL << (8 * (j - 1) + i - 1));
				if (hasColor) colorMap[py][px] = color;
				else colorMap[py][px] = backgroundColor;
			}
		}
		cursor.first += 8;
	}
}

void ScoreBoard::updateColorMap()
{
	std::pair<int, int> cursor(padding, padding);
	for (auto s : scoreKeys) {
		drawScoreLine(s + " : " + std::to_string(getScore(s)), cursor);
		cursor.first = padding;
		cursor.second += 8 + lineGap;
	}
}

ScoreBoard::ScoreBoard(float blockSize, int width, int height, sf::Vector2f position)
	: Block_base(blockSize, width, height, position)
{
	setLineGap(0);
	setPadding(0);
	setTextColor(DEFAULT_COLOR);
}

ScoreBoard::ScoreBoard(const ScoreBoard& other)
	: Block_base(other), lineGap(other.lineGap), padding(other.padding)
{
	setTextColor(other.textColor);
}

void ScoreBoard::update()
{
	updateColorMap();
	texture.clear(backgroundColor);

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
	scoreKeys.insert(scoreKeys.begin() + index, newScore.first);
	scoreValues.insert(newScore);
}

void ScoreBoard::addScoreList(const std::list<std::pair<std::string, int>>& newScoreList)
{
	for (auto p : newScoreList) {
		scoreKeys.push_back(p.first);
		scoreValues.insert(p);
	}
}

int ScoreBoard::getScore(const int index) const
{
	if (index < 0 || index >= scoreKeys.size()) throw Block_base::OutOfBound();
	return scoreValues.at(scoreKeys.at(index));
}

int ScoreBoard::getScore(const std::string key) const
{
	if (!scoreValues.count(key)) throw Block_base::OutOfBound();
	return scoreValues.at(key);
}

void ScoreBoard::editScore(const int index, const int value)
{
	if (index < 0 || index >= scoreKeys.size()) throw Block_base::OutOfBound();
	scoreValues[scoreKeys[index]] = value;
}

void ScoreBoard::editScore(const std::string key, const int value)
{
	if (!scoreValues.count(key)) throw Block_base::OutOfBound();
	scoreValues[key] = value;
}

void ScoreBoard::clearBoard()
{
	for (int i = 0; i < worldMap.size(); i++) {
		for (int j = 0; j < worldMap[0].size(); j++) {
			worldMap[i][j] = 0;
			colorMap[i][j] = backgroundColor;
		}
	}
	scoreKeys.clear();
	scoreValues.clear();
}

void ScoreBoard::setLineGap(unsigned int lineGap)
{
	this->lineGap = lineGap;
}

void ScoreBoard::setPadding(unsigned int padding)
{
	this->padding = padding;
}

void ScoreBoard::setTextColor(sf::Color color)
{
	textColor = color;
}

unsigned int ScoreBoard::getLineGap() const
{
	return lineGap;
}

unsigned int ScoreBoard::getPadding() const
{
	return padding;
}

sf::Color ScoreBoard::getTextColor() const
{
	return textColor;
}
