#pragma once
#include "Creature.h"

class Wraith: virtual public Creature
{
protected:
	int _mana;
public:
	Wraith(std::string name);
	~Wraith();
	std::string Attack();
};

