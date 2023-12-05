#pragma once
#include<map>

#include "ItemSlot.h"
#include "TouchSprite.h"
#include "FollowRectangle.h"
#include "PlayerCraft.h"
#include "HoldingObject.h"
#include "Platform.h"
#include "Crate.h"
#include "ItemDef.h"
#include "ErrorMessage.h"
#include "Building.h"
#include "Armor.h"



extern sf::Texture* playerTexture;
extern sf::Texture* handsTexture;


//the game's mega class
class Player : public TouchSprite, private Platform
{
protected:

	bool addToMatchingInventorySlot(Item* itemToAdd);			//tries to add the item to an inventory slot containing the same object type (returns false if unsuccessful)
	bool createNewInventorySlot(Item* itemToAdd);				//tries to push back the item to a new inventory slot (returns false if unsuccessful)

private:
	TouchSprite _leftHand;
	TouchSprite _rightHand;

	float _attackTime = 0;
	float _attackCooldown = 0;

	bool _isAttacking;

	bool _leftAttacking;
	bool _rightAttacking;
	bool _objectAttacking;

	float _life;
	float _hunger;
	float _heat;
	float _water;


	sf::RectangleShape _hitbox;

	std::vector<RectangleShape*> _attackedElements;

	std::map<ItemDef, unsigned int> _inventoryMap;

	std::vector<ItemSlot*> _inventory;

	std::vector<CraftingStations::stations> _atStations;

	HoldingObject* _objectInHand;
	Armor* _armor;
	
	PlayerCraft* _playerCraft;

	std::vector<Craft*> _CraftList;//the craftList
	std::vector<Craft*>* _CraftableObjects;// the currently craftable objects also oops i putted first letters in caps

	std::vector<Crate*> _crates;

	std::vector<Building*> _buildingVector;
	std::vector<Building*> _craftingTables;
	std::vector<Building*> _fire;

	Building* _building;

	ErrorMessage* _errorMessage;

	void craftingActualisation();						//check through every craftable object and pushes them back to _craftableObjects

	//update the stations the player is currently at in _atStations and update craftlist if different
	void updateStations();

	const std::vector<ItemSlot*>& getInventory();		//returns the player's inventory

	//disallowed constructor
	
	
	Player(const Player& other);

public:
	Player(sf::Vector2f spawnPoint = {0,0});		//just the only constructor to create a player
	
	void updatePlayer(const float& deltaTime);							//update the Player's general information by the time that has passed

	//move the player and all its related elements
	void move(sf::Vector2f& movement);
	//move the player and all its related elements
	void move(float x, float y);

	void onMouseLeftPressed(const sf::Vector2f& mousePosition);				//actions to do on right mouse click (use item,craft)
	void onMouseRightPressed(const sf::Vector2f& mousePosition);			//actions to do on right mouse click (drop item,cancel craft)

	void useItem(ItemSlot& slot);									//uses the item (equip if a sword or tool, eat, equip build, etc...)
	void dropItem(ItemSlot& slot);									//uses the item (equip if a sword or tool, eat, equip build, etc...)

	void attack(bool rightHandAttack);									//force and attack to happen (if its not already attacking and not in cooldown)

	void draw(sf::RenderWindow* window);								//draw the player and its HUD
	void drawPlayer(sf::RenderWindow* window);							//draws the player
	void drawPlayerHUD(sf::RenderWindow* window);						//draws the player's HUD

	
	float rightAttackAngle() const;										//the angle of the hand with the right attack
	float leftAttackAngle() const;										//the angle of the hand with the left attack

	bool isAttacking() const;											//returns true if the player is currently attacking (_isAttacking)
	bool attackHand() const;											//returns true if right hand (used in attack parameter)
	bool isAttackingObject( sf::RectangleShape* other);					//returns true if attacking hand is in collision with other object
	bool isAttackingObject(sf::RectangleShape& other);

	void stopAttacking();											//force to stop attacking and apply cooldown

	int findAttackedElements(sf::RectangleShape* element);			//finds the place at which position (by index) is the attacked element (in parameter) -1 means that it isnt found 

	int getRessourcePower();										//returns the amount of ressource power (capacity to mine multiple ressources at a time) the player has

	bool addToInventory(Item* itemToAdd);								//tries to add an item to the player's inventory (returns false if unsuccessful (dont ask me why i did that, its for debugging purpose))


	//get the crafting tables vector
	std::vector<Building*>& getCraftingTablesVector();
	//get the fire station vector
	std::vector<Building*>& getFireStationsVector();
	//get the building vector
	std::vector<Building*>& getBuildingVector();
};

