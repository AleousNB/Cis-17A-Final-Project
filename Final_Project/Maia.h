#pragma once
#include "Creature.h"

class Maia: public Creature
{
public:
	Maia(std::string name);
	~Maia();
	std::string Attack();
};

