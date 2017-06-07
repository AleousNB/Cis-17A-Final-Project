#include "Maia.h"



Maia::Maia(std::string name):Creature(name)
{
	_monsterType = "Maia";
	_health = 9999;
}


Maia::~Maia()
{
}

std::string Maia::Attack()
{
	std::string output = "ignores you";
	return output;
}