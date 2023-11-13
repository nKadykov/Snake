#include <SFML/Graphics.hpp>
#include "Snake.h"
using namespace sf;

void Game() {
	for (int i = number; i > 0; i--) {
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}

	switch (direction) {
	case 0:
		snake[0].y += 1;
		break;
	case 1:
		snake[0].x -= 1;
		break;
	case 2:
		snake[0].x += 1;
		break;
	case 3:
		snake[0].y -= 1;
		break;
	}

	if (snake[0].x > width) {
		snake[0].x = 0;
	}
	if (snake[0].x < 0) {
		snake[0].x = width;
	}
	if (snake[0].y > height) {
		snake[0].y = 0;
	}
	if (snake[0].y < 0) {
		snake[0].y = height;
	}

	if ((snake[0].x == target.x) && (snake[0].y == target.y)) {
		number++;

		target.x = rand() % width;
		target.y = rand() % height;
	}

	for (int i = 1; i < number; i++) {
		if ((snake[0].x == snake[i].x) && (snake[0].y == snake[i].y)) {
			game = false;
		}
	}

}