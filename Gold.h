#pragma once
#include "RessourcePoint.h"

class Gold : public RessourcePoint
{
private:

public:
	Gold(const sf::Vector2f& spawnPoint, const sf::Vector2i chunkPos);
};

