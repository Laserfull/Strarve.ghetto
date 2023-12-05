#pragma once
#include "Item.h"

class ItemDef
{
private:
	ItemDef(const ItemDef& item);

public:

	int _type;
	int _name;
	ItemDef();
	ItemDef(const Item& item);


};

