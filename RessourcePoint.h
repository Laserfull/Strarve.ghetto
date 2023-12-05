#pragma once
#include<SFML/Graphics.hpp>
#include "Item.h"
#include "Solid.h"

class RessourcePoint:
	public sf::RectangleShape,
	protected Item,
	private Solid

{
	int _defense;

	int _maxRessource;
	Item* createItemHolder(int gatherPower);

public:
	RessourcePoint(const RessourcePoint& other);
	RessourcePoint(const Item& ressource, const sf::Vector2f& spawnPoint, const sf::Vector2i& chunkPos, int scale, int defense = 0);			//create it at a certain point of the map

	~RessourcePoint();											//destroyer

	void updateRessourcePoint();								//update the tree at Every game tick (replenish 1-3 of its ressource)

	Item* gatherRessource(int gatherPower);

	const Item& getItem() const;

	int getDefense() const;

	int getMaxRessource() const;
};

