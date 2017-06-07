#include "Wraith.h"



Wraith::Wraith(std::string name):Creature(name)
{
	_monsterType = "Wraith";
	_health = 225;
	_mana = 100;
}


Wraith::~Wraith()
{
}

std::string Wraith::Attack()
{
	std::string output = "forces out a terrifying high-pitched screech/roar";
	return output;
}
