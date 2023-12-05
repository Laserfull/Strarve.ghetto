#pragma once
#include "Item.h"
#include "SpriteSheet.h"

class ItemSlot : public sf::RectangleShape , public Item
{
protected:
	//update the texture
	void updateItemSlotTexture();

	//update the text
	void updateText();

private:
	sf::RectangleShape _item;
	sf::Text _amountOfItem;

	SpriteSheet* _itemSpriteSheet;



public:
						//constructors

	//default constructor
	ItemSlot();
	ItemSlot(const Item& item);

						//updaters

	// updates the itemSlot by updating its item amount shown and texture
	void updateItemSlot();				



						//setters

	//set the position of the slot
	void setPosition(const sf::Vector2f& newPosition);

	//move the ItemSlot by the movement sent in parameter
	void move(const sf::Vector2f& movement);
	//move the ItemSlot by the movement sent in parameter 
	void move(float x, float y);

	//set the size of the slot
	void setSize(const sf::Vector2f& newSize);
	
						//virtual setters

	//sets Item::_amount
	void setAmount(int newAmount);

	//set Item::_type
	void setType(const ItemType::type type);	
	//set Item::_name (needs to have the type set)
	void setName(const int name);									


									//		virtual adder			//

	//amount to add has to be >=0
	void addAmount(int amountToAdd);

	//amount to substract (has to be >=0 && not get the amount to negative)
	void substractAmount(int amountToSubstract);

						//getters

	//get the position
	const sf::Vector2f& getPosition();

	//get the size
	const sf::Vector2f& getSize();


						//draw
	//draw on screen
	virtual void draw(sf::RenderWindow* window) const;



						//operators

	//change the container
	void operator=(const Item& rightItem);
	void operator=(const ItemSlot& rightSlot);
};

