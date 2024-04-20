#include "target.h"

Target::Target(int point_x, int point_y, float width, float height, sf::Sprite& sprite) {
	target_point.x = point_x;
	target_point.y = point_y;
	target_width = width;
	target_height = height;
	target_sprite = sprite;
}

TargetPoint Target::getTargetPoint() const {
	return target_point;
}

void Target::setTargetPoint(int target_x, int target_y) {
	target_point.x = target_x;
	target_point.y = target_y;
}

void Target::draw(sf::RenderWindow& window) {
	target_sprite.setScale(target_width, target_height);
	target_sprite.setPosition(target_point.x * 25, target_point.y * 25);
	window.draw(target_sprite);
}