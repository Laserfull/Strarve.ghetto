#pragma once
#include "SFML/Graphics.hpp"


class Water: public sf::RectangleShape
{
private:
	Water();
	Water(const Water&);
public:
	Water(sf::Vector2f spawnPos);


};

