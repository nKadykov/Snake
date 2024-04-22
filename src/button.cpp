#include "button.h"

Button::Button(int buttonX, int buttonY, std::string filename) {
	if (!button_texture.loadFromFile(filename)) {
		exit(1);
	}
	button_sprite.setTexture(button_texture);
	button_sprite.setPosition(buttonX, buttonY);
}

void Button::setButtonPosition(int buttonX, int buttonY) {
	button_sprite.setPosition(buttonX, buttonY);
}

void Button::draw(sf::RenderWindow& window) {
	window.draw(button_sprite);
}