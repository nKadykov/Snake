#pragma once
#include <SFML/Graphics.hpp>
#include "target.h"
enum SnakeState {ON, OFF, LOSE};

class Snake
{
private:
	struct SnakePoint {
		int x;
		int y;
	};
	std::vector<SnakePoint> snake_vector;
	int snake_direction = 2;
	int snake_width = 30;
	int snake_height = 30;
	int snake_square = 25;
	int snake_length = 4;
	SnakeState snake_state = SnakeState::ON;

	sf::Sprite snake_sprite;
public:
	Snake() = delete;
	Snake(int, int, int, int, int, int, int, sf::Sprite&);
	Snake(const Snake&) = delete;
	Snake(Snake&&) = delete;
	Snake& operator=(const Snake&) = delete;
	Snake& operator=(Snake&&) = delete;
	~Snake() = default;

	void setDirection(int);

	int getDirection() const;
	SnakeState getState() const;

	void Start(sf::RenderWindow&);
	void draw(sf::RenderWindow&);
};

