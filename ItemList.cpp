#include <string>
#include <vector>

#include "Item.h"
#include "ItemList.h"

std::string ItemType::getStrType(const ItemType::type type)
{
	return ItemType::getStrType(int(type));
}

std::string ItemType::getStrType(const int type)
{
	switch (type)//returns the string of the type (invalid if not found)
	{
	case ItemType::type::NullType:
		return "Nulltype";
		break;

	case ItemType::type::Tool :
		return "Tool";
		break;

	case ItemType::type::Weapon :
		return "Weapon";
		break;

	case ItemType::type::Armor :
		return "Armor";
		break;

	case ItemType::type::Utility:
		return "Utility";
		break;

	case ItemType::type::Upgrade:
		return "Upgrade";
		break;

	case ItemType::type::Ressource:
		return "Ressource";
		break;

	case ItemType::type::Food:
		return "Food";
		break;

	case ItemType::type::Building :
		return "Building";
		break;

	case ItemType::type::Seed:
		return "Seed";
		break;
	
	default:
		return "Invalid";
		break;
	}
}

ItemType::type ItemType::getType(const int type)
{
	switch (type)//returns the string of the type (invalid if not found)
	{
	case ItemType::type::NullType:
		return ItemType::type::NullType;
		break;

	case ItemType::type::Tool:
		return ItemType::type::Tool;
		break;

	case ItemType::type::Weapon:
		return ItemType::type::Weapon;
		break;

	case ItemType::type::Armor:
		return ItemType::type::Armor;
		break;

	case ItemType::type::Utility:
		return ItemType::type::Utility;
		break;

	case ItemType::type::Upgrade:
		return ItemType::type::Upgrade;
		break;

	case ItemType::type::Ressource:
		return ItemType::type::Ressource;
		break;

	case ItemType::type::Food:
		return ItemType::type::Food;
		break;

	case ItemType::type::Building:
		return ItemType::type::Building;
		break;

	case ItemType::type::Seed:
		return ItemType::type::Seed;
		break;

	default:
		return ItemType::type::NullType;
		break;
	}
}

std::string ToolName::getStrName(const ToolName::name name)
{
	return  ToolName::getStrName(int(name));
}

std::string ToolName::getStrName(int name)
{

	switch (name)//returns the string of the tool (invalid if not found)
	{
	case ToolName::NullName:
		return "NullName";
		break;

	case ToolName::name::WoodenPickaxe :
		return "Wooden Pickaxe";
		break;

	case ToolName::name::StonePickaxe:
		return "Stone Pickaxe";
		break;

	case ToolName::name::GoldPickaxe:
		return "Gold Pickaxe";
		break;
	default:
		return "Invalid";
		break;
	}
}

std::string ToolName::getDesc(const ToolName::name name)
{
	return ToolName::getDesc(int(name));
}

std::string ToolName::getDesc(const int name)
{
	switch (name)//returns the string of the tool (invalid if not found)
	{
	case ToolName::NullName:
		return "NullName";
		break;

	case ToolName::name::WoodenPickaxe:
		return "Better than gathering by hand, can min stone";
		break;

	case ToolName::name::StonePickaxe:
		return "Can mine gold";
		break;

	case ToolName::name::GoldPickaxe:
		return "This is some real Gucci stuff";
		break;
	default:
		return "Invalid";
		break;
	}
}
ToolName::name ToolName::getName(const int name)
{
	switch (name)
	{
	case ToolName::name::NullName:
		return ToolName::name::NullName;
		break;
	case ToolName::name::WoodenPickaxe:
		return ToolName::name::WoodenPickaxe;
		break;

	case ToolName::name::StonePickaxe:
		return ToolName::name::StonePickaxe;
		break;

	case ToolName::name::GoldPickaxe:
		return ToolName::name::GoldPickaxe;
		break;

	default:
		return ToolName::name::NullName;
		break;
	}
}

std::string WeaponName::getStrName(const WeaponName::name name)
{
	return WeaponName::getStrName(int(name));
}

std::string WeaponName::getStrName(int name)
{
	switch (name)//returns the string of the weapon (invalid if not found)
	{
	case WeaponName::name::NullName:
		return "NullName";
		break;

	case WeaponName::name::WoodenSword:
		return "Wooden Sword";
		break;

	case WeaponName::name::StoneSword:
		return "Stone Sword";
		break;

	case WeaponName::name::GoldSword:
		return "Gold Sword";
		break;
	default:
		return "Invalid";
		break;
	}
}

std::string WeaponName::getDesc(const WeaponName::name name)
{
	return WeaponName::getDesc(int(name));
}

std::string WeaponName::getDesc(const int name)
{
	switch (name)//returns the string of the weapon (invalid if not found)
	{
	case WeaponName::name::NullName:
		return "NullName";
		break;

	case WeaponName::name::WoodenSword:
		return "A Basic Sword, Attack: 14";
		break;

	case WeaponName::name::StoneSword:
		return "A Real Warrior, Attack: 18";
		break;

	case WeaponName::name::GoldSword:
		return "A King's Weapon, Attack: 24";
		break;
	default:
		return "Invalid";
		break;
	}
}
WeaponName::name WeaponName::getName(const int name)
{
	switch (name)//returns the string of the weapon (invalid if not found)
	{
	case WeaponName::name::NullName:
		return WeaponName::name::NullName;
		break;

	case WeaponName::name::WoodenSword:
		return WeaponName::name::WoodenSword;
		break;

	case WeaponName::name::StoneSword:
		return WeaponName::name::StoneSword;
		break;

	case WeaponName::name::GoldSword:
		return WeaponName::name::GoldSword;
		break;
	default:
		return WeaponName::name::NullName;
		break;
	}
}

std::string ArmorName::getStrName(const ArmorName::name name)
{
	return ArmorName::getStrName(int(name));
}

std::string ArmorName::getStrName(int name)
{
	switch (name)//returns the string of the armor (invalid if not found)
	{
	case ArmorName::name::NullName :
		return "NullName";
		break;

	case ArmorName::name::MiniChapka:
		return "Mini Chapka";
		break;

	case ArmorName::name::Chapka:
		return "Chapka";
		break;

	case ArmorName::name::WoodenHelmet :
		return "Wooden Helmet";
		break;

	case ArmorName::name::StoneHelmet :
		return "Stone Helmet";
		break;

	case ArmorName::name::GoldHelmet :
		return "Gold Helmet";
		break;

	default:
		return "Invalid";
		break;
	}
}

std::string ArmorName::getDesc(const ArmorName::name name)
{
	return ArmorName::getDesc(int(name));
}

std::string ArmorName::getDesc(const int name)
{
	switch (name)//returns the string of the armor (invalid if not found)
	{
	case ArmorName::name::NullName:
		return "NullName";
		break;

	case ArmorName::name::MiniChapka:
		return "Can protect from cold a little bit";
		break;

	case ArmorName::name::Chapka:
		return "A real pocket bear, protects from cold moderately";
		break;

	case ArmorName::name::WoodenHelmet:
		return "Better than nothing, defense : 5";
		break;

	case ArmorName::name::StoneHelmet:
		return "A strong one, defense : 8";
		break;

	case ArmorName::name::GoldHelmet:
		return "Feeling shiny, defense : 10";
		break;

	default:
		return "Invalid";
		break;
	}
}

ArmorName::name ArmorName::getName(const int name)
{
	switch (name)//returns the string of the armor (invalid if not found)
	{
	case ArmorName::name::NullName:
		return ArmorName::name::NullName;
		break;

	case ArmorName::name::MiniChapka:
		return ArmorName::name::MiniChapka;
		break;

	case ArmorName::name::Chapka:
		return ArmorName::name::Chapka;
		break;

	case ArmorName::name::WoodenHelmet:
		return ArmorName::name::WoodenHelmet;
		break;

	case ArmorName::name::StoneHelmet:
		return ArmorName::name::StoneHelmet;
		break;

	case ArmorName::name::GoldHelmet:
		return  ArmorName::name::GoldHelmet;
		break;

	default:
		return ArmorName::name::NullName;
		break;
	}
}

std::string UtilityName::getStrName(const UtilityName::name name)
{
	return UtilityName::getStrName(int(name));
}

std::string UtilityName::getStrName(int name)
{
	switch (name)//returns the string of the utility (invalid if not found)
	{
	case UtilityName::name::NullName:
		return "NullName";
		break;

	case UtilityName::name::Book :
		return "Book";
		break;

	default:
		return "Invalid";
		break;
	}
}

std::string UtilityName::getDesc(const UtilityName::name name)
{
	return UtilityName::getDesc(int(name));
}

std::string UtilityName::getDesc(const int name)
{
	switch (name)//returns the string of the utility (invalid if not found)
	{
	case UtilityName::name::NullName:
		return "NullName";
		break;

	case UtilityName::name::Book:
		return "Can be useful for crafting stuff faster";
		break;

	default:
		return "Invalid";
		break;
	}
}

UtilityName::name UtilityName::getName(const int name)
{
	switch (name)//returns the string of the utility (invalid if not found)
	{
	case UtilityName::name::NullName:
		return UtilityName::name::NullName;
		break;

	case UtilityName::name::Book:
		return UtilityName::name::Book;
		break;

	default:
		return UtilityName::name::NullName;
		break;
	}
}

std::string UpgradeName::getStrName(const UpgradeName::name name)
{
	return UpgradeName::getStrName(int(name));
}

std::string UpgradeName::getStrName(int name)
{
	switch (name)//returns the string of the upgrade (invalid if not found)
	{
	case UpgradeName::name::NullName:
		return "NullName";
		break;

	case UpgradeName::name::BackPack:
		return "BackPack";
		break;

	default:
		return "Invalid";
		break;
	}
}

std::string UpgradeName::getDesc(const UpgradeName::name name)
{
	return UpgradeName::getDesc(int(name));
}

std::string UpgradeName::getDesc(const int name)
{
	switch (name)//returns the string of the upgrade (invalid if not found)
	{
	case UpgradeName::name::NullName:
		return "NullName";
		break;

	case UpgradeName::name::BackPack:
		return "Can carry more things around";
		break;

	default:
		return "Invalid";
		break;
	}
}

UpgradeName::name UpgradeName::getName(const int name)
{
	switch (name)//returns the string of the upgrade (invalid if not found)
	{
		case UpgradeName::name::NullName:
			return UpgradeName::name::NullName;
			break;

		case UpgradeName::name::BackPack:
			return UpgradeName::name::BackPack;
			break;

		default:
			return UpgradeName::name::NullName;
			break;
	}
}

std::string RessourceName::getStrName(const RessourceName::name name)
{
	return RessourceName::getStrName(int(name));
}

std::string RessourceName::getStrName(int name)
{
	switch (name)//returns the string of the ressource (invalid if not found)
	{
	case RessourceName::name::NullName:
		return "NullName";
		break;

	case RessourceName::name::Wood:
		return "Wood";
		break;

	case RessourceName::name::Stone:
		return "Stone";
		break;

	case RessourceName::name::Gold:
		return "Gold";
		break;

	case RessourceName::name::RabbitFur:
		return "Rabbit Fur";
		break;

	case RessourceName::name::WolfFur:
		return "Wolf Fur";
		break;

	case RessourceName::name::String:
		return "String";
		break;

	case RessourceName::name::Paper:
		return "Paper";
		break;

	default:
		return "Invalid";
		break;
	}
}

std::string RessourceName::getDesc(const RessourceName::name name)
{
	return RessourceName::getDesc(int(name));
}

std::string RessourceName::getDesc(const int name)
{
	switch (name)//returns the string of the ressource (invalid if not found)
	{
	case RessourceName::name::NullName:
		return "NullName";
		break;

	case RessourceName::name::Wood:
		return "The essence of survival";
		break;

	case RessourceName::name::Stone:
		return "Better than wood";
		break;

	case RessourceName::name::Gold:
		return "The proof of strength";
		break;

	case RessourceName::name::RabbitFur:
		return "Can't run away from me now";
		break;

	case RessourceName::name::WolfFur:
		return "It seems warm at touch";
		break;

	case RessourceName::name::String:
		return "This may be useful to create bandages";
		break;

	case RessourceName::name::Paper:
		return "Can't imagine what it can be used for";
		break;

	default:
		return "Invalid";
		break;
	}
}

std::string FoodName::getStrName(const FoodName::name name)
{
	return FoodName::getStrName(int(name));
}

std::string FoodName::getStrName(int name)
{
	switch (name)//returns the string of the food (invalid if not found)
	{
	case FoodName::name::NullName :
		return "NullName";
		break;

	case FoodName::name::Berries :
		return "Berries";
		break;

	case FoodName::name::Steak :
		return "Steak";
		break;

	case FoodName::name::CookedSteak :
		return "Cooked Steak";
		break;
	default:
		return "Invalid";
		break;
	}
}

std::string FoodName::getDesc(const FoodName::name name)
{
	return FoodName::getDesc(int(name));
}

std::string FoodName::getDesc(const int name)
{
	switch (name)//returns the string of the food (invalid if not found)
	{
	case FoodName::name::NullName:
		return "NullName";
		break;

	case FoodName::name::Berries:
		return "Vegan sigma grindset : 15 food";
		break;

	case FoodName::name::Steak:
		return "Maybe cook it before eating?";
		break;

	case FoodName::name::CookedSteak:
		return "Thats some good food : 35 food";
		break;
	default:
		return "Invalid";
		break;
	}
}

std::string BuildingName::getStrName(const BuildingName::name name)
{
	return BuildingName::getStrName(int(name));
}

std::string BuildingName::getStrName(int name)
{
	switch (name)//returns the string of the build (invalid if not found)
	{
	case BuildingName::name::NullName:
		return "NullName";
		break;

	case BuildingName::name::Bridge :
		return "Bridge";
		break;

	case BuildingName::name::Roof:
		return "Roof";
		break;

	case BuildingName::name::WoodenWall:
		return "WoodenWall";
		break;

	case BuildingName::name::WoodenDoor:
		return "WoodenDoor";
		break;

	case BuildingName::name::StoneWall:
		return "StoneWall";
		break;

	case BuildingName::name::StoneDoor:
		return "StoneDoor";
		break;

	case BuildingName::name::GoldWall:
		return "GoldWall";
		break;

	case BuildingName::name::GoldDoor:
		return "GoldDoor";
		break;

	case BuildingName::name::Flag:
		return "Flag";
		break;

	case BuildingName::name::CraftingTable:
		return "CraftingTable";
		break;

	case BuildingName::name::SmallCampfire:
		return "SmallCampfire";
		break;

	case BuildingName::name::BigCampfire:
		return "BigCampfire";
		break;

	case BuildingName::name::Furnace:
		return "Furnace";
		break;

	default:
		return "Invalid";
		break;
	}
}

std::string BuildingName::getDesc(const BuildingName::name name)
{
	return BuildingName::getDesc(int(name));
}

std::string BuildingName::getDesc(const int name)
{
	switch (name)//returns the string of the build (invalid if not found)
	{
	case BuildingName::name::NullName:
		return "NullName";
		break;

	case BuildingName::name::Bridge:
		return "Can be put on top of water";
		break;

	case BuildingName::name::Roof:
		return "Can protect you from environment a little bit";
		break;

	case BuildingName::name::WoodenWall:
		return "Basic defense, Life : 500";
		break;

	case BuildingName::name::WoodenDoor:
		return "Can be opened, Life : 500";
		break;

	case BuildingName::name::StoneWall:
		return "Medium defense, Life : 1000";
		break;

	case BuildingName::name::StoneDoor:
		return "A stronger door, Life : 1000";
		break;

	case BuildingName::name::GoldWall:
		return "A Gucci defense, Life : 1500";
		break;

	case BuildingName::name::GoldDoor:
		return "A door to the Gucci house, Life : 1500";
		break;

	case BuildingName::name::Flag:
		return "A Waypoint to see where you are going";
		break;

	case BuildingName::name::CraftingTable:
		return "Used for crafting stuff";
		break;

	case BuildingName::name::SmallCampfire:
		return "A small campfire that can last 5 minutes";
		break;

	case BuildingName::name::BigCampfire:
		return "A bigger campfire that can last 15 minutes";
		break;

	case BuildingName::name::Furnace:
		return "Can last as long as alimented";
		break;

	default:
		return "Invalid";
		break;
	}
}

std::string SeedName::getStrName(const SeedName::name name)
{
	return SeedName::getStrName(int(name));
}

std::string SeedName::getStrName(int name)
{
	switch (name)			//returns the string of the seed (invalid if not found)
	{
	case SeedName::name::NullName:
		return "NullName";
		break;

	case SeedName::name::BerriesSeed:
		return "Berries Seed";
		break;

	default:
		return "Invalid";
		break;
	}
}

std::string SeedName::getDesc(const SeedName::name name)
{
	return SeedName::getDesc(int(name));
}

std::string SeedName::getDesc(const int name)
{
	switch (name)			//returns the string of the seed (invalid if not found)
	{
	case SeedName::name::NullName:
		return "NullName";
		break;

	case SeedName::name::BerriesSeed:
		return "Takes 90 seconds to grow, provide berries every 15 seconds";
		break;

	default:
		return "Invalid";
		break;
	}
}

std::string CraftingStations::getStrName(const CraftingStations::stations station)
{
	switch (station)
	{
	case CraftingStations::CraftingTable:
		return "Crafting Table";
		break;

	case CraftingStations::Water:
		return "Water";
		break;

	case CraftingStations::Fire:
		return "Fire";
		break;

	default:				//if it returns this, the crafting station is not listed above
		return "Invalid";
		break;
	}
}

std::string CraftingStations::getStrName(const int station)
{
	if (station >= CraftingStations::stations::CraftingTable && station < CraftingStations::stations::End) {
		return CraftingStations::getStrName(CraftingStations::stations(station));
	}

	return "Invalid";
}
