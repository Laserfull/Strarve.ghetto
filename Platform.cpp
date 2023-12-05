#include "Platform.h"
#include "Solid.h"
#include "Game.h"

extern Game* gameInfo;


Platform::Platform(sf::Shape* hitbox)
{
	_platformer = hitbox;
}

sf::Vector2f& Platform::getPlatformMove(const sf::Vector2f& movement)
{
	sf::Vector2f newMovement = movement;

								//calculate x
	if(newMovement.x !=0)
	{
		bool stop(false);

		_platformer->move(newMovement.x, 0);

		auto cPos(gameInfo->getChunkFromPos(_platformer->getPosition()));

		//check in 3x3 chunk around

		for (int i = -3; i <= 3; i++)
		{
			for (int j = -3; j <= 3; j++)
			{
				if(gameInfo->isChunk({ cPos.x + i ,cPos.y + j })) //check if is a chunk
				{
					for (auto solid : gameInfo->getSolidsVector({ cPos.x + i ,cPos.y + j })) {
						if (_platformer->getGlobalBounds().intersects(solid->getOwner()->getGlobalBounds())) {//if collision, unmove and no y movement

							_platformer->move(-newMovement.x, 0);
							newMovement.x = 0;
							stop = true;
							break;
						}
					}
					if (stop) {
						break;
					}
				}
			}
			if (stop) {
				break;
			}
		}

		
	}

								//calculate y



	if (newMovement.y != 0)
	{
		bool stop(false);

		_platformer->move(0, newMovement.y);

		auto cPos(gameInfo->getChunkFromPos(_platformer->getPosition()));

		//check in 3x3 chunk around

		for (int i = -3; i <= 3; i++)
		{
			for (int j = -3; j <= 3; j++)
			{
				if (gameInfo->isChunk({ cPos.x + i ,cPos.y + j })) // check if is a chunk
				{
					for (auto solid : gameInfo->getSolidsVector({ cPos.x + i ,cPos.y + j })) {
						if (_platformer->getGlobalBounds().intersects(solid->getOwner()->getGlobalBounds())) {//if collision, unmove and no y movement

							_platformer->move(0, -newMovement.y);
							newMovement.y = 0;
							stop = true;
							break;
						}
					}
				}
				if (stop) {
					break;
				}
			}
			if (stop) {
				break;
			}
		}
	}

	return newMovement;
}
