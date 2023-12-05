#include "Solid.h"
#include <assert.h>
#include <vector>
#include "Game.h"

extern Game* gameInfo;

Solid::Solid()
{
	_owner = nullptr;
	_id = NULL;
}

Solid::Solid(sf::Shape* collision,const sf::Vector2i& chunkPos)
{
	_id = NULL;
	if(collision != nullptr)
	{

		_owner = collision;

		
		gameInfo->getChunk(chunkPos)->solids.push_back(this); //add to solid vector of the chunk
	}
	else {
		_owner = nullptr;
		_id = NULL;
	}
}

Solid::~Solid()
{
	if(_owner != nullptr)			//if solid is initialised
	{
		//erase from public vector

		
		sf::Vector2i cPos(gameInfo->getChunkFromPos(sf::Vector2f{ _owner->getPosition()}));
		//erase from public vector

		//delete from solid vector in the chunk
		int i = 0;
		for (auto it : gameInfo->getChunk(cPos)->solids) {
			if (it == this) {//if found delete it
				gameInfo->getChunk(cPos)->solids.erase(gameInfo->getChunk(cPos)->solids.begin()+i);
				break;
			}
			i++;
		}
	}

	_id = NULL;			//uninitialize id
	_owner = nullptr;	//uninitalise pointer
}

sf::Shape* Solid::getOwner()
{
	return _owner;
}

void Solid::lowerSolidId()
{
	assert(_id > 0);
	_id--;
}

bool isCollisionWithSolids(const sf::Shape* shape)
{
	auto cPos(gameInfo->getChunkFromPos(sf::Vector2f{ shape->getPosition() }));

	//do the verification in a 3x3 grid of the chunks around the position of the object

	for (int i=-1;i<1; i++)
	{
		for(int j=-1; j<1;j++)
		{
			if(gameInfo->isChunk({ cPos.x + i, cPos.y + j }))		//if chunk is loaded
			{
				for (Solid* solid : gameInfo->getChunk({cPos.x + i, cPos.y + j})->solids) {
					if (solid->getOwner() != shape && solid->getOwner()->getGlobalBounds().intersects(shape->getGlobalBounds())) {//if collision (not with itself) return true
						return true;
					}
				}
			}
		}
	}

	return false;
}