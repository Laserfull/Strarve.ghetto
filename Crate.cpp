#include <vector>
#include <assert.h>

#include "Crate.h"
#include "Game.h"

extern Game* gameInfo;

extern sf::Texture* crateTexture;

Crate::Crate(std::vector<Crate*>* crateVector, const sf::Vector2f& position, const Item& itemContent) :Item(itemContent)
{
	this->setTexture(crateTexture);

	this->setSize({ gameInfo->getUnit().x * 100, gameInfo->getUnit().x * 100 });
	this->setPosition(position);


	_lifeTime = 30;
	_life = 8;
	_id = crateVector->size();
	_crateVector = crateVector;
}

Crate::~Crate()
{
	//erase current
	_crateVector->erase(_crateVector->begin() + _id);

	std::vector<Crate*>::iterator begin = _crateVector->begin() + _id;

	for (int i = _id; begin != _crateVector->end(); begin++, i++) {// for each crates after the one that is destroyed
		_crateVector->at(i)->lowerId();		//lower the vector id
	}

	_lifeTime = NULL;
	_life = NULL;
	_id = NULL;
}

void Crate::onAttacked()
{
	_life--;
}

int Crate::getLife() const
{
	return _life;
}

void Crate::lowerId()
{
	assert(_id > 0);

	_id--;
}

void Crate::update(const float& deltaTime)
{
	_lifeTime -= deltaTime;

	if (_lifeTime <= 0) {	//if lifetime exceeded, destroy
		this->~Crate();
	}
}

Item* Crate::getItem()
{
	if (_life <= 0) {
		return new Item(*this);
	}
	return nullptr;
}
