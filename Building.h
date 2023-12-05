#pragma once
#include "Solid.h"

class Building: 
	public sf::RectangleShape,
	public Item,
	public SpriteSheet
{
private:

	Solid* _solid = nullptr;
	int _id = -1;
	int _craftId = -1;
	int _life;

	float _timer = 0;

	bool _death = false;

	//disable default constructors
	Building();
	Building(const Building& build );
public:
	Building(const Item& item);
	~Building();




	//makes it solid
	void placeBuilding();

	void update(float deltaTime);

	//lower the id
	void lowerId();
	// lower the craftingid
	void lowerCraftId();

};

