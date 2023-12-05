#include "Chunk.h"
#include "Game.h"
#include "basicFuntions.h"

extern Game* gameInfo;



Chunk::Chunk(sf::Vector2i chunk)
{
	_chunkPos = chunk;
}

Chunk::~Chunk()
{
	for (auto tree : treeSpots) {
		delete tree;
	}
	treeSpots.clear();

	for (auto tree : stoneSpots) {
		delete tree;
	}
	stoneSpots.clear();

	for (auto tree : goldSpots) {
		delete tree;
	}
	goldSpots.clear();

	for (auto tree : waterSpots) {
		delete tree;
	}
	waterSpots.clear();

	solids.clear();

}

void Chunk::init()
{

	sf::Vector2f ChunkSize(gameInfo->getChunkSize());

	sf::Vector2f ChunkPos(int(gameInfo->getChunkSize().x) * int(_chunkPos.x), int(gameInfo->getChunkSize().y) * int(_chunkPos.y));

#define randomPos sf::Vector2f{ChunkSize.x + getRandom(0, ChunkSize.x-1), ChunkSize.y + getRandom(0, ChunkSize.y-1)}
#define playerBox gameInfo->getPlayer().getGlobalBounds()
	int randomNumber(getRandom(3,4));

	
	for (int i = 0; i < randomNumber; i++) {
		Tree* tempTreePtr = new Tree(ChunkPos + randomPos,_chunkPos);

		if (tempTreePtr->getGlobalBounds().intersects(playerBox)) { //reallocate the pos if collide with player
			do {
				tempTreePtr->setPosition(ChunkPos + randomPos);
			} while (tempTreePtr->getGlobalBounds().intersects(playerBox));
		}
		treeSpots.push_back(tempTreePtr);
	}

	randomNumber = (getRandom(0, 1));
	for (int i = 0; i < randomNumber; i++) {
		Stone* tempStonePtr = new Stone(ChunkPos + randomPos, _chunkPos);

		if (tempStonePtr->getGlobalBounds().intersects(playerBox)) { //reallocate the pos if collide with player
			do {
				tempStonePtr->setPosition(ChunkPos + randomPos);
			} while (tempStonePtr->getGlobalBounds().intersects(playerBox));
		}
		stoneSpots.push_back(tempStonePtr);
	}

	randomNumber = (getRandom(0, 5));

	if (randomNumber == 1) {
		Gold* tempGoldPtr = new Gold(ChunkPos + randomPos, _chunkPos);

		if (tempGoldPtr->getGlobalBounds().intersects(playerBox)) { //reallocate the pos if collide with player
			do {
				tempGoldPtr->setPosition(ChunkPos + randomPos);
			} while (tempGoldPtr->getGlobalBounds().intersects(playerBox));
		}
		goldSpots.push_back(tempGoldPtr);
	}


}

void Chunk::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < waterSpots.size();i++) {
		window->draw(*waterSpots[i]);
	}
	for (int i = 0; i < goldSpots.size();i++) {
		window->draw(*goldSpots[i]);
	}
	for (int i = 0; i < stoneSpots.size(); i++) {
		window->draw(*stoneSpots[i]);
	}
	for (int i = 0; i < treeSpots.size();i++) {
		window->draw(*treeSpots[i]);
	}
}

void Chunk::updateRessources()
{
	for (int i = 0; i < goldSpots.size(); i++) {
		goldSpots[i]->updateRessourcePoint();
	}
	for (int i = 0; i < stoneSpots.size(); i++) {
		stoneSpots[i]->updateRessourcePoint();
	}
	for (int i = 0; i < treeSpots.size(); i++) {
		treeSpots[i]->updateRessourcePoint();
	}
}

void Chunk::checkRessourceCollection(Player* player)
{

	for (int i = 0; i < treeSpots.size(); i++)
	{
		if (player->isAttackingObject(treeSpots[i])) {// if tree is attacked
			player->addToInventory(treeSpots[i]->gatherRessource(player->getRessourcePower()));//get the ressources
		}
	}
	for (int i = 0; i < stoneSpots.size(); i++)
	{
		if (player->isAttackingObject(stoneSpots[i])) {// if stone is attacked
			player->addToInventory(stoneSpots[i]->gatherRessource(player->getRessourcePower()));//get the ressources
		}
	}
	for (int i = 0; i < goldSpots.size();i++)
	{
		if (player->isAttackingObject(goldSpots[i])) {// if gold is attacked
			player->addToInventory(goldSpots[i]->gatherRessource(player->getRessourcePower()));//get the ressources
		}
	}
}

const sf::Vector2i& Chunk::getChunkPos() const
{
	return _chunkPos;
}
