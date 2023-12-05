#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Item.h"



class Crate : public sf::RectangleShape, public Item
{
private:
	int _id;
	int _life;

	float _lifeTime;

	std::vector<Crate*>* _crateVector;		//vector of which the crate is member of
public:
	Crate(std::vector<Crate*>* crateVector, const sf::Vector2f& position, const Item& itemContent);		//constructor
	~Crate();															//destructor

	void onAttacked();

	int getLife()const;

	//only use in destructor, do not call anywhere else, lowers the vector id of the object
	void lowerId();			

	void update(const float& deltaTime);

	Item* getItem();
};
