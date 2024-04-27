#include "target.h"

Target::Target(int point_x, int point_y, float width, float height, sf::Sprite& sprite) {
	m_target_point.x = point_x;
	m_target_point.y = point_y;
	m_target_width = width;
	m_target_height = height;
	m_target_sprite = sprite;
}

TargetPoint Target::getTargetPoint() const {
	return m_target_point;
}

void Target::setTargetPoint(int target_x, int target_y) {
	m_target_point.x = target_x;
	m_target_point.y = target_y;
}

void Target::setTargetSquare(float square) {
	m_target_square = square;
}

void Target::draw(sf::RenderWindow& window) {
	m_target_sprite.setScale(m_target_width * m_target_square / 25, m_target_width * m_target_square / 25);
	m_target_sprite.setPosition(m_target_point.x * m_target_square, m_target_point.y * m_target_square);
	window.draw(m_target_sprite);
}