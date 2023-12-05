#include "Game.h"
#include "basicFuntions.h"
#include "Stone.h"

extern sf::Texture* stoneTexture;

Stone::Stone(const sf::Vector2f& spawnPoint, const sf::Vector2i chunkPos) :RessourcePoint({RessourceName::name::Stone,15},spawnPoint, chunkPos, getRandom(5,9),1)
{
	this->setTexture(stoneTexture);
}
