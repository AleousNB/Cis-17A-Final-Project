#include "UrukHai.h"



UrukHai::UrukHai(std::string name) :Orc(name), Creature(name)
{
	_monsterType = "Uruk Hai";
	_health = 150;
	_strength = 80;
	_constitution = 60;
}


UrukHai::~UrukHai()
{
}


std::string UrukHai::Attack()
{
	std::string output = "lifts their giant axe and starts destroying nearby items";
	return output;
}