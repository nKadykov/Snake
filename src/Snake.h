#pragma once
#include <SFML/Graphics.hpp>
#include "target.h"
enum SnakeState {ON, MENU, LOSE};

class Snake
{
private:
	struct SnakePoint {
		int x;
		int y;
	};
	std::vector<SnakePoint> m_snake_vector;
	int m_snake_direction = 2;
	int m_snake_width = 30;
	int m_snake_height = 30;
	int m_snake_square;
	int m_snake_length = 4;
	SnakeState m_snake_state = SnakeState::ON;
	sf::Sprite m_snake_sprite;
public:
	Snake() = delete;
	Snake(int, int, int, int, int, int, int, sf::Sprite&);
	Snake(const Snake&) = delete;
	Snake(Snake&&) = delete;
	Snake& operator=(const Snake&) = delete;
	Snake& operator=(Snake&&) = delete;
	~Snake() = default;

	void setDirection(int);
	void setState(SnakeState);

	int getDirection() const;
	SnakeState getState() const;

	void Start(sf::RenderWindow&);
	void draw(sf::RenderWindow&) const;
};

