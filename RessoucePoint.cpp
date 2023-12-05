#include <assert.h>
#include "Game.h"
#include "basicFuntions.h"

#include "RessourcePoint.h"

extern Game* gameInfo;



RessourcePoint::RessourcePoint(const RessourcePoint& other) : Item(other.getItem()), sf::RectangleShape(other), Solid(this, gameInfo->getChunkFromPos(other.getPosition()))
{
	_maxRessource = other.getMaxRessource();
	_defense = other.getDefense();
}

RessourcePoint::RessourcePoint(const Item& ressource, const sf::Vector2f& spawnPoint, const sf::Vector2i& chunkPos, int scale, int defense) : Item(ressource), Solid(this, chunkPos)
{
	assert(defense >= 0);

	this->setSize(sf::Vector2f(gameInfo->getUnit().x * 30 * scale, gameInfo->getUnit().x * 30 * scale));
	

	this->setPosition(spawnPoint);
	

	_maxRessource = 3*scale;//max ressource is 1000 divided by scale reducer+9

	_defense = defense;
}

RessourcePoint::~RessourcePoint()
{
	this->RectangleShape::Drawable::~Drawable();
	this->RectangleShape::Transformable::~Transformable();
	this->Item::~Item();
}

void RessourcePoint::updateRessourcePoint()
{
	if(_amount !=_maxRessource)							//if isnt at max ressource (allows to save some ressource on the random and comparison)
	{
		int replenish = getRandom(1, 3);

		if (_amount + replenish <= _maxRessource) {		// if amount+replenish is lower than the max add to amount
			_amount += replenish;
		}
		else {											//set to max amount of ressource
			_amount = _maxRessource;
		}
	}
}

Item* RessourcePoint::gatherRessource(int gatherPower)
{
	if(gatherPower > _defense)		//if can gather the ressource
	{
		if (_amount >= gatherPower - _defense) {		//if there is more ressources than the amount, get for gathering power
			_amount -= (gatherPower - _defense);
			return this->createItemHolder(gatherPower - _defense);
		}
		else if (_amount != 0) {			//if power is greater than amount get the remaining amount
			int returnAmount = _amount;
			_amount = 0;
			return this->createItemHolder(returnAmount);
		}
		else if (_amount == 0) {
			return this->createItemHolder(0);	//ressource is empty (amount is 0)
		}
	}

	return nullptr;				//cant gather the ressource
}

const Item& RessourcePoint::getItem() const
{
	return *this;
}

int RessourcePoint::getDefense() const
{
	return _defense;
}

int RessourcePoint::getMaxRessource() const
{
	return _maxRessource;
}

Item* RessourcePoint::createItemHolder(int amount)
{
	Item* bozo = new Item(*this);
	bozo->setAmount(amount);
	return bozo;
}
