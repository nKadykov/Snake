#pragma once
#include <SFML/Graphics.hpp>

enum class GameOverState { ON, OFF, MENU };

class GameOverWindow
{
private:
	sf::Texture gameOverTexture;
	sf::Sprite gameOverSprite;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Texture buttonTexture;
	sf::Sprite buttonSprite;
	GameOverState gameOverState;
public:
	GameOverWindow();
	GameOverWindow(const GameOverWindow&) = delete;
	GameOverWindow(GameOverWindow&&) = delete;
	GameOverWindow& operator=(const GameOverWindow&) = delete;
	GameOverWindow& operator=(GameOverWindow&&) = delete;
	~GameOverWindow() = default;

	GameOverState getState();
	void setState(GameOverState);
	void setPosition(float, float);
	void draw(sf::RenderWindow&);
};

