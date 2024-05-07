#include "snake.h"
#include "target.h"
#include <SFML/Audio.hpp>

Snake::Snake(int direction, int width, int height, int square, int length, int point_x, int point_y, sf::Sprite& sprite) {
	m_snake_direction = direction;
	m_snake_width = width;
	m_snake_height = height;
	m_snake_square = square;
	m_snake_length = length;
	m_snake_state = SnakeState::ON;
	for (int i = 0; i < m_snake_length; i++) {
		m_snake_vector.push_back(SnakePoint());
	}
	m_snake_sprite = sprite;
}

void Snake::setDirection(int direction) {
	m_snake_direction = direction;
}

void Snake::setState(SnakeState state) {
	m_snake_state = state;
}

int Snake::getDirection() const {
	return m_snake_direction;
}

SnakeState Snake::getState() const {
	return m_snake_state;
}

void Snake::Start(sf::RenderWindow& window) {

	sf::Music music;
	music.openFromFile("resources/back1.mp3");
	music.play();


	sf::Texture target_texture;
	target_texture.loadFromFile("resources/Target.png");
	sf::Sprite target_sprite(target_texture);
	target_sprite.setScale(m_snake_square / 25, m_snake_square / 25);
	Target target(1, 1, 0.065, 0.067, target_sprite);
	target.setTargetSquare(m_snake_square);
	TargetPoint target_point = target.getTargetPoint();

	sf::Texture texture;
	texture.loadFromFile("resources/Square.png");
	sf::Sprite title_sprite(texture);

	sf::Texture gameover_texture;
	gameover_texture.loadFromFile("resources/GameOver.png");
	sf::Sprite gameover_sprite(gameover_texture);
	gameover_sprite.setScale(2.7, 2.7);
	gameover_sprite.setPosition(0, 175);

	sf::Clock clock;
	float timer = 0;
	float delay = 0.2;

	while (window.isOpen() && m_snake_state == SnakeState::ON) {

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
			m_snake_state = SnakeState::MENU;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			m_snake_direction = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			m_snake_direction = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			m_snake_direction = 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			m_snake_direction = 0;
		}

		if (timer > delay && m_snake_state == ON) {

			timer = 0;

			target_point = target.getTargetPoint();

			for (int i = m_snake_length - 1; i > 0; i--) {
				m_snake_vector[i].x = m_snake_vector[i - 1].x;
				m_snake_vector[i].y = m_snake_vector[i - 1].y;
			}

			switch (m_snake_direction) {
			case 0:
				m_snake_vector[0].y += 1;
				break;
			case 1:
				m_snake_vector[0].x -= 1;
				break;
			case 2:
				m_snake_vector[0].x += 1;
				break;
			case 3:
				m_snake_vector[0].y -= 1;
				break;
			}

			if (m_snake_vector[0].x > m_snake_width - 1) {
				m_snake_vector[0].x = 0;
			}
			if (m_snake_vector[0].x < 0) {
				m_snake_vector[0].x = m_snake_width;
			}
			if (m_snake_vector[0].y > m_snake_height - 1) {
				m_snake_vector[0].y = 0;
			}
			if (m_snake_vector[0].y < 0) {
				m_snake_vector[0].y = m_snake_height;
			}

			if ((m_snake_vector[0].x == target_point.x) && (m_snake_vector[0].y == target_point.y)) {
				int target_x = rand() % m_snake_width;
				int target_y = rand() % m_snake_width;
				for (int i = 0; i < m_snake_length; i++) {
					if (target_x == m_snake_vector[i].x && target_y == m_snake_vector[i].y) {
						target_x = rand() % m_snake_width;
						target_y = rand() % m_snake_width;
						i = 0;
					}
				}
				m_snake_length++;
				int new_x = m_snake_vector.back().x;
				int new_y = m_snake_vector.back().y;
				SnakePoint new_point{ new_x, new_y };
				m_snake_vector.push_back(new_point);
				target.setTargetPoint(rand() % m_snake_width, rand() % m_snake_height);
			}

			for (int i = 2; i < m_snake_length; i++) {
				if ((m_snake_vector[0].x == m_snake_vector[i].x) && (m_snake_vector[0].y == m_snake_vector[i].y)) {
					m_snake_state = SnakeState::LOSE;
				}
			}
		}

		window.clear();

		for (int i = 0; i < m_snake_width; i++) {
			for (int j = 0; j < m_snake_height; j++) {
				title_sprite.setScale(static_cast<float>(m_snake_square) / 25.0, static_cast<float>(m_snake_square) / 25.0);
				title_sprite.setPosition(i * m_snake_square, j * m_snake_square);
				window.draw(title_sprite);
			}
		}

		for (int i = 0; i < m_snake_length; i++) {
			m_snake_sprite.setScale(static_cast<float>(m_snake_square) / (25.0 * 7.0), static_cast<float>(m_snake_square) / (25.0 * 7.3));
			m_snake_sprite.setPosition(m_snake_vector[i].x * m_snake_square, m_snake_vector[i].y * m_snake_square);
			this->draw(window);
		}

		target.draw(window);

		window.display();
	}

}

void Snake::draw(sf::RenderWindow& window) const {
	window.draw(m_snake_sprite);
}