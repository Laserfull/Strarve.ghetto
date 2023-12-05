#pragma once
#include "Item.h"
#include "SpriteSheet.h"

class HoldingObject : public Item , public sf::RectangleShape, public SpriteSheet
{
private:
	int _attackPower;
	int _gatheringPower;



public:
	HoldingObject(Item* item);			//default Constructor
	~HoldingObject();					//destructor

	int getAttackPower() const;				//get attack power
	int getGatheringPower() const;			//get gathering power

	const Item& getItem() const;			//returns its item
};