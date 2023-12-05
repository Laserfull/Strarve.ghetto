#pragma once

#include<SFML/Graphics.hpp>

class ChunkPos: public sf::Vector2i
{
public:
	ChunkPos(sf::Vector2i vect);


	bool operator> (ChunkPos);
};
