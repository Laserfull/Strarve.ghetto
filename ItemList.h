#pragma once


struct ItemType {
	enum type { NullType, Tool, Weapon, Armor, Utility, Upgrade, Ressource, Food, Building, Seed };		//list of types
	static std::string getStrType(const ItemType::type type);				//returns the string of the type
	static std::string getStrType(const int type);							//returns the string of the type (invalid if not found)

	static ItemType::type getType(const int type);
};

struct ToolName {
	enum name { NullName, WoodenPickaxe, StonePickaxe, GoldPickaxe };		//list of tool

	

	static std::string getStrName(const ToolName::name name);				//returns the string of the tool
	static std::string getStrName(const int name);							//returns the string of the tool (invalid if not found)

	static std::string getDesc(const ToolName::name name);					//returns the description of the tool
	static std::string getDesc(const int name);								//returns the description of the tool (invalid if not found)

	static ToolName::name getName(const int name);
};

struct WeaponName {
	enum name { NullName, WoodenSword, StoneSword, GoldSword };				//list of weapon

	static std::string getStrName(const WeaponName::name name);				//returns the string of the weapon 
	static std::string getStrName(const int name);							//returns the string of the weapon (invalid if not found)

	static std::string getDesc(const WeaponName::name name);				//returns the description of the weapon
	static std::string getDesc(const int name);								//returns the description of the weapon (invalid if not found)

	static WeaponName::name getName(const int name);
};

struct ArmorName {
	enum name { NullName, MiniChapka, Chapka, WoodenHelmet, StoneHelmet, GoldHelmet };		//list of armor

	static std::string getStrName(const ArmorName::name name);				//returns the string of the armor 
	static std::string getStrName(const int name);							//returns the string of the armor (invalid if not found)

	static std::string getDesc(const ArmorName::name name);					//returns the description of the armor
	static std::string getDesc(const int name);								//returns the description of the armor (invalid if not found)

	static ArmorName::name getName(const int name);
};

struct UtilityName {
	enum name { NullName, Book };									//list of utilities

	static std::string getStrName(const UtilityName::name name);			//returns the string of the utility
	static std::string getStrName(const int name);							//returns the string of the utility (invalid if not found)

	static std::string getDesc(const UtilityName::name name);				//returns the description of the utility
	static std::string getDesc(const int name);								//returns the description of the utility (invalid if not found)

	static UtilityName::name getName(const int name);
};

struct UpgradeName {
	enum name { NullName, BackPack };								//list of upgrades

	static std::string getStrName(const UpgradeName::name name);			//returns the string of the upgrade
	static std::string getStrName(const int name);							//returns the string of the upgrade (invalid if not found)

	static std::string getDesc(const UpgradeName::name name);				//returns the description of the upgrade
	static std::string getDesc(const int name);								//returns the description of the upgrade (invalid if not found)

	static UpgradeName::name getName(const int name);
};

struct RessourceName {
	enum name { NullName, Wood, Stone, Gold, RabbitFur, WolfFur, String, Paper};						//list of ressources

	static std::string getStrName(const RessourceName::name name);			//returns the string of the ressource
	static std::string getStrName(const int name);							//returns the string of the ressource (invalid if not found)

	static std::string getDesc(const RessourceName::name name);				//returns the description of the ressource
	static std::string getDesc(const int name);								//returns the description of the ressource (invalid if not found)
};

struct FoodName {
	enum name { NullName, Berries, Steak, CookedSteak };				//list of food

	static std::string getStrName(const FoodName::name name);				//returns the string of the food
	static std::string getStrName(const int name);							//returns the string of the food (invalid if not found)

	static std::string getDesc(const FoodName::name name);					//returns the description of the food
	static std::string getDesc(const int name);								//returns the description of the food (invalid if not found)
};

struct BuildingName {
	enum name { NullName, Bridge, Roof, WoodenWall, WoodenDoor, StoneWall, StoneDoor, GoldWall, GoldDoor, Flag, CraftingTable, SmallCampfire, BigCampfire, Furnace };			//list of building

	static std::string getStrName(const BuildingName::name name);			//returns the string of the build
	static std::string getStrName(const int name);							//returns the string of the build (invalid if not found)

	static std::string getDesc(const BuildingName::name name);				//returns the description of the building
	static std::string getDesc(const int name);								//returns the description of the building (invalid if not found)
};

struct SeedName {
	enum name { NullName, BerriesSeed };								//list of seed

	static std::string getStrName(const SeedName::name name);				//returns the string of the seed
	static std::string getStrName(const int name);							//returns the string of the seed (invalid if not found)

	static std::string getDesc(const SeedName::name name);					//returns the description of the seed
	static std::string getDesc(const int name);								//returns the description of the seed (invalid if not found)
};


struct CraftingStations {
	enum stations { CraftingTable, Water, Fire, End };								//list of crafting stations effects (not an item) and end is nothing

	static std::string getStrName(const CraftingStations::stations station); //returns the string of the crafting station
	static std::string getStrName(const int station);						 //returns the string of the crafting station (invalid if not found)
};

