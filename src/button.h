#pragma once
#include <SFML/Graphics.hpp>

struct RectangleCoordinate {
	float x_left;
	float x_right;
	float y_up;
	float y_down;
};

class Button
{
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	sf::FloatRect m_rectangle;
	RectangleCoordinate m_coordinates;
public:
	Button() = delete;
	Button(int, int, const sf::Texture&);
	Button(const Button&) = delete;
	Button(Button&&) = delete;
	Button& operator=(const Button&) = delete;
	Button& operator=(Button&&) = delete;
	~Button() = default;

	void setPosition(int, int);
	void setTexture(const sf::Texture&);
	void setSprite(const sf::Sprite&);

	sf::Vector2f getPosition();
	sf::Texture getTexture();
	sf::Sprite getSprite();

	bool isPushed(const sf::RenderWindow&) const;

	void draw(sf::RenderWindow&) const;
};