#include <SFML/Graphics.hpp>
#include "snake.h"
#include "menu.h"
#include "gameoverwindow.h"

const int snake_square = 50;
const int snake_width = 1280 / snake_square;
const int snake_height = 720 / snake_square;
const int snake_length = 4;

enum class GameState {MENU, SNAKE, GAME_OVER};

int main() {

	srand(time(nullptr));

	sf::RenderWindow window(sf::VideoMode(snake_square * snake_width, snake_square * snake_height), "Snake");

	sf::Texture snake_texture;
	snake_texture.loadFromFile("E:/C/Visual Studio/Snake/resources/Snake.png");
	sf::Sprite snake_sprite(snake_texture);

	sf::Texture gameover_texture;
	gameover_texture.loadFromFile("resources/back1.jpg");
	sf::Sprite gameover_sprite(gameover_texture);

	Menu menu("resources/back1.jpg");
	menu.addButton(500, 200, "resources/button2.png");
	menu.addButton(500, 400, "resources/button3.png");

	GameOverWindow gameover_window;
	gameover_window.setPosition(300, 200);
	GameState game_state = GameState::MENU;
	Snake* pSnake = new Snake(2, snake_width, snake_height, snake_square, snake_length, 1, 1, snake_sprite);

	SnakeState snake_state = SnakeState::ON;

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
			snake_state = pSnake->getState();
		}
		MenuState menu_state = menu.getState();
		ButtonState button_state = menu.getButtonState();
		GameOverState gameover_state = gameover_window.getState();

		if (snake_state == SnakeState::LOSE && pSnake) {
			game_state = GameState::GAME_OVER;
			if (pSnake) {
				delete pSnake;
				pSnake = nullptr;
			}
		}
		else if (snake_state == SnakeState::MENU || gameover_state == GameOverState::MENU) {
			game_state = GameState::MENU;
			gameover_window.setState(GameOverState::ON);
			if (pSnake) {
				delete pSnake;
				pSnake = nullptr;
			}
			snake_state = SnakeState::ON;
		}

		else if (gameover_state == GameOverState::OFF || button_state == ButtonState::START_GAME) {
			game_state = GameState::SNAKE;
			menu.setButtonState(ButtonState::NONE);
			gameover_window.setState(GameOverState::ON);
			pSnake = new Snake(2, snake_width, snake_height, snake_square, snake_length, 1, 1, snake_sprite);
		}
		else if (button_state == ButtonState::CLOSE) {
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