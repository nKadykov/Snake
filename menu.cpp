#include "menu.h"

Menu::Menu() {
	menu_state = MenuState::ON;
	button_state = ButtonState::NONE;
	menu_texture.loadFromFile("resources/back1.jpg");
	menu_sprite.setTexture(menu_texture);
}

Menu::Menu(std::string filename) {
	menu_state = MenuState::OFF;
	button_state = ButtonState::NONE;
	menu_texture.loadFromFile(filename);
	menu_sprite.setTexture(menu_texture);
}

Menu::~Menu() {
	for (auto it = button_vector.begin(); it != button_vector.end(); it++) {
		delete* it;
	}
}

void Menu::addButton(int buttonX, int buttonY, std::string filename) {
	Button* newButton = new Button(buttonX, buttonY, filename);
	button_vector.push_back(newButton);
}

ButtonState Menu::getButtonState() const {
	return button_state;
}

MenuState Menu::getState() const {
	return menu_state;
}

void Menu::setButtonState(ButtonState state) {
	button_state = state;
}

void Menu::setState(MenuState state) {
	menu_state = state;
}

void Menu::draw(sf::RenderWindow& window) {
	window.clear();
	button_state = NONE;
	if ((sf::Mouse::getPosition(window).x < 700) && (sf::Mouse::getPosition(window).x > 500) && (sf::Mouse::getPosition(window).y > 200) && (sf::Mouse::getPosition(window).y < 300)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			button_state = ButtonState::START_GAME;
		}
	}
	if ((sf::Mouse::getPosition(window).x < 700) && (sf::Mouse::getPosition(window).x > 500) && (sf::Mouse::getPosition(window).y > 400) && (sf::Mouse::getPosition(window).y < 500)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			button_state = ButtonState::CLOSE;
		}
	}
	window.draw(menu_sprite);
	for (auto it = button_vector.begin(); it != button_vector.end(); it++) {
		(*it)->draw(window);
	}
}