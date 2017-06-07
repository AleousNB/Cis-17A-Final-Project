#include "Dragon.h"



Dragon::Dragon(std::string name): Orc(name), Wraith(name), Creature(name)
{
	_monsterType = "Dragon";
	_health = 500;
	_strength = 200;
	_mana = 500;
	_speed = 200;
}


Dragon::~Dragon()
{
}

std::string Dragon::Attack()
{
	std::string output = "releases a torrent of flame engulfing their surroundings with heat and devastation";
	return output;
}
