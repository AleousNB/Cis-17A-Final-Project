#pragma once
#include "Creature.h"

class Orc : virtual public Creature
{
protected:
	int _strength;
public:
	Orc(std::string name);
	~Orc();
	std::string Attack();
};

