#include "button.h"

Button::Button(int buttonX, int buttonY, std::string filename) {
	if (!buttonTexture.loadFromFile(filename)) {
		exit(1);
	}
	buttonSprite.setTexture(buttonTexture);
	buttonSprite.setPosition(buttonX, buttonY);
}

void Button::setButtonPosition(int buttonX, int buttonY) {
	buttonSprite.setPosition(buttonX, buttonY);
}

void Button::draw(sf::RenderWindow& window) {
	window.draw(buttonSprite);
}