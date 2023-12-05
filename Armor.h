#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteSheet.h"
#include "Item.h"

class Armor: public sf::RectangleShape, public Item, public SpriteSheet
{
private:
	Armor();
	Armor(const Armor& other);

	unsigned int _defense;

public:
	Armor(const Item& other);
	~Armor();

	unsigned int getDefense() const;


};

