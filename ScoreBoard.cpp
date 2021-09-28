#include "ScoreBoard.h"

void ScoreBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const
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

void ScoreBoard::drawScoreLine(std::string line, std::pair<int, int>& cursor)
{
	//TODO: Exception Handling - OutOfBound
	for (auto c : line) {
		/**
		* For each character:
		*  -get the index for font array
		*  -nested for loop for 8x8 character
		*  -get actual position from cursor
		*  -increment cursor when done with a character
		*/
		int id = static_cast<int>(c);
		for (int i = 8; i > 0; i--) {
			for (int j = 8; j > 0; j--) {
				int px = cursor.first + 8 - i;
				int py = cursor.second + 8 - j;
				if (px < 0 || py < 0 || px >= width || py >= height) throw Error();
				bool color = font[id] & (1LL << (8 * (j - 1) + i - 1));
				if (color) colorMap[py][px] = DEFAULT_COLOR;
			}
		}
		cursor.first += 8;
	}
}


ScoreBoard::ScoreBoard(float blockSize, int width, int height, sf::Vector2f position)
	: Block_base(blockSize, width, height, position)
{
	setLineGap(0);
	setPadding(0);
}

ScoreBoard::ScoreBoard(const ScoreBoard& other)
	: Block_base(other), lineGap(other.lineGap), padding(other.padding)
{
	
}

void ScoreBoard::update()
{
	std::pair<int, int> cursor(padding, padding);
	for (auto s : scoreKeys) {
		drawScoreLine(s + " : " + std::to_string(getScore(s)), cursor);
		cursor.first = padding;
		cursor.second += 8 + lineGap;
	}

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

void ScoreBoard::clearBoard()
{
	//TODO: set all colors to DEFAULT_BACKGROUND
}

void ScoreBoard::setLineGap(unsigned int lineGap)
{
	this->lineGap = lineGap;
}

void ScoreBoard::setPadding(unsigned int padding)
{
	this->padding = padding;
}


unsigned int ScoreBoard::getLineGap() const
{
	return lineGap;
}

unsigned int ScoreBoard::getPadding() const
{
	return padding;
}
