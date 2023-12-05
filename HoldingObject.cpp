#include <assert.h>
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "HoldingObject.h"
#include "Player.h"

extern Game* gameInfo;
extern sf::Texture* handItemsTexture;

HoldingObject::HoldingObject(Item* item) : Item(*item) , SpriteSheet(this, handItemsTexture,{3,3})
{
	//this->setSpriteAmount({ 3,3 });		//uncomment when reactualisation is enabled

	_gatheringPower = 0;
	_attackPower = 0;
	

	if (_amount > 0 && _type != ItemType::NullType) {
		switch (_type)
		{

		case ItemType::Tool:
			switch (ToolName::getName(_name))
			{
			case ToolName::name::WoodenPickaxe:
				_gatheringPower = 2;
				_attackPower = 5;
				this->setSpritePosition({ 0,1 });
				

				break;

			case ToolName::name::StonePickaxe:
				_gatheringPower = 3;
				_attackPower = 5;
				this->setSpritePosition({ 1,1 });

				break;

			case ToolName::name::GoldPickaxe:
				_gatheringPower = 4;
				_attackPower = 5;
				this->setSpritePosition({ 2,1 });

				break;

			default:
				assert(false);		//look up if the item called is initializable or if getName contains the mentionned item
				break;
			}
			this->setSize({ gameInfo->getUnit().x * 15 * 6, gameInfo->getUnit().x * 15 * 13 });
			this->setOrigin(this->getSize().x / 2, this->getSize().y * 0.9);
			break;


		case ItemType::Weapon:
			switch (WeaponName::getName(_name))
			{
			case WeaponName::name::WoodenSword:
				_gatheringPower = 0;
				_attackPower = 14;
				this->setSpritePosition({ 0,0 });
				break;

			case WeaponName::name::StoneSword:
				_gatheringPower = 0;
				_attackPower = 18;
				this->setSpritePosition({ 1,0 });
				break;

			case WeaponName::name::GoldSword:
				_gatheringPower = 0;
				_attackPower = 24;
				this->setSpritePosition({ 2,0 });
				break;

			default:
				assert(false);		//look up if the item called is initializable or if getName contains the mentionned item
				break;
			}
			this->setSize({ gameInfo->getUnit().x * 15 * 6, gameInfo->getUnit().x * 15 * 13 });
			this->setOrigin(this->getSize().x / 2, this->getSize().y * 0.9);
			break;


		case ItemType::Utility:
			switch (UtilityName::getName(_name))
			{
			case UtilityName::name::Book:
				_gatheringPower = 0;
				_attackPower = 5;
				this->setSpriteAmount({ 3,6 });
				this->setSpritePosition({ 0,5 });
				break;

			default:
				assert(false);		//look up if the item called is initializable or if getName contains the mentionned item
				break;
			}
			this->setSize({ gameInfo->getUnit().x * 15 * 6, (gameInfo->getUnit().x * 15 * 13) / 2 });
			this->setOrigin(this->getSize().x * 0.2 , this->getSize().y * 0.8);
			break;
			

		default:
			assert(false);		//this item cannot be held (go check if player Item interaction is done correctly)
			break;
		}
	}
}

HoldingObject::~HoldingObject()
{
	this->Item::~Item();
	_attackPower = NULL;
	_gatheringPower = NULL;
}

int HoldingObject::getAttackPower() const
{
	return _attackPower;
}

int HoldingObject::getGatheringPower() const
{
	return _gatheringPower;
}

const Item& HoldingObject::getItem() const
{
	return *this;
}


