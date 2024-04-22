#pragma once
#include <SFML/Graphics.hpp>

enum class GameOverState { ON, OFF, MENU };

class GameOverWindow
{
private:
	sf::Texture game_over_texture;
	sf::Sprite game_over_sprite;
	sf::Texture background_texture;
	sf::Sprite background_sprite;
	sf::Texture button_texture;
	sf::Sprite button_sprite;
	GameOverState game_over_state;
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

