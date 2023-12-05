#include <assert.h>
#include <map>


#include "ItemDef.h"

#include "Player.h"
#include "Craft.h"


Craft::Craft()
{
	_craftTime = 0;

	_itemSlot = nullptr;
}

Craft::Craft(const ToolName::name name) 
{
	_craftingResult = Item(name);

	_craftTime = 0;


	switch (name)				//creates the craft
	{
	case ToolName::name::WoodenPickaxe:				//10 wood
		_requiredMaterials.push_back(Item(RessourceName::name::Wood, 10));

		_craftTime = 5;
		break;

	case ToolName::name::StonePickaxe:				//50 wood, 20 stone
		_requiredMaterials.push_back(Item(ToolName::name::WoodenPickaxe));

		_requiredMaterials.push_back(Item(RessourceName::name::Wood, 50));
		_requiredMaterials.push_back(Item(RessourceName::name::Stone, 20));

		_requiredStations.push_back(CraftingStations::stations::CraftingTable);

		_craftTime = 10;
		break;

	case ToolName::name::GoldPickaxe:				// 75 wood, 50 stone, 20 gold
		_requiredMaterials.push_back(Item(ToolName::name::StonePickaxe));

		_requiredMaterials.push_back(Item(RessourceName::name::Wood, 75));
		_requiredMaterials.push_back(Item(RessourceName::name::Stone, 50));
		_requiredMaterials.push_back(Item(RessourceName::name::Gold, 20));

		_requiredStations.push_back(CraftingStations::stations::CraftingTable);

		_craftTime = 15;
		break;

	default:					//out of range
		assert(false);
		break;
	}

	_itemSlot = new ItemSlot(Item(name));
}

Craft::Craft(const WeaponName::name name) {

	_craftingResult = Item(name);

	_craftTime = 0;

	switch (name)				//creates the craft
	{
	case WeaponName::name::WoodenSword:				//30 wood
		_requiredMaterials.push_back(Item(RessourceName::name::Wood, 30));

		_craftTime = 7;

		break;

	case WeaponName::name::StoneSword:				//50 wood, 30 stone
		_requiredMaterials.push_back(Item(WeaponName::name::WoodenSword));

		_requiredMaterials.push_back(Item(RessourceName::name::Wood, 50));
		_requiredMaterials.push_back(Item(RessourceName::name::Stone, 30));

		_requiredStations.push_back(CraftingStations::stations::CraftingTable);

		_craftTime = 10;
		break;

	case WeaponName::name::GoldSword:				//75 wood, 50 stone, 30 gold
		_requiredMaterials.push_back(Item(WeaponName::name::StoneSword));

		_requiredMaterials.push_back(Item(RessourceName::name::Wood, 75));
		_requiredMaterials.push_back(Item(RessourceName::name::Stone, 50));
		_requiredMaterials.push_back(Item(RessourceName::name::Gold, 30));

		_requiredStations.push_back(CraftingStations::stations::CraftingTable);

		_craftTime = 13;
		break;

	default:			//out of range
		assert(false);
		break;
	}

	_itemSlot = new ItemSlot(Item(name));
}

Craft::Craft(const ArmorName::name name)
{
	_craftingResult = Item(name);

	_craftTime = 0;

	switch (name) {
	case ArmorName::name::MiniChapka:				//1 rabbit fur, 4 string
		_requiredMaterials.push_back(Item(RessourceName::RabbitFur, 1));
		_requiredMaterials.push_back(Item(RessourceName::String, 4));

		_requiredStations.push_back(CraftingStations::CraftingTable);

		_craftTime = 7;
		break;

	case ArmorName::name::Chapka:					//4 string, 4 wolf fur
		_requiredMaterials.push_back(Item(ArmorName::MiniChapka));

		_requiredMaterials.push_back(Item(RessourceName::WolfFur, 4));
		_requiredMaterials.push_back(Item(RessourceName::String, 4));

		_requiredStations.push_back(CraftingStations::CraftingTable);

		_craftTime = 12;
		break;

	case ArmorName::name::WoodenHelmet:				//50 wood
		_requiredMaterials.push_back(Item(RessourceName::name::Wood, 50));

		_craftTime = 7;
		break;

	case ArmorName::name::StoneHelmet:				//75 wood, 50 stone
		_requiredMaterials.push_back(Item(ArmorName::name::WoodenHelmet));

		_requiredMaterials.push_back(Item(RessourceName::name::Wood, 75));
		_requiredMaterials.push_back(Item(RessourceName::name::Stone, 50));

		_requiredStations.push_back(CraftingStations::CraftingTable);

		_craftTime = 10;
		break;

	case ArmorName::name::GoldHelmet:				//100 wood, 75 stone, 50 gold
		_requiredMaterials.push_back(Item(ArmorName::name::StoneHelmet));

		_requiredMaterials.push_back(Item(RessourceName::name::Wood, 100));
		_requiredMaterials.push_back(Item(RessourceName::name::Stone, 75));
		_requiredMaterials.push_back(Item(RessourceName::name::Gold, 50));

		_requiredStations.push_back(CraftingStations::CraftingTable);

		_craftTime = 12;
		break;

	default:					//out of range
			assert(false);
			break;
	}

	_itemSlot = new ItemSlot(Item(name));
}

Craft::Craft(const UtilityName::name name)
{
	_craftingResult = Item(name);

	_craftTime = 0;
	
	switch (name) {
	case UtilityName::name::Book:				//5 wolf fur, 6 string
		_requiredMaterials.push_back(Item(RessourceName::WolfFur, 5));
		_requiredMaterials.push_back(Item(RessourceName::String, 6));

		_requiredStations.push_back(CraftingStations::CraftingTable);

		_craftTime = 10;
		break;

	default:					//out of range
		assert(false);
		break;
	}
	_itemSlot = new ItemSlot(Item(name));
}
Craft::Craft(const UpgradeName::name name)
{
	_craftingResult = Item(name);

	_craftTime = 0;
 
	switch (name) {
	case UpgradeName::name::BackPack:			//4 wolf fur 6 string
		_requiredMaterials.push_back(Item(RessourceName::WolfFur, 4));
		_requiredMaterials.push_back(Item(RessourceName::String, 6));

		_requiredStations.push_back(CraftingStations::CraftingTable);

		_craftTime = 10;
		break;

	default:					//out of range
		assert(false);
		break;
	}
	_itemSlot = new ItemSlot(Item(name));
}
Craft::Craft(const RessourceName::name name)
{
	_craftingResult = Item(name);

	_craftTime = 0;

	switch (name) {

	default:					//out of range
		assert(false);
		break;
	}
	_itemSlot = new ItemSlot(Item(name));
}

Craft::Craft(const FoodName::name name)
{
	_craftingResult = Item(name);

	_craftTime = 0;

	switch (name) {
	case FoodName::CookedSteak :
		_requiredMaterials.push_back(Item(FoodName::Steak, 1));

		_requiredStations.push_back(CraftingStations::stations::Fire);

		_craftTime = 5;
		break;

	default:					//out of range
		assert(false);
		break;
	}
	_itemSlot = new ItemSlot(Item(name));
}

Craft::Craft(const BuildingName::name name)
{
	_craftingResult = Item(name);

	_craftTime = 0;

	switch (name) {
	case BuildingName::WoodenWall: case BuildingName::WoodenDoor: case BuildingName::Roof: case BuildingName::Bridge:
		_requiredMaterials.push_back(Item(RessourceName::Wood, 15));

		_requiredStations.push_back(CraftingStations::stations::CraftingTable);

		_craftTime = 3;
		break;

	case BuildingName::StoneWall:
		_requiredMaterials.push_back(Item(BuildingName::WoodenWall));

		_requiredMaterials.push_back(Item(RessourceName::Stone, 10));

		_requiredStations.push_back(CraftingStations::stations::CraftingTable);

		_craftTime = 3;
		break;

	case BuildingName::StoneDoor:
		_requiredMaterials.push_back(Item(BuildingName::WoodenDoor));

		_requiredMaterials.push_back(Item(RessourceName::Stone, 10));

		_requiredStations.push_back(CraftingStations::stations::CraftingTable);

		_craftTime = 3;
		break;

	case BuildingName::GoldWall:
		_requiredMaterials.push_back(Item(BuildingName::StoneWall));

		_requiredMaterials.push_back(Item(RessourceName::Gold, 10));

		_requiredStations.push_back(CraftingStations::stations::CraftingTable);

		_craftTime = 3;
		break;

	case BuildingName::GoldDoor:
		_requiredMaterials.push_back(Item(BuildingName::StoneDoor));

		_requiredMaterials.push_back(Item(RessourceName::Gold, 10));

		_requiredStations.push_back(CraftingStations::stations::CraftingTable);

		_craftTime = 3;
		break;
	
	case BuildingName::CraftingTable:
		_requiredMaterials.push_back(Item(RessourceName::Wood, 25));
		_requiredMaterials.push_back(Item(RessourceName::Stone, 12));

		_craftTime = 6;
		break;

	case BuildingName::SmallCampfire:
		_requiredMaterials.push_back(Item(RessourceName::Wood, 20));
		_requiredMaterials.push_back(Item(RessourceName::Stone, 12));

		_craftTime = 4;
		break;

	case BuildingName::BigCampfire:
		_requiredMaterials.push_back(Item(RessourceName::Wood, 50));
		_requiredMaterials.push_back(Item(RessourceName::Stone, 20));

		_craftTime = 6;
		break;

	case BuildingName::Furnace:
		_requiredMaterials.push_back(Item(RessourceName::Wood, 75));
		_requiredMaterials.push_back(Item(RessourceName::Stone, 40));
		_requiredMaterials.push_back(Item(RessourceName::Gold, 20));

		_requiredStations.push_back(CraftingStations::stations::CraftingTable);

		_craftTime = 6;
		break;

	case BuildingName::Flag:
		_requiredMaterials.push_back(Item(RessourceName::Wood, 75));
		_requiredMaterials.push_back(Item(RessourceName::String, 10));

		_requiredStations.push_back(CraftingStations::stations::CraftingTable);

		_craftTime = 6;
		break;

	default:					//out of range
		assert(false);
		break;
	}
	_itemSlot = new ItemSlot(Item(name));

}
Craft::Craft(const SeedName::name name)
{
	_craftingResult = Item(name);

	_craftTime = 0;

	switch (name) {
	case SeedName::BerriesSeed:
		_requiredMaterials.push_back(Item(FoodName::Berries,3));

		_requiredStations.push_back(CraftingStations::stations::Fire);

		_craftTime = 3;
		break;

	default:					//out of range
		assert(false);
		break;
	}
	_itemSlot = new ItemSlot(Item(name));
}



Craft::Craft(Item craftingResult, std::vector<Item>& requiredMaterials, const float& craftTime)
{
	assert(craftTime >= 0);

	_craftTime = craftTime;
	_requiredMaterials = requiredMaterials;
	_craftingResult = craftingResult;
	_itemSlot = new ItemSlot(craftingResult);
}

bool Craft::isAtStation(const CraftingStations::stations station, const std::vector<CraftingStations::stations>& atStations) const
{
	for (CraftingStations::stations atStation : atStations)
	{
		if (atStation == station) {
			return true;
		}
	}

	return false;
}

bool Craft::canCraft(const std::vector<ItemSlot*>& inventory, const std::vector<CraftingStations::stations>& atStations) const
{


	for (Item requiredMaterial : _requiredMaterials) {			//for all items in the recipy
		if (!isItemQuantityContainedIn(requiredMaterial,inventory)) {				//if the inventory doesnt contain the requiredMaterials, return false
			return false;
		}
	}

	for (CraftingStations::stations station : _requiredStations) {
		if (!isAtStation(station, atStations)) {
			return false;
		}
	}


	return true;			//is craftable
}

const Item& Craft::getCraftingResult()
{
	return _craftingResult;
}

const std::vector<Item>& Craft::getRequiredMaterials()
{
	return _requiredMaterials;
}

const ItemSlot& Craft::getItemSlot()const {

	return *_itemSlot;
}


void Craft::move(const sf::Vector2f& move) {
	_itemSlot->move(move);
}

void Craft::setPosition(const sf::Vector2f& newPosition) {
	_itemSlot->setPosition(newPosition);
}

void Craft::draw(sf::RenderWindow* window)
{
	if (_itemSlot != nullptr)
	{
		_itemSlot->draw(window);
	}
	
}

float Craft::getCraftTime() const
{
	return _craftTime;
}

void loadAllCraft(std::vector<Craft*>& craftlist)
{
	craftlist.clear();//be sure that the array is cleared

	craftlist.push_back(new Craft(ToolName::WoodenPickaxe));
	craftlist.push_back(new Craft(ToolName::StonePickaxe));
	craftlist.push_back(new Craft(ToolName::GoldPickaxe));

	craftlist.push_back(new Craft(WeaponName::WoodenSword));
	craftlist.push_back(new Craft(WeaponName::StoneSword));
	craftlist.push_back(new Craft(WeaponName::GoldSword));

	craftlist.push_back(new Craft(ArmorName::MiniChapka));
	craftlist.push_back(new Craft(ArmorName::Chapka));
	craftlist.push_back(new Craft(ArmorName::WoodenHelmet));
	craftlist.push_back(new Craft(ArmorName::StoneHelmet));
	craftlist.push_back(new Craft(ArmorName::GoldHelmet));

	craftlist.push_back(new Craft(UtilityName::Book));

	craftlist.push_back(new Craft(UpgradeName::BackPack));

	craftlist.push_back(new Craft(FoodName::CookedSteak));

	craftlist.push_back(new Craft(BuildingName::WoodenWall));
	craftlist.push_back(new Craft(BuildingName::WoodenDoor));
	craftlist.push_back(new Craft(BuildingName::StoneWall));
	craftlist.push_back(new Craft(BuildingName::StoneDoor));
	craftlist.push_back(new Craft(BuildingName::GoldWall));
	craftlist.push_back(new Craft(BuildingName::GoldDoor));

	craftlist.push_back(new Craft(BuildingName::SmallCampfire));
	craftlist.push_back(new Craft(BuildingName::BigCampfire));

	craftlist.push_back(new Craft(BuildingName::CraftingTable));

	craftlist.push_back(new Craft(BuildingName::Roof));
	craftlist.push_back(new Craft(BuildingName::Bridge));

	craftlist.push_back(new Craft(BuildingName::Flag));

	craftlist.push_back(new Craft(SeedName::BerriesSeed));
}

bool isItemQuantityContainedIn(const Item& itemQuantitySearched, const std::vector<ItemSlot*>& inventory) {

	for (auto inv : inventory) {
		if (inv->getType() == itemQuantitySearched.getType() && inv->getName() == itemQuantitySearched.getName() && inv->getAmount() >= itemQuantitySearched.getAmount()) {
			return true;
		}
	}
	

	return false;
}