#pragma once
#include <vector>
#include <map>
#include <thread>

#include "App.h"

#include "Tree.h"
#include "Stone.h"
#include "Gold.h"

#include "Player.h"
#include "Water.h"
#include "Chunk.h"


struct Game : public App
{
private:
	float _deltaTime=0;

	Player* _player;
	
	
	
	void initGame();

	

	void checkRessourceCollection();

	void initRessources();

	void updateRessourcePoints();

	void findOnScreenElements();

	void sortRessources();

	void drawRessources();

	void updateChunksLoaded();
	
	std::thread* _chunkMakur;
	std::thread* _ressourceUpdateur;

	bool _askRessourceUpdateur;
	bool _endThread;
	
public:
	
	void play();
	std::map<std::pair<int, int>, Chunk*> _chunks;

	Game();
	~Game();



	const float& getDeltaTime();

	//get the main player
	Player& getPlayer();

	std::vector<Solid*>& getSolidsVector(const sf::Vector2i& chunk);

	std::vector<Water*>& getWaterSpots(const sf::Vector2i& chunk);
	


	//			chunk related

	void clearChunks();

	void createChunk(const sf::Vector2i& chunk); // create chunk assert if chunk already exists

	Chunk* getChunk(const sf::Vector2i& chunk); //returns the chunk requested assert if doesnt exist

	bool isChunk(const sf::Vector2i& chunk); //returns true if the chunk exists

	sf::Vector2i getChunkFromPos(const sf::Vector2f& position);	//returns the chunk the position sent should be at

	sf::Vector2i getChunkSize();
};

