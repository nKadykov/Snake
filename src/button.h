#pragma once
#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::Texture m_button_texture;
	sf::Sprite m_button_sprite;
public:
	Button() = default;
	Button(int, int, std::string);
	Button(const Button&) = delete;
	Button(Button&&) = delete;
	Button& operator=(const Button&) = delete;
	Button& operator=(Button&&) = delete;
	~Button() = default;

	void setButtonPosition(int, int);
	void draw(sf::RenderWindow&);
};