#pragma once
#include <SFML/Graphics.hpp>

enum class GameOverState { ON, OFF, MENU };

class GameOverWindow
{
private:
	sf::Texture m_game_over_texture;
	sf::Sprite m_game_over_sprite;
	sf::Texture m_background_texture;
	sf::Sprite m_background_sprite;
	sf::Texture m_button_texture;
	sf::Sprite m_button_sprite;
	GameOverState m_game_over_state;
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

