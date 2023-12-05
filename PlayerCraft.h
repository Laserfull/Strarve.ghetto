#pragma once
#include <map>

#include "HoldingObject.h"
#include "Building.h"
#include "ItemDef.h"
#include "Craft.h"
#include "Armor.h"



class PlayerCraft
{
	Craft* _currentCraft;

	float _timePassed;

public:

	PlayerCraft(Craft* currentCraft);				//creates a craft based on the Craft

	~PlayerCraft();									//puts every variables to NULL

	void updateCraft(float timePassed);				//update _timePassed

	bool isCraftDone() const;								//returns true if craft is done

	Item* getItem(std::vector<ItemSlot*>& inventory, std::map<ItemDef, unsigned int>& map, HoldingObject*& heldObject, Building*& heldBuild, Armor*& heldArmor) const;								//returns item if Craft is Done, else returns nullPtr
};

