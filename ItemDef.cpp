


#include "ItemDef.h"



ItemDef::ItemDef()
{
	_type = ItemType::type::NullType;
	_name = 0;
	
}

ItemDef::ItemDef(const Item& item)
{
	_type = item.getType();
	_name = item.getName();
}
