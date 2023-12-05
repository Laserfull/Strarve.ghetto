#pragma once
#include <string>
#include <vector>
#include "ItemList.h"

class Item
{
protected:
	int _amount;

	ItemType::type _type;
	int _name;
	
	
public:
				//		constructor		//

	Item();																		//default constructor


	Item(const ToolName::name name, int amount = 1);							//tool constructor
	Item(const WeaponName::name name, int amount = 1);							//weapon constructor
	Item(const ArmorName::name name, int amount = 1);							//armor constructor
	Item(const UtilityName::name name, int amount = 1);							//utility constructor
	Item(const UpgradeName::name name, int amount = 1);							//upgrade constructor
	Item(const RessourceName::name name, int amount = 1);						//ressource constructor
	Item(const FoodName::name name, int amount = 1);							//food constructor
	Item(const BuildingName::name name, int amount = 1);						//building constructor
	Item(const SeedName::name name, int amount = 1 );							//seed constructor

	Item(const Item& otherItem);												// creates a copy of the otherItem

	~Item();

				//		getters			//

	int getAmount() const;						//get _amount
	ItemType::type getType()const;				//get _type
	int getName()const;							//get _name
	std::string getDescription() const;	//get _description

	std::string getStrType();		//get the type in string (Invalid if not found)
	std::string getStrName();		//get the name in string (Invalid if not found)


				//		setters			//

	virtual void setAmount(int amount);										//set _amount (assert >=0)
	virtual void setType(const ItemType::type type);						//set _type
	virtual void setName(const int name);									//set _name (needs to have the type set)


				//		adder			//
				
				//amount to add has to be >=0
	virtual void addAmount(int amountToAdd);								

				//amount to substract (has to be >=0 && not get the amount to negative)
	virtual void substractAmount(int amountToSubstract);					

				//		comparators		//
				
	//returns true if inventory is containing the item with at least minAmount in				
	//minAmount has to be greater or equal to 0
	bool isContainedIn(const std::vector<Item*>& inventory, int minAmount) const;

	//returns true if inventory is containing the item
	bool isContainedIn(const std::vector<Item*>& inventory) const;

				//		operator		//

	virtual void operator=(const Item& rightItem);									//this gets the amount, type, name and description properties from rightItem
	friend bool operator==(const Item& leftItem, const Item& rightItem);	//returns true if the items are of the same type and name
	friend bool operator!=(const Item& leftItem, const Item& rightItem);	//returns true if the items are of the same type and name
};

