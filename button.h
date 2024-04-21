#pragma once
#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::Texture button_texture;
	sf::Sprite button_sprite;
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