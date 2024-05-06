#include "button.h"

Button::Button(int start_x, int start_y, const sf::Texture& texture) {
	m_texture = texture;
	m_sprite.setTexture(m_texture);

	m_position.x = start_x;
	m_position.y = start_y;

	m_sprite.setPosition(m_position);

	m_rectangle = m_sprite.getGlobalBounds();

	m_coordinates.x_left = m_rectangle.left;
	m_coordinates.x_right = m_coordinates.x_left + m_rectangle.width;
	m_coordinates.y_up = m_rectangle.top;
	m_coordinates.y_down = m_coordinates.y_up + m_rectangle.height;
}

void Button::setPosition(int start_x, int start_y) {
	m_position.x = start_x;
	m_position.y = start_y;
}

void Button::setSprite(const sf::Sprite& sprite) {
	m_sprite = sprite;
}

void Button::setTexture(const sf::Texture& texture) {
	m_texture = texture;
}

sf::Vector2f Button::getPosition() {
	return m_position;
}

sf::Sprite Button::getSprite() {
	return m_sprite;
}

sf::Texture Button::getTexture() {
	return m_texture;
}

bool Button::isPushed(const sf::RenderWindow& window) const {
	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
	if (!(mouse_position.x > m_coordinates.x_left && mouse_position.x < m_coordinates.x_right &&
		mouse_position.y > m_coordinates.y_up && mouse_position.y < m_coordinates.y_down)) {
		return false;
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		return false;
	}
	return true;
}

void Button::draw(sf::RenderWindow& window) const {
	window.draw(m_sprite);
}