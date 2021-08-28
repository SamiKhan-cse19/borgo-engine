#pragma once
#include <SFML/Graphics.hpp>
#include <list>
class ScoreBoard :
    public sf::Drawable
{
private:

    const sf::Color DEFAULT_COLOR = sf::Color::White;
    const sf::Color DEFAULT_BACKGROUND = sf::Color::Transparent;

    int width, height;
    sf::Vector2f position;
    sf::Font sFont;
    std::vector<std::string> scoreKeys;
    std::map<std::string, int> scoreValues;
    sf::RenderTexture texture;  // Everything drawn here first
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    ScoreBoard(int width, int height, sf::Vector2f position);
    ScoreBoard(const ScoreBoard&);
    void update();

    // Score related
    void addScore(const std::pair<std::string, int>& newScore);
    void addScore(const std::pair<std::string, int>& newScore, int index);
    void addScoreList(const std::list<std::pair<std::string, int>>& newScoreList);
    int getScore(const int index) const;
    int getScore(const std::string key) const;

    void setWidth(int width);
    void setHeight(int height);
    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);
    int getWidth() const;
    int getHeight() const;
    sf::Vector2f getPosition() const;
};

