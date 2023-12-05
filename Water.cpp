#include "Water.h"
#include "Game.h"


extern Game* gameInfo;

Water::Water(sf::Vector2f spawnPos)
{
	this->setPosition(spawnPos);

	this->setSize({gameInfo->getUnit().x * 500,gameInfo->getUnit().y * 500});

	this->setFillColor(sf::Color::Cyan);
}
