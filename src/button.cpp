#include "button.h"

Button::Button(int buttonX, int buttonY, std::string filename) {
	if (!m_button_texture.loadFromFile(filename)) {
		exit(1);
	}
	m_button_sprite.setTexture(m_button_texture);
	m_button_sprite.setPosition(buttonX, buttonY);
}

void Button::setButtonPosition(int buttonX, int buttonY) {
	m_button_sprite.setPosition(buttonX, buttonY);
}

void Button::draw(sf::RenderWindow& window) {
	window.draw(m_button_sprite);
}