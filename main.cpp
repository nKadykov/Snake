#include <SFML/Graphics.hpp>
#include "snake.h"

const int snake_width = 30;
const int snake_height = 20;
const int snake_square = 25;
const int snake_length = 4;

int main() {

	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(snake_square * snake_width, snake_square * snake_height), "Snake");

	sf::Texture snake_texture;
	snake_texture.loadFromFile("E:/C/Visual Studio/Snake/resources/Snake.png");
	sf::Sprite snake_sprite(snake_texture);

	Snake snake(2, snake_width, snake_height, snake_square, snake_length, 1, 1, snake_sprite);

	snake.Start(window);

	return 0;
}