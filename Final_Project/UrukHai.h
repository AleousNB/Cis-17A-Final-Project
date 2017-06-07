#pragma once
#include "Orc.h"

class UrukHai: public Orc
{
protected:
	int _constitution;
public:
	UrukHai(std::string name);
	~UrukHai();
	std::string Attack();
};

