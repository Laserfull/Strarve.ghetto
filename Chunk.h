#pragma once
#include <vector>

#include "Tree.h"
#include "Stone.h"
#include "Gold.h"
#include "Solid.h"
#include "Water.h"
#include "Player.h"

class Chunk
{
	Chunk();
	sf::Vector2i _chunkPos;
public:
	std::vector<Tree*> treeSpots;
	std::vector<Stone*> stoneSpots;
	std::vector<Gold*> goldSpots;
	std::vector<Water*> waterSpots;

	std::vector<Solid*> solids;

	Chunk(sf::Vector2i chunk);
	~Chunk();

	void init();
	void draw(sf::RenderWindow* window);

	void updateRessources();

	void checkRessourceCollection(Player* player);

	const sf::Vector2i& getChunkPos() const;
};


