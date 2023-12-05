#pragma once
#include <SFML/Graphics.hpp>


class Solid
{
private:
	long long int _id;	//position of the solid in the solids/solidsVector vector on 64 bit integer

	sf::Shape* _owner;	//the owner


	Solid(const Solid& right);

public:
	Solid();//default (not solid)
	Solid(sf::Shape* collision, const sf::Vector2i& chunkPos);		//constructor
	~Solid();							//destructor

	sf::Shape* getOwner();				//not in const because sometimes we may want to move every solids

	virtual void lowerSolidId();		//lower the solid's _id in the solids vector
};

bool isCollisionWithSolids(const sf::Shape* shape);		//returns true if shape is in collision with any solids