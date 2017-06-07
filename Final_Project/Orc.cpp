#include "Orc.h"



Orc::Orc(std::string name): Creature(name)
{
	_monsterType = "Orc";
	_health = 120;
	_strength = 50;
}


Orc::~Orc()
{
}

std::string Orc::Attack()
{
	std::string output = "yells and repeatedly hammers their shield";
	return output;
}