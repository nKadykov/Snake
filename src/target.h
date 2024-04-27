#pragma once
#include <SFML/Graphics.hpp>

struct TargetPoint {
	int x;
	int y;
};

class Target
{
private:
	TargetPoint m_target_point{ 1, 1 };
	float m_target_width = 0.062;
	float m_target_height = 0.065;
	float m_target_square;
	sf::Sprite m_target_sprite;
public:
	Target() = delete;
	Target(int, int, float, float, sf::Sprite&);
	Target(const Target&) = delete;
	Target(Target&&) = delete;
	Target& operator=(const Target&) = delete;
	Target& operator=(Target&&) = delete;
	~Target() = default;

	TargetPoint getTargetPoint() const;
	void setTargetPoint(int, int);
	void setTargetSquare(float);

	void draw(sf::RenderWindow&);
};

