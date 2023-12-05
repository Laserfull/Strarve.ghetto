#pragma once
#include <vector>

#include "ItemSlot.h"

class Craft
{
	float _craftTime;


	std::vector<CraftingStations::stations> _requiredStations;
	std::vector<Item> _requiredMaterials;
	Item _craftingResult;

	ItemSlot* _itemSlot;

public:
	Craft();

	Craft(const ToolName::name name);					// the craft of the tool
	Craft(const WeaponName::name name);					// the craft of the weapon
	Craft(const ArmorName::name name);					// the craft of the armor
	Craft(const UtilityName::name name);				// the craft of the utility
	Craft(const UpgradeName::name name);				// the craft of the upgrade
	Craft(const RessourceName::name name);				// the craft of the ressource
	Craft(const FoodName::name name);					// the craft of the food
	Craft(const BuildingName::name name);				// the craft of the build
	Craft(const SeedName::name name);					// the craft of the seed


	Craft(Item craftingResult,std::vector<Item>& requiredMaterials, const float& craftTime);		//full constructor (craft time has to be >=0)

	bool canCraft(const std::vector<ItemSlot*>& inventory, const std::vector<CraftingStations::stations>& atStations) const;			//returns true if you can craft the item

	bool isAtStation(const CraftingStations::stations station, const std::vector<CraftingStations::stations>& atStations) const;				//returns true if the player is at this station 

	const Item& getCraftingResult();									//returns _craftingResults
	const std::vector<Item>& getRequiredMaterials();					//returns _requiredMaterials
	float getCraftTime() const;											//returns _craftTime

	const ItemSlot& getItemSlot()const;							//returns _itemSlot

	void move(const sf::Vector2f& move);						//moves the itemslot
	void setPosition(const sf::Vector2f& newPosition);			//sets the position of the itemslot

	void draw(sf::RenderWindow* window);		//draws the craft at the screen as player GUI
};

void loadAllCraft(std::vector<Craft*>& craftlist);				// clears, then loads all craft in the vector

bool isItemQuantityContainedIn(const Item& itemQuantitySearched, const std::vector<ItemSlot*>& inventory);			//returns true if the item are of same type and have enough amount