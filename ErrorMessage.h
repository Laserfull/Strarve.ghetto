#pragma once
#include <SFML/Graphics.hpp>

class ErrorMessage : public sf::RectangleShape
{
	sf::Text _text;

	float _lifeTime;

public:
	ErrorMessage(const char* text);
	~ErrorMessage();

	void changeText(const char* text);

	void update(const float& deltaTime);

	bool isDead()const;

	void draw(sf::RenderWindow* window,const sf::Vector2f& position);				///updates its position and draws the box and text
};

