#include "gameoverwindow.h"

GameOverWindow::GameOverWindow() {
	game_over_state = GameOverState::ON;
	game_over_texture.loadFromFile("resources/GameOver.jpg");
	game_over_sprite.setTexture(game_over_texture);
	background_texture.loadFromFile("resources/back1.jpg");
	background_sprite.setTexture(background_texture);
	button_texture.loadFromFile("resources/Again.png");
	button_sprite.setTexture(button_texture);
}

void GameOverWindow::setPosition(float positionX, float positionY) {
	game_over_sprite.setPosition(positionX, positionY);
	button_sprite.setPosition(230, 300);
}

GameOverState GameOverWindow::getState() {
	return game_over_state;
}

void GameOverWindow::setState(GameOverState state) {
	game_over_state = state;
}

void GameOverWindow::draw(sf::RenderWindow& window) {
	game_over_state = GameOverState::ON;
	window.clear();
	if ((sf::Mouse::getPosition(window).x < 900) && (sf::Mouse::getPosition(window).x > 400) && (sf::Mouse::getPosition(window).y > 400) && (sf::Mouse::getPosition(window).y < 500)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			game_over_state = GameOverState::OFF;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
		game_over_state = GameOverState::MENU;
	}
	window.draw(background_sprite);
	window.draw(game_over_sprite);
	window.draw(button_sprite);
}