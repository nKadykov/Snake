#include <SFML/Graphics.hpp>
#include "snake.h"
#include "menu.h"
#include "gameoverwindow.h"

const int m_snake_square = 50;
const int m_snake_width = 1280 / m_snake_square;
const int m_snake_height = 720 / m_snake_square;
const int m_snake_length = 4;

enum class GameState {MENU, SNAKE, GAME_OVER};

int main() {

	srand(time(nullptr));

	sf::RenderWindow window(sf::VideoMode(m_snake_square * m_snake_width, m_snake_square * m_snake_height), "Snake");

	sf::Texture snake_texture;
	snake_texture.loadFromFile("resources/Snake.png");
	sf::Sprite m_snake_sprite(snake_texture);

	sf::Texture gameover_texture;
	gameover_texture.loadFromFile("resources/back1.jpg");
	sf::Sprite gameover_sprite(gameover_texture);

	Menu menu("resources/back1.jpg");
	menu.addButton(500, 200, "resources/button2.png");
	menu.addButton(500, 400, "resources/button3.png");

	GameOverWindow gameover_window;
	gameover_window.setPosition(300, 200);
	GameState game_state = GameState::MENU;
	Snake* pSnake = new Snake(2, m_snake_width, m_snake_height, m_snake_square, m_snake_length, 1, 1, m_snake_sprite);

	SnakeState m_snake_state = SnakeState::ON;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}

		if (pSnake) {
			m_snake_state = pSnake->getState();
		}
		MenuState m_menu_state = menu.getState();
		ButtonState m_button_state = menu.getButtonState();
		GameOverState gameover_state = gameover_window.getState();

		if (m_snake_state == SnakeState::LOSE && pSnake) {
			game_state = GameState::GAME_OVER;
			if (pSnake) {
				delete pSnake;
				pSnake = nullptr;
			}
		}
		else if (m_snake_state == SnakeState::MENU || gameover_state == GameOverState::MENU) {
			game_state = GameState::MENU;
			gameover_window.setState(GameOverState::ON);
			if (pSnake) {
				delete pSnake;
				pSnake = nullptr;
			}
			m_snake_state = SnakeState::ON;
		}

		else if (gameover_state == GameOverState::OFF || m_button_state == ButtonState::START_GAME) {
			game_state = GameState::SNAKE;
			menu.setButtonState(ButtonState::NONE);
			gameover_window.setState(GameOverState::ON);
			pSnake = new Snake(2, m_snake_width, m_snake_height, m_snake_square, m_snake_length, 1, 1, m_snake_sprite);
		}
		else if (m_button_state == ButtonState::CLOSE) {
			window.close();
		}

		switch (game_state) {
			case GameState::MENU:
				menu.draw(window);
				break;
			case GameState::SNAKE:
				pSnake->Start(window);
				break;
			case GameState::GAME_OVER:
				gameover_window.draw(window);
				break;
		}

		window.display();
	}
	if (pSnake) {
		delete pSnake;
		pSnake = nullptr;
	}
	return 0;
}