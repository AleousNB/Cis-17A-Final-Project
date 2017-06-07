#pragma once
#include "UrukHai.h"
#include "Wraith.h"

class Dragon: public Orc, public Wraith
{
private:
	int _speed;
public:
	Dragon(std::string name);
	~Dragon();
	std::string Attack();
};

