#include "snake.h"
#include "target.h"

Snake::Snake(int direction, int width, int height, int square, int length, int point_x, int point_y, sf::Sprite& sprite) {
	snake_direction = direction;
	snake_width = width;
	snake_height = height;
	snake_square = square;
	snake_length = length;
	snake_state = SnakeState::ON;
	snake_vector.resize(100);
	for (int i = 0; i < snake_length; i++) {
		snake_vector.push_back(SnakePoint());
	}
	snake_sprite = sprite;
}

void Snake::setDirection(int direction) {
	snake_direction = direction;
}

int Snake::getDirection() const {
	return snake_direction;
}

SnakeState Snake::getState() const {
	return snake_state;
}

void Snake::Start(sf::RenderWindow& window) {

	sf::Texture target_texture;
	target_texture.loadFromFile("E:/C/Visual Studio/Snake/resources/Target.png");
	sf::Sprite target_sprite(target_texture);
	Target target(1, 1, 0.064, 0.066, target_sprite);
	TargetPoint target_point = target.getTargetPoint();

	sf::Texture texture;
	texture.loadFromFile("E:/C/Visual Studio/Snake/resources/Square.png");
	sf::Sprite title_sprite(texture);

	sf::Texture gameover_texture;
	gameover_texture.loadFromFile("E:/C/Visual Studio/Snake/resources/GameOver.png");
	sf::Sprite gameover_sprite(gameover_texture);
	gameover_sprite.setScale(2.7, 2.7);
	gameover_sprite.setPosition(0, 175);

	sf::Clock clock;
	float timer = 0;
	float delay = 0.1;

	int snake_direction = 2;

	while (window.isOpen()) {

		target_point = target.getTargetPoint();

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			snake_direction = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			snake_direction = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			snake_direction = 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			snake_direction = 0;
		}

		if (timer > delay && snake_state == ON) {

			timer = 0;

			target_point = target.getTargetPoint();

			for (int i = snake_length; i > 0; i--) {
				snake_vector[i].x = snake_vector[i - 1].x;
				snake_vector[i].y = snake_vector[i - 1].y;
			}

			switch (snake_direction) {
			case 0:
				snake_vector[0].y += 1;
				break;
			case 1:
				snake_vector[0].x -= 1;
				break;
			case 2:
				snake_vector[0].x += 1;
				break;
			case 3:
				snake_vector[0].y -= 1;
				break;
			}

			if (snake_vector[0].x > snake_width - 1) {
				snake_vector[0].x = 0;
			}
			if (snake_vector[0].x < 0) {
				snake_vector[0].x = snake_width;
			}
			if (snake_vector[0].y > snake_height - 1) {
				snake_vector[0].y = 0;
			}
			if (snake_vector[0].y < 0) {
				snake_vector[0].y = snake_height;
			}

			if ((snake_vector[0].x == target_point.x) && (snake_vector[0].y == target_point.y)) {
				snake_length++;
				target.setTargetPoint(rand() % snake_width, rand() % snake_height);
			}

			for (int i = 1; i < snake_length; i++) {
				if ((snake_vector[0].x == snake_vector[i].x) && (snake_vector[0].y == snake_vector[i].y)) {
					snake_state = SnakeState::OFF;
				}
			}
		}

		window.clear();

		for (int i = 0; i < snake_width; i++) {
			for (int j = 0; j < snake_height; j++) {
				title_sprite.setPosition(i * snake_square, j * snake_square);
				window.draw(title_sprite);
			}
		}

		for (int i = 0; i < snake_length; i++) {
			snake_sprite.setTextureRect(sf::IntRect(0, 0, snake_square, snake_square));
			if (snake_state == SnakeState::OFF && i == 1) {
				snake_sprite.setTextureRect(sf::IntRect(snake_direction * snake_square, snake_square * 2, snake_square, snake_square));
			}
			snake_sprite.setPosition(snake_vector[i].x * snake_square, snake_vector[i].y * snake_square);
			this->draw(window);
		}

		target.draw(window);

		if (snake_state == SnakeState::LOSE) {
			window.draw(gameover_sprite);
		}

		window.display();
	}

}

void Snake::draw(sf::RenderWindow& window) const {
	window.draw(snake_sprite);
}