#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "button.h"

enum class MenuState { ON, OFF };
enum ButtonState { NONE, START_GAME, CLOSE };

class Menu
{
private:
	std::vector<Button*> button_vector;
	sf::Texture menu_texture;
	sf::Sprite menu_sprite;
	ButtonState button_state;
	MenuState menu_state;
public:
	Menu();
	Menu(std::string);
	Menu(const Menu&) = delete;
	Menu(Menu&&) = delete;
	Menu& operator=(const Menu&) = delete;
	Menu& operator=(Menu&&) = delete;
	~Menu();

	ButtonState getButtonState() const;
	MenuState getState() const;
	void setButtonState(ButtonState);
	void setState(MenuState);
	void addButton(int, int, std::string);
	void draw(sf::RenderWindow&);
};