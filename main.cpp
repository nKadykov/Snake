#include <SFML/Graphics.hpp>
#include "Snake.h"

using namespace sf;


int direction = 2;
bool game = true;

const int width = 30;
const int height = 20;
int square = 25;

int number = 4;

Snake snake[600];
Target target;

int main() {

	srand(time(NULL));

	RenderWindow window(VideoMode(square * width, square * height), "Snake");

	Texture texture;
	texture.loadFromFile("E:/resources/Square.png");
	Sprite title_sprite(texture);

	Texture snake_texture;
	snake_texture.loadFromFile("E:/resources/Snake.png");
	Sprite snake_sprite(snake_texture);

	Texture target_texture;
	target_texture.loadFromFile("E:/resources/Target.png");
	Sprite target_sprite(target_texture);

	Texture gameover_texture;
	gameover_texture.loadFromFile("E:/resources/GameOver.png");
	Sprite gameover_sprite(gameover_texture);
	gameover_sprite.setPosition(0, 150);

	target.x = 1;
	target.y = 1;

	Clock clock;
	float timer = 0;
	float delay = 0.1;

	while (window.isOpen()) {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			direction = 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			direction = 2;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			direction = 3;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			direction = 0;
		}

		if (timer > delay && game) {
			timer = 0;
			Game();
		}

		window.clear();

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				title_sprite.setPosition(i * square, j * square);
				window.draw(title_sprite);
			}
		}

		for (int i = 0; i < number; i++) {
			snake_sprite.setTextureRect(IntRect(0, 0, square, square));
		
			if (!game && i == 1) {
				snake_sprite.setTextureRect(IntRect(direction * square, square * 2, square, square));
			}
			snake_sprite.setPosition(snake[i].x * square, snake[i].y * square);
			window.draw(snake_sprite);

		}

		target_sprite.setPosition(target.x * 1, target.y * 1);
		window.draw(target_sprite);

		if (!game) {
			window.draw(gameover_sprite);
		}

		window.display();
	}

	return 0;
}