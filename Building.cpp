#include <SFML/Graphics.hpp>
#include <assert.h>


#include "SpriteSheet.h"
#include "Item.h"
#include "Game.h"


#include "Building.h"


extern Game* gameInfo;
extern sf::Texture* buildingTexture;


#define playerBuildings gameInfo->getPlayer().getBuildingVector()

#define playerCraftingTables gameInfo->getPlayer().getCraftingTablesVector()
#define playerFireStations gameInfo->getPlayer().getFireStationsVector()

Building::Building(const Item& item) :Item(item), SpriteSheet(this, buildingTexture, {4,4})
{
	assert(_type == ItemType::Building || _type == ItemType::Seed);					//has to be a seed or a building

	this->setSize({ gameInfo->getUnit().x * 300,gameInfo->getUnit().y * 300 });		//set the size & origin
	this->setOrigin({ this->getSize().x / 2,this->getSize().y / 2 });

	_life = 200;

	switch(_type)
	{
	case ItemType::Building:

		switch (_name)
		{

		case BuildingName::name::WoodenWall: case BuildingName::name::StoneWall: case BuildingName::name::GoldWall:
			this->setSpritePosition({ 0,1 });

			switch (_name)//color definition
			{
			case BuildingName::name::WoodenWall:
				this->setFillColor(sf::Color(98, 52, 18));
				_life = 500;
				break;

			case BuildingName::name::StoneWall:
				this->setFillColor(sf::Color(146, 148, 151));
				_life = 1000;
				break;

			case BuildingName::name::GoldWall:
				this->setFillColor(sf::Color::Yellow);
				_life = 1500;
				break;
			}

			break;

		case BuildingName::name::WoodenDoor: case BuildingName::name::StoneDoor: case BuildingName::name::GoldDoor://door texture
			this->setSpritePosition({ 1,1 });

			switch (_name)//color definition
			{
			case BuildingName::name::WoodenDoor:
				this->setFillColor(sf::Color(98, 52, 18));
				_life = 500;
				break;

			case BuildingName::name::StoneDoor:
				this->setFillColor(sf::Color(146, 148, 151));
				_life = 1000;
				break;

			case BuildingName::name::GoldDoor:
				this->setFillColor(sf::Color::Yellow);
				_life = 1500;
				break;
			}

			break;

		case BuildingName::Flag:
			this->setSpritePosition({ 2,1 });
			break;

		case BuildingName::SmallCampfire:
			this->setSpritePosition({ 0,0 });
			_timer = 180;
			break;

		case BuildingName::BigCampfire:
			this->setSpritePosition({ 1,0 });
			_timer = 480;
			break;

		case BuildingName::Furnace:
			this->setSpritePosition({ 2,0 });
			break;

		case BuildingName::CraftingTable:
			this->setSpritePosition({ 3,0 });
			break;

		case BuildingName::Bridge:
			this->setSpritePosition({ 0,2 });
			break;

		case BuildingName::Roof:
			this->setSpritePosition({ 1,2 });
			break;
		}

		break;

	case ItemType::Seed:

		switch (_name) {
		case SeedName::BerriesSeed:
			this->setSpritePosition({ 0,3 });
			_timer = 120;
			break;
		}

		break;
	}


	this->setFillColor({ this->getFillColor().r, this->getFillColor().g, this->getFillColor().b, 100 });//set to transparent
}

Building::~Building()
{
	if (_id != -1) {//if solid

		playerBuildings.erase(playerBuildings.begin() + _id);

		//lower the id of the others
		for (std::vector<Building*>::iterator it = (playerBuildings.begin() + _id); it != playerBuildings.end(); it++, _id++) {
			playerBuildings[_id]->lowerId();
		}

		if (_craftId != -1) {
			if (this->getType() != ItemType::Building) {//if not building crash
				assert(false);
			}
			else {
				if (this->getName() == BuildingName::CraftingTable) {//if is a crafting table
					playerCraftingTables.erase(playerCraftingTables.begin()+_craftId);

					//lower the id of the others
					for (std::vector<Building*>::iterator it = (playerCraftingTables.begin() + _craftId); it != playerCraftingTables.end(); it++, _craftId++) {
						playerCraftingTables[_craftId]->lowerCraftId();
					}
				}
				else {//if is a firestation
					playerFireStations.erase(playerFireStations.begin() + _craftId);

					//lower the id of the others
					for (std::vector<Building*>::iterator it = (playerFireStations.begin() + _craftId); it != playerFireStations.end(); it++, _craftId++) {
						playerFireStations[_craftId]->lowerCraftId();
					}
				}
			}
		}

	}

	if (_solid != nullptr) {//destroy solid if was solid
		_solid->~Solid();
		_solid = nullptr;
	}

	_id = NULL;
	_craftId = NULL;
	_timer = NULL;
}

void Building::placeBuilding()
{
	//if solid
	if ((_type != ItemType::Seed) && !(_type == ItemType::Building && (_name == BuildingName::Flag || _name == BuildingName::Bridge || _name == BuildingName::Roof || _name == BuildingName::SmallCampfire || _name == BuildingName::BigCampfire))) {
		_solid = new Solid(this, gameInfo->getChunkFromPos(this->getPosition()));
	}

	/*if (_type == ItemType::Building) {
		switch (_name) {
		case BuildingName::name::WoodenDoor:
		case BuildingName::name::WoodenWall:

			this->setFillColor(sf::Color(98, 52, 18));
			break;

		case BuildingName::name::StoneDoor:
		case BuildingName::name::StoneWall:

			this->setFillColor(sf::Color(146, 148, 151));
			break;

		case BuildingName::name::GoldDoor:
		case BuildingName::name::GoldWall:

			this->setFillColor(sf::Color::Yellow);
			break;

		default:

			this->setFillColor(sf::Color::White);
			break;
		}
	}*/
	this->setFillColor({ this->getFillColor().r, this->getFillColor().g, this->getFillColor().b, 255});//set to opaque

	_id = playerBuildings.size();
	playerBuildings.push_back(this);

	if (_type == ItemType::Building) {//if a building
		switch (_name) {
		case BuildingName::SmallCampfire://if a fire source add to player firestations
		case BuildingName::BigCampfire:
		case BuildingName::Furnace:

			_craftId = playerFireStations.size();
			playerFireStations.push_back(this);
			break;

		case BuildingName::CraftingTable://if a crafting table add to player crafting tables

			_craftId = playerCraftingTables.size();
			playerCraftingTables.push_back(this);
			break;
		}
	}

}

void Building::update(float deltaTime)
{
	switch (_type)
	{
	case ItemType::Building:

		switch (_name) {
		case BuildingName::SmallCampfire:
		case BuildingName::BigCampfire:

			_timer -= deltaTime;

			if (_timer <= 0) {
				_death = true;
			}

			break;
		}


		break;

	case ItemType::Seed:

		switch (_name) {
		case SeedName::BerriesSeed:
			_timer -= deltaTime;

			if (_timer <= 0) {		//if timer is done
				if (this->getSpritePosition() != sf::Vector2u{ 1, 3 })//if not a bush
				{
					this->setSpritePosition({ 1,3 });	//become a bush
					_timer = 15;
				}
				else {//if is in bush state

					//add item here

					_timer = 15;//restart timer
				}
			}

			break;
		}

		break;
	}

	if (_death) {//if dead destroy
		this->~Building();
	}

}

void Building::lowerId()
{
	assert(_id > 0);// if id is initialised

	_id--;
}

void Building::lowerCraftId()
{
	assert(_craftId > 0);// if id is initialised

	_craftId--;
}
