#include "Game.h"
#include "basicFuntions.h"
#include "Gold.h"

extern sf::Texture* goldTexture;

Gold::Gold(const sf::Vector2f& spawnPoint, const sf::Vector2i chunkPos) :RessourcePoint({RessourceName::name::Gold,10},spawnPoint, chunkPos,getRandom(3,7),2)
{
	this->setTexture(goldTexture);
}
