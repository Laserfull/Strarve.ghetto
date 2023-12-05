#include<iostream>
#include<map>
#include<SFML/Graphics.hpp>
#include <Windows.h>



#include "basicFuntions.h"
#include "TouchSprite.h"
#include "Game.h"
#include "FollowRectangle.h"

#include "Craft.h"
#include "Water.h"
#include "Player.h"


extern Game* gameInfo;

Player::Player(sf::Vector2f spawnPoint) :TouchSprite(playerTexture, sf::Vector2u(1, 1), 10, false), Platform(&_hitbox)
{
	this->setSize(sf::Vector2f(gameInfo->getUnit().x * 200.0f , gameInfo->getUnit().y * 125.0f));	//8:5 aspect ratio
	this->setPosition(500, 500);
	this->setOrigin(this->getSize().x / 2, this->getSize().y / 2);

	_hitbox.setSize({ this->getSize().y / 2, this->getSize().y / 2 });
	_hitbox.setOrigin(_hitbox.getSize().x / 2, _hitbox.getSize().y / 2);
	_hitbox.setPosition(this->getPosition());

	_leftHand.setTexture(handsTexture);
	_leftHand.setSize(sf::Vector2f(this->getSize().x / 4, this->getSize().x / 4)); //1:1
	_leftHand.setOrigin(_leftHand.getSize().x / 2, _leftHand.getSize().y / 2);

	_rightHand.setTexture(handsTexture);
	_rightHand.setSize(sf::Vector2f(this->getSize().x / 4, this->getSize().x / 4));//1:1
	_rightHand.setOrigin(_rightHand.getSize().x / 2, _rightHand.getSize().y / 2);

	_playerCraft = nullptr;
	_building = nullptr;
	_armor = nullptr;
	//_armor = new Armor({ArmorName::StoneHelmet,1});

	for (int i = 0; i < 9; i++) {
		_inventory.push_back(new ItemSlot());
	}

	int eachSpace = _inventory[0]->getSize().x + (gameInfo->getUnit().x * 20);
	int begin = eachSpace * 4.5;

	for (int i = 0; i < _inventory.size();i++) {
		_inventory[i]->setPosition(sf::Vector2f( this->getPosition().x - begin + (i * eachSpace), this->getPosition().y + (400 * gameInfo->getUnit().y) ));
	}

	_CraftableObjects = new std::vector<Craft*>;

	loadAllCraft(_CraftList);	//loads all crafts in the vector


	this->craftingActualisation();			//actualize craft
}

void Player::updatePlayer(const float& deltaTime)
{
	this->setRotation(findAngle(this->getPosition()-sf::Vector2f(gameInfo->getMousePosition()))+90);//set rotation towards cursor
	_hitbox.setPosition(this->getPosition());
						//move
	if (gameInfo->_keyboard->isKeyPressed(sf::Keyboard::A)) {
		this->move(-gameInfo->_screenResolution.x / 5 * deltaTime, 0);
	}
	if (gameInfo->_keyboard->isKeyPressed(sf::Keyboard::D)) {
		this->move(gameInfo->_screenResolution.x / 5 * deltaTime, 0);
	}
	if (gameInfo->_keyboard->isKeyPressed(sf::Keyboard::W)) {
		this->move(0, -gameInfo->_screenResolution.x / 5 * deltaTime);
	}
	if (gameInfo->_keyboard->isKeyPressed(sf::Keyboard::S)) {
		this->move(0, gameInfo->_screenResolution.x / 5 * deltaTime);
	}

	if (gameInfo->getMouse()->isButtonPressed(sf::Mouse::Left) && _playerCraft == nullptr) {
		this->attack(this->attackHand());
	}

	if (_attackCooldown > 0) {//reduce attack cooldown
		_attackCooldown -= deltaTime;
	}
	if (_attackCooldown < 0) {//if attack cooldown < 0, set to 0
		_attackCooldown = 0;
	}


	if (_isAttacking) {
		_attackTime += deltaTime;

		for (auto crate : _crates) {		//for each crates
			if (this->isAttackingObject(crate)) {		//if crate is attacked

				crate->onAttacked();					//attack the crate

				if (crate->getLife() <= 0) {			//if crate is dead
					this->addToInventory(crate->getItem());			//add content to inventory
					delete crate;								//destroy the crate
				}
			}
		}

		if (_attackTime > 0.5f) {//if done attacking
			this->stopAttacking();
		}
	}
										//update crates

	for (auto crate : _crates) {
		crate->update(deltaTime);
	}

										//math :sunglasses:

	_leftHand.setPosition(this->getPosition() + rotateVectorAngle(this->getRotation() - 135 + leftAttackAngle(), this->getSize().x / 2));//angle of player+attack
	_rightHand.setPosition(this->getPosition() + rotateVectorAngle(this->getRotation() - 45 - rightAttackAngle(), this->getSize().x / 2));//same as above but for right hand

	if (_objectInHand != nullptr) {		//if there is an object in hand
		_objectInHand->setPosition(_rightHand.getPosition());
		_objectInHand->setRotation(-rightAttackAngle()+this->getRotation());
	}
	
	if (_playerCraft != nullptr) {		//if the player is crafting something
		_playerCraft->updateCraft(deltaTime);

		if (_objectInHand != nullptr && _objectInHand->getItem() == Item(UtilityName::Book)) {//if the player has a book in hand
			_playerCraft->updateCraft(deltaTime);	//update a second time
		}
		if (_playerCraft->isCraftDone()) {
			this->addToInventory(_playerCraft->getItem(_inventory,_inventoryMap, _objectInHand, _building, _armor));
			

			delete _playerCraft;
			_playerCraft = nullptr;
		}
	}
	else {			//if not already crafting, update the current stations
		this->updateStations();
	}

	if (_errorMessage != nullptr) {			//if message exist, update
		_errorMessage->update(deltaTime);

		if (_errorMessage->isDead()) {			//if message is dead destroy
			delete _errorMessage;
			_errorMessage = nullptr;
		}
	}

	if (_building != nullptr) {			//if player is building
		if (isCollisionWithSolids(_building)) {				//if is in collision with other shape, set outline as red (not placeable)
			_building->setOutlineThickness(gameInfo->getUnit().x * 10);
			_building->setOutlineColor(sf::Color(255, 0, 0, 255));
		}
		else				//placeable
		{ 
			_building->setOutlineThickness(0);
			_building->setOutlineColor(sf::Color(255, 255, 255, 0));
		}
				//set the building to a radius of 350 pixel around the player and set its rotation at same as player
		_building->setPosition(this->getPosition() + rotateVectorAngle(this->getRotation() - 90, 350 * gameInfo->getUnit().x));
		_building->setRotation(this->getRotation());
	}
	

	for (auto build : _buildingVector) {
		build->update(deltaTime);
	}

	if (_armor != nullptr) {
		_armor->setPosition(this->getPosition());
		_armor->setRotation(this->getRotation() + 180);
	}
	
}

void Player::attack(bool rightHandAttack)
{
	if (!_isAttacking && _attackCooldown<=0) {
		_isAttacking = true;
		if (rightHandAttack) {
			_rightAttacking = true;
		}
		else {
			_leftAttacking = true;
		}
	}
}

void Player::drawPlayer(sf::RenderWindow* window)
{
	for (auto crate : _crates) {
		window->draw(*crate);
	}

	window->draw(*this);
	window->draw(_leftHand);

	if (_objectInHand != nullptr) {//if player has an object in its hand
		window->draw(*_objectInHand);
	}

	window->draw(_rightHand);

	if (_armor != nullptr) {// if player has armor draw the armor
		window->draw(*_armor);
	}

	if (_building != nullptr) {//if player has building, draw the building
		window->draw(*_building);
	}

	for (auto build : _buildingVector) {
		window->draw(*build);
	}
}

void Player::drawPlayerHUD(sf::RenderWindow* window)
{
	for (ItemSlot* item : _inventory) {
		item->draw(window);
	}

	for (auto craft : *_CraftableObjects) {
		craft->draw(window);
	}
	if (_errorMessage != nullptr) {
		_errorMessage->draw(window, { this->getPosition().x, this->getPosition().y - gameInfo->getUnit().y - 400});
	}

}

float Player::rightAttackAngle() const
{
	if(_rightAttacking)
	{
		return _attackTime * 120;
	}
	else {
		return 0.0f;
	}
}

float Player::leftAttackAngle() const
{
	if (_leftAttacking)
	{
		return _attackTime * 120;
	}
	else {
		return 0.0f;
	}
}

bool Player::isAttacking() const
{
	return _isAttacking;
}

void Player::draw(sf::RenderWindow* window)
{
	this->drawPlayer(window);

	this->drawPlayerHUD(window);
	
}

bool Player::isAttackingObject( sf::RectangleShape* other) 
{
	if(_objectInHand==nullptr)
	{
		if (findAttackedElements(other) == -1 && ((_leftAttacking && isCollision(_leftHand, other)) || (_rightAttacking && isCollision(_rightHand, other)))) {// if element isnt already hit && in collision with attacking hand
			_attackedElements.push_back(other);
			return true;
		}
	}
	else {
		if (findAttackedElements(other) == -1 && _isAttacking && _objectInHand->getGlobalBounds().intersects(other->getGlobalBounds())) {// if element isnt already hit && in collision with attacking hand
			_attackedElements.push_back(other);
			return true;
		}
	}
	
	return false;
}
bool Player::isAttackingObject(sf::RectangleShape& other) {
	return this->isAttackingObject(&other);
}

bool Player::attackHand() const
{
	if (_objectInHand == nullptr) {
		return getRandom(0, 1);
	}
	return true;
}

void Player::stopAttacking()
{
	_attackCooldown = 0.5f - _attackTime;

	_attackTime = 0.0f;
	_isAttacking = false;
	_rightAttacking = false;
	_leftAttacking = false;

	_attackedElements.clear();
}

int Player::findAttackedElements(sf::RectangleShape* element)
{
	int i = 0;
	for (RectangleShape* shape : _attackedElements) {	//for each attacked elements on the on the attack
		if (shape == element) {			//if element has already been hit
			return i;				//return the id of the element
		}
		i++;
	}

	return -1;//not found
}

void Player::updateStations()
{
	//create a copy of the current stations the player is at

	auto copy = _atStations;

	_atStations.clear();

	//check if close to any crafting table

	for (auto craftingTable : _craftingTables) {

		sf::Vector2f deltaPos(craftingTable->getPosition() - this->getPosition());
		if ((deltaPos.x < 350 * gameInfo->getUnit().x && deltaPos.x > -350 * gameInfo->getUnit().x) && (deltaPos.y < 350 * gameInfo->getUnit().y && deltaPos.y > -350 * gameInfo->getUnit().y)) {
			_atStations.push_back(CraftingStations::CraftingTable);
			break;
		}
	}

	//check if close to any campfire

	for (auto fire : _fire) {

		sf::Vector2f deltaPos(fire->getPosition() - this->getPosition());
		if ((deltaPos.x < 350 * gameInfo->getUnit().x && deltaPos.x > -350 * gameInfo->getUnit().x) && (deltaPos.y < 350 * gameInfo->getUnit().y && deltaPos.y > -350 * gameInfo->getUnit().y)) {
			_atStations.push_back(CraftingStations::Fire);
			break;
		}
	}

	//check if in water from the chunks search

	auto cPos(gameInfo->getChunkFromPos(this->getPosition()));

	bool foundWater(false);

	for (int i = -2; i < 2; i++) {
		for (int j = -2; j < 2; j++) {
			
			if (gameInfo->isChunk({ cPos.x + i, cPos.y + j })) {

					Chunk* chunkPtr = gameInfo->getChunk({ cPos.x + i, cPos.y + j });
				for (int i = 0; i < chunkPtr->waterSpots.size(); i++) {
					if (chunkPtr->waterSpots[i]->getLocalBounds().contains(this->getPosition())) {
						_atStations.push_back(CraftingStations::Water);
						foundWater = true;
						break;
					}
				}
				if (foundWater) {
					break;
				}
			}
		}
		if (foundWater) {
			break;
		}
	}

	

	//if the the vector changed from the last one, update the crafting list

	if (copy != _atStations) {
		this->craftingActualisation();
	}
}

void Player::onMouseLeftPressed(const sf::Vector2f& mousePosition)
{
	if(_playerCraft == nullptr && gameInfo->getMouse()->isButtonPressed(sf::Mouse::Left))	//if not crafting
	{
		bool buttonClicked(false);

		for (auto craft : *_CraftableObjects)		//for each craftable object
		{
			if (craft->getItemSlot().getGlobalBounds().contains(mousePosition)) {		//if the craftable object is clicked
				_playerCraft = new PlayerCraft(craft);			//create a craft for the player to start crafting
				buttonClicked = true;
			}
		}
		
		for (auto slot : _inventory) {			//for each slot of the inventory
			if (slot->getGlobalBounds().contains(mousePosition))
			{
				if (_objectInHand != nullptr && *slot == *_objectInHand) {	//if the item is the one in hand
					delete _objectInHand;
					_objectInHand = nullptr;

					buttonClicked = true;
				}
				else if (_armor != nullptr && *slot == *_armor) {	//if the item is the one in hand
					delete _armor;
					_armor = nullptr;

					buttonClicked = true;
				}
				else if (slot->getType() != ItemType::type::NullType) {		//if a slot is clicked and not empty
					this->useItem(*slot);

					buttonClicked = true;
				}
			}
		}

		if (!buttonClicked && _building != nullptr) {//if no button were clicked place building
			if (_building->getOutlineThickness() == 0)			//if can be placed
			{
				_building->placeBuilding();

				for (auto slot : _inventory) {			//for each slot of the inventory
					if (*slot == *_building) {//if found the building, substract 1 from the inventory
						slot->substractAmount(1);
						_building = nullptr;
						break;
					}
				}
			}
		}
	}
}

void Player::onMouseRightPressed(const sf::Vector2f& mousePosition)
{ 
	if(gameInfo->getMouse()->isButtonPressed(sf::Mouse::Right))
	{
		if (_playerCraft == nullptr)//if not crafting drop item
		{
			for (auto slot : _inventory) {			//for each slot of the inventory
				if (slot->getGlobalBounds().contains(mousePosition) && slot->getType() != ItemType::type::NullType) {		//if a slot is clicked and not empty

					if (_objectInHand != nullptr && *slot == _objectInHand->getItem()) {
						delete _objectInHand;
						_objectInHand = nullptr;
					}
					if (_building != nullptr && *slot == *_building) {
						delete _building;
						_building = nullptr;
					}
					if (_armor != nullptr && *slot == *_armor) {
						delete _armor;
						_armor = nullptr;
					}

					this->dropItem(*slot);
				}
			}
		}
		else {		//if crafting stop crafting and lose all items
			delete _playerCraft;
			_playerCraft = nullptr;
		}
	}
}

void Player::useItem(ItemSlot& slot) {
	switch (ItemType::type(slot.getType()))
	{
	case ItemType::type::Tool:		//if tool or weapon
		if (_objectInHand != nullptr) {
			delete _objectInHand;
		}
		_objectInHand = new HoldingObject(&slot);

		break;

	case ItemType::type::Weapon:
		if (_objectInHand != nullptr) {
			delete _objectInHand;
		}
		_objectInHand = new HoldingObject(&slot);

		break;

	case ItemType::type::Armor:
		if (_armor != nullptr) {
			delete _armor;
		}
		_armor = new Armor(slot);

		break;

	case ItemType::type::Utility:
		if (_objectInHand != nullptr) {
			delete _objectInHand;
		}
		_objectInHand = new HoldingObject(&slot);

		break;

	case ItemType::type::Upgrade:


		break;

	case ItemType::type::Ressource:


		break;

	case ItemType::type::Building:
		if(_building != nullptr)		//if has building
		{
			if (*_building != slot) {
				delete _building;
				_building = new Building(slot);
			}
			else {
				delete _building;
				_building = nullptr;
			}
		}
		else
		{
			_building = new Building(slot);
		}
		
		break;

	case ItemType::type::Seed:


		break;

	default:
		break;
	}
}

void Player::dropItem(ItemSlot& slot) 
{
	_crates.push_back(new Crate(&_crates, this->getPosition(), slot));	//add a crate containing the itemSlot content

	slot.setType(ItemType::NullType);									//make the slot a null slot
	this->craftingActualisation();										//actualise craft list
}


void Player::move(sf::Vector2f& movement)
{
	sf::Vector2f bruh = this->getPlatformMove(movement);	// get Bidirectionnal Reactive User Headed direction (bruh)

				//move everything related to the player according to bruh

	this->RectangleShape::move(bruh);

	for(ItemSlot* item : _inventory){
		item->move(bruh);
	}
	for (Craft* craft : *_CraftableObjects) {
		craft->move(bruh);
	}
}

void Player::move(float x, float y)
{
	sf::Vector2f bruh = this->getPlatformMove(sf::Vector2f(x,y));	// get Bidirectionnal Reactive User Headed direction (bruh)

				//move everything related to the player according to bruh

	this->RectangleShape::move(bruh);

	for (ItemSlot* item : _inventory) {
		item->move(bruh);
	}
	for (Craft* craft : *_CraftableObjects) {
		craft->move(bruh);
	}
}

void Player::craftingActualisation()
{
	std::vector<Craft*>* craftListPtr= new std::vector<Craft*>;

	for (auto craft : _CraftList) {			//check through all craft list, if can craft add to new vector
		if (craft->canCraft(_inventory, _atStations)) {
			craftListPtr->push_back(craft);
		}
	}

	if (*craftListPtr != *_CraftableObjects)	//if vectors arent the same, destroy old vector and place new vector
	{
		delete _CraftableObjects;

		_CraftableObjects = craftListPtr;

		int y = 0;
		int x = 0;

		for (auto craft : *_CraftableObjects) {			//to show like a list, compromises had to be made with maths and other black magic like so
			craft->setPosition(this->getPosition() - sf::Vector2f(gameInfo->getUnit().x * (920 - (x * 120)),
																  gameInfo->getUnit().y * (500 - (y * 120))));

			y++;//craft organisation
			if (y > 7) {
				y = 0;
				x++;
			}
		}

	}
}

const std::vector<ItemSlot*>& Player::getInventory()
{
	return _inventory;
}

bool Player::addToMatchingInventorySlot(Item* itemToAdd)
{
	for (ItemSlot* item : _inventory)
	{
		if (item->getType() == itemToAdd->getType() && item->getName() == itemToAdd->getName()) {//if slot is of same ressource, add to slot
			item->addAmount(itemToAdd->getAmount());

			delete itemToAdd;//destroy the item

			//message in console
			std::cout << "The Player now has " << item->getAmount() << " amount in the " << item->getStrName() << " slot " << std::endl;

			return true;
		}
	}

	return false;				//no matching inventory slot
}

bool Player::createNewInventorySlot(Item* itemToAdd)
{
	for (ItemSlot* item : _inventory)
	{
		if (item->getType() == ItemType::NullType) {//if slot is empty, add to slot
			*item = *itemToAdd;
			delete itemToAdd;

			//message in console
			std::cout << "The Player has created a new slot of " << item->getStrName() << " containing " << item->getAmount() << std::endl;
			return true;
		}
	}
	

	return false;
}

bool Player::addToInventory(Item* itemToAdd)
{

	if (itemToAdd != nullptr)	//if its not a nullptr (couldnt collect the ressource)
	{
		if (itemToAdd->getAmount() != 0)		//if not amount of 0
		{
			if (this->addToMatchingInventorySlot(itemToAdd)) {
				this->craftingActualisation();			//actualize crafting list
				return true;
			}
			else {			//add storage limit

				if (this->createNewInventorySlot(itemToAdd)) {
					this->craftingActualisation();			//actualize crafting list
					return true;
				}
				else {
					//inventory full
					if (_errorMessage == nullptr) {
						_errorMessage = new ErrorMessage("Your Inventory is full, (drop item with M_Button 2)");
					}
					else {
						_errorMessage->changeText("Your Inventory is full, (drop item with M_Button 2)");
					}
					return false;
				}
			}
		}
		//ressource is empty

		if (_errorMessage == nullptr) {
			_errorMessage = new ErrorMessage("This ressource is empty");
		}
		else {
			_errorMessage->changeText("This ressource is empty");
		}
		return false;
	}
	//too weak tool

	if (_errorMessage == nullptr) {
		_errorMessage = new ErrorMessage("This is the wrong tool");
	}
	else {
		_errorMessage->changeText("This is the wrong tool");
	}

	return false;
}

int Player::getRessourcePower()
{
	if (_objectInHand != nullptr) {

		if (_objectInHand->getType() == ItemType::Tool) {//if its a tool

			return _objectInHand->getGatheringPower();
		}

		return 0;	//other items (with no gathering power)
	}

	return 1;	//bare hands
}

std::vector<Building*>& Player::getCraftingTablesVector() {
	return _craftingTables;
}


std::vector<Building*>& Player::getFireStationsVector() {
	return _fire;
}

std::vector<Building*>& Player::getBuildingVector() {
	return _buildingVector;
}