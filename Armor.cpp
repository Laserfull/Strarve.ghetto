#include <assert.h>
#include "Armor.h"

#include "Game.h"

extern Game* gameInfo;

extern sf::Texture* armorTexture;

Armor::Armor(const Item& other): Item(other), SpriteSheet(this, armorTexture,{5,1})
{
	if (_type != ItemType::Armor) {//if type isnt an armor crash
		assert(false);
	}
	this->setSize(sf::Vector2f(gameInfo->getUnit().x * 240.0f, gameInfo->getUnit().y * 200.0f));
	this->setOrigin(this->getSize().x / 2, this->getSize().y / 2);
	switch (_name) {
	case ArmorName::WoodenHelmet:
		_defense = 5;
		this->setSpritePosition({ 0,0 });
		break;
	case ArmorName::StoneHelmet:
		_defense = 8;
		this->setSize(sf::Vector2f(gameInfo->getUnit().x * 240.0f, gameInfo->getUnit().y * 250.0f));
		this->setOrigin(this->getSize().x / 2, (this->getSize().y / 5) * 3);
		this->setSpritePosition({ 1,0 });
		break;
	case ArmorName::GoldHelmet:
		_defense = 10;
		this->setSpritePosition({ 2,0 });
		break;
	case ArmorName::MiniChapka:
		_defense = 0;
		this->setSpritePosition({ 3,0 });
		break;
	case ArmorName::Chapka:
		_defense = 0;
		this->setSpritePosition({ 4,0 });
		break;
	default:
		_defense = 0;
		break;
	}
	
	
}

Armor::~Armor()
{
	_defense = NULL;
}

unsigned int Armor::getDefense() const
{
	return _defense;
}
