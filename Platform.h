#pragma once
#include <SFML/Graphics.hpp>


class Platform
{
private:
	sf::Shape* _platformer;
public:
	Platform(sf::Shape* hitbox);

	virtual sf::Vector2f& getPlatformMove(const sf::Vector2f& movement);

};
