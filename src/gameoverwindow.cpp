#include "gameoverwindow.h"

GameOverWindow::GameOverWindow() {
	m_game_over_state = GameOverState::ON;
	m_game_over_texture.loadFromFile("resources/GameOver.jpg");
	m_game_over_sprite.setTexture(m_game_over_texture);
	m_background_texture.loadFromFile("resources/back1.jpg");
	m_background_sprite.setTexture(m_background_texture);
	m_button_texture.loadFromFile("resources/Again.png");
	m_button_sprite.setTexture(m_button_texture);
}

void GameOverWindow::setPosition(float positionX, float positionY) {
	m_game_over_sprite.setPosition(positionX, positionY);
	m_button_sprite.setPosition(230, 300);
}

GameOverState GameOverWindow::getState() {
	return m_game_over_state;
}

void GameOverWindow::setState(GameOverState state) {
	m_game_over_state = state;
}

void GameOverWindow::draw(sf::RenderWindow& window) {
	m_game_over_state = GameOverState::ON;
	window.clear();
	if ((sf::Mouse::getPosition(window).x < 900) && (sf::Mouse::getPosition(window).x > 400) && (sf::Mouse::getPosition(window).y > 400) && (sf::Mouse::getPosition(window).y < 500)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			m_game_over_state = GameOverState::OFF;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
		m_game_over_state = GameOverState::MENU;
	}
	window.draw(m_background_sprite);
	window.draw(m_game_over_sprite);
	window.draw(m_button_sprite);
}