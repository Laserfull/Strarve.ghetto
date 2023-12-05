#include <iostream>
#include <assert.h>


#include "Item.h"

Item::Item()
{
	_amount = 0;
	_type = ItemType::NullType;
	_name = RessourceName::NullName;
}

Item::Item(const ToolName::name name, int amount) 
{
	assert(amount >= 0);						//amount has to be greater or equal to 0

	_amount = amount;
	_type = ItemType::Tool;
	_name = name;
}

Item::Item(const WeaponName::name name, int amount)
{
	assert(amount >= 0);						//amount has to be greater or equal to 0

	_amount = amount;
	_type = ItemType::Weapon;
	_name = name;
}

Item::Item(const ArmorName::name name, int amount)
{
	assert(amount >= 0);						//amount has to be greater or equal to 0

	_amount = amount;
	_type = ItemType::Armor;
	_name = name;
}

Item::Item(const UtilityName::name name, int amount)
{
	assert(amount >= 0);						//amount has to be greater or equal to 0

	_amount = amount;
	_type = ItemType::Utility;
	_name = name;
}

Item::Item(const UpgradeName::name name, int amount)
{
	assert(amount >= 0);						//amount has to be greater or equal to 0

	_amount = amount;
	_type = ItemType::Upgrade;
	_name = name;
}

Item::Item(const RessourceName::name name, int amount)
{
	assert(amount >= 0);						//amount has to be greater or equal to 0

	_amount = amount;
	_type = ItemType::Ressource;
	_name = name;
}

Item::Item(const FoodName::name name, int amount)
{
	assert(amount >= 0);						//amount has to be greater or equal to 0

	_amount = amount;
	_type = ItemType::Food;
	_name = name;
}

Item::Item(const BuildingName::name name, int amount)
{
	assert(amount >= 0);						//amount has to be greater or equal to 0

	_amount = amount;
	_type = ItemType::Building;
	_name = name;
}

Item::Item(const SeedName::name name, int amount)
{
	assert(amount >= 0);						//amount has to be greater or equal to 0

	_amount = amount;
	_type = ItemType::Seed;
	_name = name;
}

Item::Item(const Item& otherItem)
{
	_amount = otherItem.getAmount();

	_type = otherItem.getType();
	_name = otherItem.getName();
}

Item::~Item()
{
	_amount = NULL;
	_type = ItemType::type::NullType;
	_name = NULL;
}

int Item::getAmount() const
{
	return _amount;
}

ItemType::type Item::getType() const
{
	return _type;
}

int Item::getName() const
{
	return _name;
}

std::string Item::getDescription() const
{
	switch (_type)
	{
	case ItemType::NullType:
		return "A Null Slot";
		break;

	case ItemType::Tool:
		return ToolName::getDesc(_name);
		break;

	case ItemType::Weapon:
		return WeaponName::getDesc(_name);
		break;

	case ItemType::Armor:
		return ArmorName::getDesc(_name);
		break;

	case ItemType::Utility:
		return UtilityName::getDesc(_name);
		break;

	case ItemType::Upgrade:
		return UpgradeName::getDesc(_name);
		break;

	case ItemType::Ressource:
		return RessourceName::getDesc(_name);
		break;

	case ItemType::Food:
		return FoodName::getDesc(_name);
		break;

	case ItemType::Building:
		BuildingName::getDesc(_name);
		break;

	case ItemType::Seed:
		return SeedName::getDesc(_name);
		break;

	default:
		return "Error";
		break;
	}
}

std::string Item::getStrType() 
{
	return ItemType::getStrType(_type);			//get the type string name
}

std::string Item::getStrName() 
{
	switch (ItemType::type(_type)) {			//returns name depending on type (invalid if not found)
	case ItemType::type::NullType:
		return "Nulltype";
		break;

	case ItemType::type::Tool:
		return ToolName::getStrName(_name);
		break;

	case ItemType::type::Weapon:
		return WeaponName::getStrName(_name);
		break;

	case ItemType::type::Armor:
		return ArmorName::getStrName(_name);
		break;

	case ItemType::type::Utility:
		return UtilityName::getStrName(_name);;
		break;

	case ItemType::type::Upgrade:
		return UpgradeName::getStrName(_name);
		break;

	case ItemType::type::Ressource:
		return RessourceName::getStrName(_name);
		break;

	case ItemType::type::Food:
		return FoodName::getStrName(_name);
		break;

	case ItemType::type::Building:
		return BuildingName::getStrName(_name);
		break;

	case ItemType::type::Seed:
		return SeedName::getStrName(_name);
		break;

	default:
		return "Invalid";
		break;
	}
}

void Item::setAmount(int amount)
{
	assert(amount >= 0);			//amount has to be greater or equal to 0

	_amount = amount;
}

void Item::setType(const ItemType::type type)
{
	_type = type;
}

void Item::setName(const int name)
{
	_name = name;
}


void Item::addAmount(int amountToAdd)
{
	assert(amountToAdd>=0);			//has to be positive amount
	_amount += amountToAdd;
}

void Item::substractAmount(int amountToSubstract)
{
	assert(amountToSubstract >= 0 && _amount - amountToSubstract >= 0);					 //has to be >= 0 && not get the amount to negative

	_amount -= amountToSubstract;
}

bool Item::isContainedIn(const std::vector<Item*>& inventory, int minAmount) const
{
	assert(minAmount >= 0);//has to be greaer or equal to 0

	for (Item* invObject : inventory) {
		if (*this == *invObject && invObject->getAmount() >= minAmount) {
			return true;
		}
	}


	return false;
}

bool Item::isContainedIn(const std::vector<Item*>& inventory) const
{
	for (Item* invObject : inventory) {
		if (*this == *invObject) {
			return true;
		}
	}


	return false;
}

void Item::operator=(const Item& rightItem)
{
	this->_amount = rightItem.getAmount();

	this->_type = rightItem.getType();
	this->_name = rightItem.getName();
}

bool operator==(const Item& leftItem, const Item& rightItem)
{
	return (leftItem._type == rightItem._type && leftItem._name == rightItem._name );		// (_type && name)
}

bool operator!=(const Item& leftItem, const Item& rightItem)
{
	return !(leftItem == rightItem);
}
