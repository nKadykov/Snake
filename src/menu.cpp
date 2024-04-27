#include "menu.h"

Menu::Menu() {
	m_menu_state = MenuState::ON;
	m_button_state = ButtonState::NONE;
	m_menu_texture.loadFromFile("resources/back1.jpg");
	m_menu_sprite.setTexture(m_menu_texture);
}

Menu::Menu(std::string filename) {
	m_menu_state = MenuState::OFF;
	m_button_state = ButtonState::NONE;
	m_menu_texture.loadFromFile(filename);
	m_menu_sprite.setTexture(m_menu_texture);
}

Menu::~Menu() {
	for (auto it = m_button_vector.begin(); it != m_button_vector.end(); it++) {
		delete* it;
	}
}

void Menu::addButton(int buttonX, int buttonY, std::string filename) {
	Button* new_button = new Button(buttonX, buttonY, filename);
	m_button_vector.push_back(new_button);
}

ButtonState Menu::getButtonState() const {
	return m_button_state;
}

MenuState Menu::getState() const {
	return m_menu_state;
}

void Menu::setButtonState(ButtonState state) {
	m_button_state = state;
}

void Menu::setState(MenuState state) {
	m_menu_state = state;
}

void Menu::draw(sf::RenderWindow& window) {
	window.clear();
	m_button_state = NONE;
	if ((sf::Mouse::getPosition(window).x < 700) && (sf::Mouse::getPosition(window).x > 500) && (sf::Mouse::getPosition(window).y > 200) && (sf::Mouse::getPosition(window).y < 300)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			m_button_state = ButtonState::START_GAME;
		}
	}
	if ((sf::Mouse::getPosition(window).x < 700) && (sf::Mouse::getPosition(window).x > 500) && (sf::Mouse::getPosition(window).y > 400) && (sf::Mouse::getPosition(window).y < 500)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			m_button_state = ButtonState::CLOSE;
		}
	}
	window.draw(m_menu_sprite);
	for (auto it = m_button_vector.begin(); it != m_button_vector.end(); it++) {
		(*it)->draw(window);
	}
}