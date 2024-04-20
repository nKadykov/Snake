#include "gameoverwindow.h"

GameOverWindow::GameOverWindow() {
	gameOverState = GameOverState::ON;
	gameOverTexture.loadFromFile("resources/GameOver.jpg");
	gameOverSprite.setTexture(gameOverTexture);
	backgroundTexture.loadFromFile("resources/back1.jpg");
	backgroundSprite.setTexture(backgroundTexture);
	buttonTexture.loadFromFile("resources/Again.png");
	buttonSprite.setTexture(buttonTexture);
}

void GameOverWindow::setPosition(float positionX, float positionY) {
	gameOverSprite.setPosition(positionX, positionY);
	buttonSprite.setPosition(230, 300);
}

GameOverState GameOverWindow::getState() {
	return gameOverState;
}

void GameOverWindow::setState(GameOverState state) {
	gameOverState = state;
}

void GameOverWindow::draw(sf::RenderWindow& window) {
	gameOverState = GameOverState::ON;
	window.clear();
	if ((sf::Mouse::getPosition(window).x < 900) && (sf::Mouse::getPosition(window).x > 400) && (sf::Mouse::getPosition(window).y > 400) && (sf::Mouse::getPosition(window).y < 500)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			gameOverState = GameOverState::OFF;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
		gameOverState = GameOverState::MENU;
	}
	window.draw(backgroundSprite);
	window.draw(gameOverSprite);
	window.draw(buttonSprite);
}