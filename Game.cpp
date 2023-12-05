#include <assert.h>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


#include "basicFuntions.h"

#include "RessourcePoint.h"
#include "Item.h"
#include "ItemSlot.h"


#include "Game.h"

#include "Slime.h"



sf::Texture* playerTexture;
sf::Texture* handsTexture;

sf::Texture* treeTexture;
sf::Texture* stoneTexture;
sf::Texture* goldTexture;

sf::Texture* handItemsTexture;
sf::Texture* armorTexture;

sf::Texture* itemHolderTexture;
sf::Texture* itemIconTexture;
sf::Texture* slimeTexture;

sf::Texture* crateTexture;
sf::Texture* errorTexture;

sf::Texture* buildingTexture;


sf::Font* gameFont;


Game* gameInfo;


namespace RichardVigneux
{

	struct Man {
	public:
		int coolness;

		long long int cock;
	};

	class pussy {

	};

	class BabyMaker : public pussy {

	};

	class Woman : public BabyMaker {
	private:
		double personality;

	public:
		double boob;
		int ass;


		Woman(Man& sex);

		void sex(const Man& jerk);

	};
}

Game::Game() :App()
{

	gameInfo = this;

	this->initGame();
}

Game::~Game()
{
	_endThread = true;

	//destroy threads
	if(_chunkMakur != nullptr)
	{
		
		_chunkMakur->join();
		delete _chunkMakur;
		_chunkMakur = nullptr;
	}

	if(_ressourceUpdateur != nullptr)
	{
		_ressourceUpdateur->join();
		delete _ressourceUpdateur;
	}

	_askRessourceUpdateur = false;
	_ressourceUpdateur = nullptr;

	this->clearChunks();


}


void Game::initGame()
{
	_endThread = false;
				//------------------------------//
				//		initialize fonts		//
				//------------------------------//

	gameFont = new sf::Font;
	gameFont->loadFromFile("./Fonts/static/SignikaNegative-Regular.ttf");


				//------------------------------//
				//		initialize textures		//
				//------------------------------//

	playerTexture = new sf::Texture;
	playerTexture->loadFromFile("./Textures/Player.png");

	handsTexture = new sf::Texture;
	handsTexture->loadFromFile("./Textures/PlayerHands.png");

	treeTexture = new sf::Texture;
	treeTexture->loadFromFile("./Textures/Tree.png");

	stoneTexture = new sf::Texture;
	stoneTexture->loadFromFile("./Textures/Stone.png");

	goldTexture = new sf::Texture;
	goldTexture->loadFromFile("./Textures/Gold.png");
	
	armorTexture = new sf::Texture;
	armorTexture->loadFromFile("./Textures/Armor.png");

	itemHolderTexture = new sf::Texture;
	itemHolderTexture->loadFromFile("./Textures/ItemHolder.png");

	itemIconTexture = new sf::Texture;
	itemIconTexture->loadFromFile("./Textures/ItemsIcon.png");

	handItemsTexture = new sf::Texture;
	handItemsTexture->loadFromFile("./Textures/HandItems.png");

	crateTexture = new sf::Texture;
	crateTexture->loadFromFile("./Textures/Crate.png");
	
	errorTexture = new sf::Texture;
	errorTexture->loadFromFile("./Textures/ErrorMessage.png");

	buildingTexture = new sf::Texture;
	buildingTexture->loadFromFile("./Textures/Building.png");

				//------------------------------//
				//				play			//
				//------------------------------//	

	slimeTexture = new sf::Texture;			//to delete later
	slimeTexture->loadFromFile("./Textures/Slime.png");

			//init player

	_player = new Player;
	_window->setView(sf::View(_player->getPosition(), _screenResolution)); //get visible screen

	this->initRessources();//initialize ressources

	//_chunkThread = new std::thread(&Game::updateChunksLoaded, this); //start updating chunks on another thread
}

void Game::play()
{
	_askRessourceUpdateur = false;

	_chunkMakur = new std::thread(&Game::updateChunksLoaded, this);							//thread handling chunks
	_ressourceUpdateur = new std::thread(&Game::updateRessourcePoints, this);				//thread handling ressources within chunks
	


	Tree bob(sf::Vector2f(0, 0),{0,0});
	Stone bobette({ 500,0 }, { 0,0 });
	Gold boobas({ 1000,0 }, { 0,0 });

	
	_window->setFramerateLimit(144);

	
	Slime slime({ 100,100 });

	slime.setAnimation(0);

	sf::Clock deltaClock;

	float tickClock =0;			//ticks the game tick clock every 5 seconds


	while (_window->isOpen()) {
		while (_window->pollEvent(*_event)) {

			if (_event->Closed()) {
				_window->close();
				exit(0);
			}
			if (_event->MouseButtonPressed) {
				if (_event->mouseButton.button == _mouse->Left) {
					_player->onMouseLeftPressed(this->getMousePosition());
				}
				else if(_event->mouseButton.button == _mouse->Right){
					_player->onMouseRightPressed(this->getMousePosition());
				}
			}
			if (_event->KeyPressed) {
				if (_keyboard->isKeyPressed(sf::Keyboard::LAlt) && _keyboard->isKeyPressed(sf::Keyboard::F4)) {
					_window->close();
				}
			}
		}
		

		_player->updatePlayer(_deltaTime);
		

		if (_player->isAttacking()) {
			this->checkRessourceCollection();			//check for player ressource collections

			if (_player->isAttackingObject(&bob)) {
				_player->addToInventory(bob.gatherRessource(_player->getRessourcePower()));
			}
			if (_player->isAttackingObject(&bobette)) {
				_player->addToInventory(bobette.gatherRessource(_player->getRessourcePower()));
			}
			if (_player->isAttackingObject(&boobas)) {
				_player->addToInventory(boobas.gatherRessource(_player->getRessourcePower()));
			}
		}

		

		if (tickClock >= 5) {//update tick
			if (!_askRessourceUpdateur) {
				_askRessourceUpdateur = true;
			}

			

			bob.updateRessourcePoint();
			bobette.updateRessourcePoint();
			boobas.updateRessourcePoint();

			tickClock = 0;
		}
		slime.update(_deltaTime);
	

									
		//clear display
				//make green background
		_window->clear(sf::Color(0,128,60,255));

										//draw
		
		_window->setView(sf::View(_player->getPosition(),_screenResolution));

		
		
		_player->drawPlayer(_window);

		this->drawRessources();

		_window->draw(bob);
		_window->draw(bobette);
		_window->draw(boobas);

		_player->drawPlayerHUD(_window);

		_window->draw(slime);

		_window->display();		//show the window
		_deltaTime = deltaClock.getElapsedTime().asSeconds();
		deltaClock.restart();
		tickClock += _deltaTime;
	}
	_endThread = true;
	_chunkMakur->join();
	this->clearChunks();
}

void Game::checkRessourceCollection()
{
	auto cPos(this->getChunkFromPos(_player->getPosition()));

	for (int i = -3; i < 3; i++) {
		for (int j = -3; j < 3; j++) {
			if (this->isChunk({ cPos.x + i,cPos.y + j }))		//if chunk is loaded
			{
				this->getChunk({ cPos.x + i, cPos.y + j })->checkRessourceCollection(_player);
			}
		}
	}
}

void Game::initRessources()
{

	
	for (int i = -5; i < 5; i++) {
		for (int j = -5; j < 5; j++) {
			this->createChunk(sf::Vector2i{ i,j });
		}
	}
				

}

void Game::drawRessources()
{
	auto cPos(this->getChunkFromPos(_player->getPosition()));
	//draw in 3x3 chunk around player

	for (int i = -3; i <= 3; i++)
	{
		for (int j = -3; j <= 3; j++)
		{
			if (this->isChunk({cPos.x + i,cPos.y + j}))		//if chunk is loaded
			{
				this->getChunk({cPos.x + i, cPos.y + j})->draw(_window);
			}
		}
	}

}

const float& Game::getDeltaTime()
{
	return _deltaTime;
}

Player& Game::getPlayer()
{
	return *_player;
}

std::vector<Solid*>& Game::getSolidsVector(const sf::Vector2i& chunk)
{
	return this->getChunk(chunk)->solids;
}

std::vector<Water*>& Game::getWaterSpots(const sf::Vector2i& chunk)
{
	return this->getChunk(chunk)->waterSpots;
}

void Game::clearChunks()
{
	if (_chunks.size() > 0)
	{
		for (auto chunk : _chunks) { //destroy chunk
			delete chunk.second;
		}
		_chunks.clear();
	}
}

void Game::createChunk(const sf::Vector2i& chunk)
{
	std::pair<int, int> chunkPair(std::make_pair(chunk.x, chunk.y));
	assert(_chunks.find(chunkPair) == _chunks.end()); //assert chunk has to not exist

	_chunks.emplace(chunkPair, new Chunk(chunk));
	_chunks.at(chunkPair)->init();
	
}

Chunk* Game::getChunk(const sf::Vector2i& chunk)
{
	
	std::pair<int, int> chunkPair(std::make_pair(chunk.x,chunk.y));

	assert(_chunks.find(chunkPair) != _chunks.end()); //assert chunk has to exist

	return _chunks[chunkPair];
}

bool Game::isChunk(const sf::Vector2i& chunk)
{
	return (_chunks.find(std::make_pair(chunk.x, chunk.y)) != _chunks.end());//does chunk exist
}

sf::Vector2i Game::getChunkFromPos(const sf::Vector2f& position)
{
	return sf::Vector2i(int(position.x) / int(_window->getSize().x), int(position.y) / int(_window->getSize().y));
}

sf::Vector2i Game::getChunkSize()
{
	return sf::Vector2i(_window->getSize().x, _window->getSize().y);
}

#include <Windows.h>

void Game::updateRessourcePoints()
{
	do {

		if (_askRessourceUpdateur)
		{

			for (auto chunk : _chunks) {
				chunk.second->updateRessources();
			}
			_askRessourceUpdateur = false;
		}
		Sleep(50);
	} while (!_endThread);

	//update ressources in 5x5 chunk around player (DEPRECATED)
	/*
	auto cPos(this->getChunkFromPos(_player->getPosition()));

	for (int i = -5; i < 5; i++)
	{
		for (int j = -5; j < 5; j++)
		{
			if (this->isChunk({ cPos.x + i,cPos.y + j }))		//if chunk is loaded
			{
				this->getChunk({ cPos.x + i, cPos.y + j })->updateRessources();
			}
		}
	}
	*/
}

void Game::updateChunksLoaded()
{
	do {
		auto cPos = this->getChunkFromPos(this->getPlayer().getPosition());

		for (int i = -5; i < 5; i++) {
			for (int j = -5; j < 5; j++) {
				if (!this->isChunk({ cPos.x + i, cPos.y + j }))// if chunk doesnt exist
				{
					this->createChunk({ cPos.x + i, cPos.y + j }); //createChunk
				}
			}
		}
		Sleep(50);

	} while (!_endThread);
}
