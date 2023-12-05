#include <assert.h>

#include <SFML/Graphics.hpp>

#include "Game.h"
#include "ItemSlot.h"

extern sf::Texture* itemHolderTexture;
extern sf::Texture* itemIconTexture;

extern sf::Font* gameFont;

extern Game* gameInfo;

void ItemSlot::updateItemSlotTexture()
{
	
	//just a basic texture binder
	_item.setFillColor(sf::Color::White);
	switch (_type)
	{
	case ItemType::NullType:
		_itemSpriteSheet->setSpritePosition({ 0,0 });
		break;
	case ItemType::Tool:
		switch (_name) {
		case WeaponName::name::WoodenSword:
			_itemSpriteSheet->setSpritePosition({ 0,2 });
			break;

		case WeaponName::name::StoneSword:
			_itemSpriteSheet->setSpritePosition({ 1,2 });
			break;

		case WeaponName::name::GoldSword:
			_itemSpriteSheet->setSpritePosition({ 2,2 });
			break;
		}
		break;
	case ItemType::Weapon:
		switch (_name) {
		case WeaponName::name::WoodenSword:
			_itemSpriteSheet->setSpritePosition({ 0,1 });
			break;

		case WeaponName::name::StoneSword:
			_itemSpriteSheet->setSpritePosition({ 1,1 });
			break;

		case WeaponName::name::GoldSword:
			_itemSpriteSheet->setSpritePosition({ 2,1 });
			break;

		}

		break;

	case ItemType::Armor:			//armor

		switch (_name)
		{
		case ArmorName::name::WoodenHelmet:
			_itemSpriteSheet->setSpritePosition({ 0,6 });
			break;

		case ArmorName::name::StoneHelmet:
			_itemSpriteSheet->setSpritePosition({ 1,6 });
			break;

		case ArmorName::name::GoldHelmet:
			_itemSpriteSheet->setSpritePosition({ 2,6 });
			break;

		case ArmorName::name::MiniChapka:
			_itemSpriteSheet->setSpritePosition({ 3,6 });
			break;

		case ArmorName::name::Chapka:
			_itemSpriteSheet->setSpritePosition({ 4,6 });
			break;
		}

		break;

	case ItemType::Utility:
		switch (_name) {
		case UtilityName::name::Book:
			_itemSpriteSheet->setSpritePosition({ 0,3 });
			break;
		}

		break;

	case ItemType::Upgrade:

		switch (_name) {
		case UpgradeName::name::BackPack:
			_itemSpriteSheet->setSpritePosition({ 4,5 });
			break;
		}

		break;
	case ItemType::Ressource:
		switch (_name) {
		case RessourceName::name::Wood:
			_itemSpriteSheet->setSpritePosition({ 1,0 });
			break;

		case RessourceName::name::Stone:
			_itemSpriteSheet->setSpritePosition({ 2,0 });
			break;

		case RessourceName::name::Gold:
			_itemSpriteSheet->setSpritePosition({ 3,0 });
			break;

		case RessourceName::RabbitFur:
			_itemSpriteSheet->setSpritePosition({ 0,5 });
			break;

		case RessourceName::WolfFur:
			_itemSpriteSheet->setSpritePosition({ 1,5 });
			break;

		case RessourceName::String:
			_itemSpriteSheet->setSpritePosition({ 2,5 });
			break;

		case RessourceName::Paper:
			_itemSpriteSheet->setSpritePosition({ 3,5 });
			break;

		}

		break;
	case ItemType::Food:
		switch (_name) {
		case FoodName::Berries:

			_itemSpriteSheet->setSpritePosition({ 4,2 });
			break;

		case FoodName::Steak:
			_itemSpriteSheet->setSpritePosition({ 3,1 });
			break;

		case FoodName::CookedSteak:
			_itemSpriteSheet->setSpritePosition({ 4,1 });
			break;

		}

		break;
	case ItemType::Building:
		switch (_name) {
		case BuildingName::name::SmallCampfire:
			_itemSpriteSheet->setSpritePosition({ 1,3 });
			break;

		case BuildingName::name::BigCampfire:
			_itemSpriteSheet->setSpritePosition({ 2,3 });
			break;

		case BuildingName::name::Furnace:
			_itemSpriteSheet->setSpritePosition({ 3,3 });
			break;

		case BuildingName::name::Flag:
			_itemSpriteSheet->setSpritePosition({ 4,3 });
			break;

		case BuildingName::name::CraftingTable:
			_itemSpriteSheet->setSpritePosition({ 0,4 });
			break;

		case BuildingName::name::WoodenWall: case BuildingName::name::StoneWall: case BuildingName::name::GoldWall:
			_itemSpriteSheet->setSpritePosition({ 1,4 });

			switch (_name)//color definition
			{
			case BuildingName::name::WoodenWall:
				_item.setFillColor(sf::Color(98, 52, 18));
				break;

			case BuildingName::name::StoneWall:
				_item.setFillColor(sf::Color(146, 148, 151));
				break;

			case BuildingName::name::GoldWall:
				_item.setFillColor(sf::Color::Yellow);
				break;
			}

			break;

		case BuildingName::name::WoodenDoor: case BuildingName::name::StoneDoor: case BuildingName::name::GoldDoor://door texture
			_itemSpriteSheet->setSpritePosition({ 2,4 });

			switch (_name)//color definition
			{
			case BuildingName::name::WoodenDoor:
				_item.setFillColor(sf::Color(98, 52, 18));
				break;

			case BuildingName::name::StoneDoor:
				_item.setFillColor(sf::Color(146, 148, 151));
				break;

			case BuildingName::name::GoldDoor:
				_item.setFillColor(sf::Color::Yellow);
				break;
			}

			break;

		case BuildingName::Bridge:
			_itemSpriteSheet->setSpritePosition({ 3,4 });
			break;

		case BuildingName::Roof:
			_itemSpriteSheet->setSpritePosition({ 4,4 });
			break;

		}

		break;

	case ItemType::Seed://seed

		switch (_name)
		{
		case SeedName::name::BerriesSeed:
			_itemSpriteSheet->setSpritePosition({ 3,2 });
			break;
		}

		break;
	default:											// empty slot
		_itemSpriteSheet->setSpritePosition({ 0,0 });
		break;
	}

}

void ItemSlot::updateText()
{
	if (_amount > 1) {
		_amountOfItem.setString(std::to_string(_amount)+'x');
	}
	else {		//null string (0 or 1 _amount)
		_amountOfItem.setString("");
	}

	_amountOfItem.setPosition(this->getPosition().x + (this->getSize().x * 0.75) - ((_amountOfItem.getString().getSize() - 1) * _amountOfItem.getCharacterSize() / 2), this->getPosition().y + (this->getSize().y * 0.6));
}

ItemSlot::ItemSlot() : Item()
{
	this->setSize({ gameInfo->getUnit().x * 100, gameInfo->getUnit().y * 100 });

	this->sf::RectangleShape::setTexture(itemHolderTexture);

	//set position missing			!!!!!!!

	_item.setTexture(itemIconTexture);
	//set position missing			!!!!!!!

	_amountOfItem.setFont(*gameFont);
	_itemSpriteSheet = new SpriteSheet(&_item, { 5,7 });
	this->updateItemSlot();
}

ItemSlot::ItemSlot(const Item& item) : Item(item)
{
	this->setSize({ gameInfo->getUnit().x * 100, gameInfo->getUnit().y * 100 });

	this->sf::RectangleShape::setTexture(itemHolderTexture);

	//set position missing			!!!!!!!

	_item.setTexture(itemIconTexture);
	//set position missing			!!!!!!!

	_amountOfItem.setFont(*gameFont);
	_itemSpriteSheet = new SpriteSheet(&_item, { 5,7 });
	this->updateItemSlot();
}

void ItemSlot::updateItemSlot()
{
	this->updateItemSlotTexture();
	this->updateText();
}

void ItemSlot::setPosition(const sf::Vector2f& newPosition)
{
	this->sf::RectangleShape::setPosition(newPosition);
	_item.setPosition(newPosition);

								//x: current pos +  3/4 * the x size - (the string length of the displayed amount (-1 is for the x at the end * size of each char), y: current position - the 6/10 of the size of the box
	_amountOfItem.setPosition(newPosition.x + (this->getSize().x * 0.75) - ((_amountOfItem.getString().getSize() - 1) * _amountOfItem.getCharacterSize() / 2), newPosition.y + (this->getSize().y * 0.6));	//basically mathematical black magic in a nutshell
}

void ItemSlot::move(const sf::Vector2f& movement)
{
	this->sf::RectangleShape::move(movement);
	_item.move(movement);
	_amountOfItem.move(movement);
}

void ItemSlot::move(float x, float y)
{
	this->sf::RectangleShape::move(x,y);
	_item.move(x,y);
	_amountOfItem.move(x,y);
}

void ItemSlot::setSize(const sf::Vector2f& newSize)
{
	this->sf::RectangleShape::setSize(newSize);
	_item.setSize(newSize);
	//_amountOfItem.setCharacterSize(this->getSize().x/5);
	_amountOfItem.setCharacterSize(this->getSize().x/5);
}

void ItemSlot::setAmount(int newAmount)
{
	assert(newAmount >= 0);

	_amount = newAmount;

	if(_amount > 0)
	{
		this->updateText();
	}
	else {			//because amount is 0, ItemSlot will be containing nothing now

		_type = ItemType::type::NullType; //null icon
		_name = 0;	//null name

		this->updateItemSlot();
	}
}

void ItemSlot::setType(const ItemType::type type)
{
	if (type == ItemType::type::NullType) {			//if nulltype, make nullslot
		this->setAmount(0);
	}
	else {		//change the type
		_type = type;

		this->updateItemSlot();
	}
}

void ItemSlot::setName(const int name)
{
	if (name == 0) {	//if nullItem, make nullslot
		this->setAmount(0);
	}
	else {				//change the name
		_name = name;

		this->updateItemSlot();
	}
}

void ItemSlot::addAmount(int amountToAdd)
{
	assert(amountToAdd >= 0);

	_amount += amountToAdd;
	if (_amount > 1) {
		this->updateText();
	}
}

void ItemSlot::substractAmount(int amountToSubstract)
{
	assert(_amount - amountToSubstract >= 0);

	_amount -= amountToSubstract;

	if (_amount > 0)
	{
		this->updateText();
	}
	else {			//because amount is 0, ItemSlot will be containing nothing now

		_type = ItemType::type::NullType; //null icon
		_name = 0;	//null name

		this->updateItemSlot();
	}
}

const sf::Vector2f& ItemSlot::getPosition()
{
	return this->RectangleShape::getPosition();
}

const sf::Vector2f& ItemSlot::getSize()
{
	return this->RectangleShape::getSize();
}

void ItemSlot::draw(sf::RenderWindow* window) const
{
	window->draw(*this);
	window->draw(_item);
	window->draw(_amountOfItem);
}

void ItemSlot::operator=(const Item& rightItem)
{
	this->_amount = rightItem.getAmount();

	this->_type = rightItem.getType();
	this->_name = rightItem.getName();

	this->updateItemSlot();
}

void ItemSlot::operator=(const ItemSlot& rightSlot)
{
	this->_amount = rightSlot.getAmount();

	this->_type = rightSlot.getType();
	this->_name = rightSlot.getName();

	this->updateItemSlot();
}

