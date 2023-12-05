#include <assert.h>

#include "PlayerCraft.h"

PlayerCraft::PlayerCraft(Craft* currentCraft)
{
	assert(currentCraft != nullptr);

	_currentCraft = currentCraft;
	_timePassed = 0;

}

PlayerCraft::~PlayerCraft()
{
	_currentCraft = nullptr;
	_timePassed = NULL;
}

void PlayerCraft::updateCraft(float timePassed)
{
	_timePassed += timePassed;
}

bool PlayerCraft::isCraftDone() const
{
	if (_timePassed >= _currentCraft->getCraftTime()) {			//if done return true
		return true;
	}
	else {														//return false
		return false;
	}
}

Item* PlayerCraft::getItem(std::vector<ItemSlot*>& inventory, std::map<ItemDef, unsigned int>& map, HoldingObject*& heldObject, Building*& heldBuild, Armor*& heldArmor) const
{
	if (this->isCraftDone()) {
		for (auto craft : _currentCraft->getRequiredMaterials()) {
			for (auto inv : inventory) {
				if (inv->getType() == craft.getType() && inv->getName() == craft.getName()) {
					if (heldObject != nullptr && *heldObject == craft) {
						if (inv->getAmount() == craft.getAmount()) {		//if amount eq to substract destroy object in hand
							delete heldObject;
							heldObject = nullptr;
						}
					}
					if (heldBuild != nullptr && *heldBuild == craft) {
						if (inv->getAmount() == craft.getAmount()) {		//if amount eq to substract destroy object in hand
							delete heldBuild;
							heldBuild = nullptr;
						}
					}
					if (heldArmor != nullptr && *heldArmor == craft) {
						if (inv->getAmount() == craft.getAmount()) {		//if amount eq to substract destroy object in hand
							delete heldArmor;
							heldArmor = nullptr;
						}
					}

					inv->substractAmount(craft.getAmount());
				}
			}
		}
		

		return new Item(_currentCraft->getCraftingResult());	//returns a new Item and pointer to the item (add to player inventory)
	}
	else {
		return nullptr;
	}
}
