#include <SFML/Graphics.hpp>
#include "basicFuntions.h"
#include "Game.h"
#include "Tree.h"

extern sf::Texture* treeTexture;

Tree::Tree(const sf::Vector2f& spawnPoint, const sf::Vector2i& chunkPos) :RessourcePoint(Item(RessourceName::name::Wood, 20), spawnPoint, chunkPos, getRandom(6, 11), 0)
{
	this->setTexture(treeTexture);
}

