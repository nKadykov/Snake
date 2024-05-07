#include <SFML/Graphics.hpp>
#include "snake.h"
#include "menu.h"
#include "gameoverwindow.h"

const int SQUARE = 150;
const int WIDTH = 1280 / SQUARE;
const int HEIGHT = 720 / SQUARE;
const int LENGTH = 4;

enum class GameState {MENU, SNAKE, GAME_OVER};

int main() {

	srand(time(nullptr));

	sf::RenderWindow window(sf::VideoMode(SQUARE * WIDTH, SQUARE * HEIGHT), "Snake");

	sf::Texture snake_texture;
	snake_texture.loadFromFile("resources/Snake.png");
	sf::Sprite snake_sprite(snake_texture);

	sf::Texture gameover_texture;
	gameover_texture.loadFromFile("resources/back1.jpg");
	sf::Sprite gameover_sprite(gameover_texture);

	sf::Texture button_texture_1;
	sf::Texture button_texture_2;
	button_texture_1.loadFromFile("resources/button2.png");
	button_texture_2.loadFromFile("resources/button3.png");

	Menu menu("resources/back1.jpg");
	menu.addButton(500, 200, button_texture_1);
	menu.addButton(500, 400, button_texture_2);

	GameOverWindow gameover_window;
	gameover_window.setPosition(300, 150);
	GameState game_state = GameState::MENU;
	Snake* pSnake = new Snake(2, WIDTH, HEIGHT, SQUARE, LENGTH, 1, 1, snake_sprite);

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
			pSnake = new Snake(2, WIDTH, HEIGHT, SQUARE, LENGTH, 1, 1, snake_sprite);
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