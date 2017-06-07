#include "Creature.h"



using namespace std;

Creature::Creature(std::string name): _name(name)
{
	_monsterType = "Creature";
	_health = 80;
}

Creature::Creature()
{
}

Creature::~Creature()
{
}

std::string Creature::GetName()
{
	return _name;
}

std::string Creature::GetMonsterType()
{
	return _monsterType;
}

std::string Creature::ListSubordinates()
{
	std::string output = "\n";
	for (auto Monster : _Subordinates) {
		output += "*" + Monster->GetName();
		output += " the " + Monster->GetMonsterType() + "\n";
	}
	return output;
}

void Creature::AddMonster(std::shared_ptr<Creature> newMonster)
{
	_Subordinates.push_back(newMonster);
}

std::shared_ptr<Creature> Creature::FindMonster(std::string name)
{
	for (auto Monster : _Subordinates)
	{
		if (Monster->GetName() == name) {
			return Monster;
		}
	}
	return nullptr;
}

std::string Creature::GetStats(std::shared_ptr<Creature> currentMonster)
{
	std::string output;
	int Health = 0;
	int Mana = 0;
	int Strength = 0;
	int Constitution = 0;
	int Speed = 0;
	
	if (currentMonster->_monsterType == "Creature")
	{
		Health = 80, Mana = 0, Strength = 0, Constitution = 0, Speed = 0;
	}
	else if(currentMonster->_monsterType == "Orc")
	{
		Health = 120, Mana = 0, Strength = 50, Constitution = 0, Speed = 0;
	}
	else if (currentMonster->_monsterType == "Uruk Hai")
	{
		Health = 150, Mana = 0, Strength = 80, Constitution = 60, Speed = 0;
	}
	else if (currentMonster->_monsterType == "Wraith")
	{
		Health = 225, Mana = 100, Strength = 0, Constitution = 0, Speed = 0;
	}
	else if (currentMonster->_monsterType == "Dragon")
	{
		Health = 500, Mana = 200, Strength = 200, Constitution = 0, Speed = 200;
	}
	if (currentMonster->_monsterType == "Maia")
	{
		Health = 9999, Mana = 0, Strength = 0, Constitution = 0, Speed = 0;
	}
	
	output += currentMonster->_name + "'s Health: " + to_string(Health) +"\n";
	output += currentMonster->_name + "'s Mana: " + to_string(Mana) + "\n";
	output += currentMonster->_name + "'s Strength: " + to_string(Strength) + "\n";
	output += currentMonster->_name + "'s Constitution: " + to_string(Constitution) + "\n";
	output += currentMonster->_name + "'s Speed: " + to_string(Speed) + "\n";

	return output;
}

int Creature::MonsterCount(std::string monsterType)
{
	int MonsterCount = 0;
	for (auto monster : _Subordinates)
	{
		if (monster->_monsterType == monsterType)
		{
			MonsterCount += 1;
		}
		int subMonsterCount = monster->MonsterCount(monsterType);
		MonsterCount += subMonsterCount;
	}
	return MonsterCount;
}

std::string Creature::GetCombinedBranchStats(int CreatureCount, int OrcCount, int UrukHaiCount, int WraithCount, int DragonCount)
{
	std::string output;
	int totalHealth = 0;
	int totalMana = 0;
	int totalStrength = 0;
	int totalConstitution = 0;
	int totalSpeed = 0;

	totalHealth = (80 * CreatureCount) + (120 * OrcCount) + (150 *UrukHaiCount) + (225 * WraithCount) + (500 * DragonCount);
	totalMana = (100 * WraithCount) + (200 * DragonCount);
	totalStrength = (50 * OrcCount) + (80 * UrukHaiCount) + (200 * DragonCount);
	totalConstitution = (60 * UrukHaiCount);
	totalSpeed = (200 * DragonCount);

	output += "Army Branch's Health: " + to_string(totalHealth) + "\n";
	output += "Army Branch's Mana: " + to_string(totalMana) + "\n";
	output += "Army Branch's Strength: " + to_string(totalStrength) + "\n";
	output += "Army Branch's Constitution: " + to_string(totalConstitution) + "\n";
	output += "Army Branch's Speed: " + to_string(totalSpeed) + "\n";

	return output;
}

std::string Creature::Attack()
{
	string output = "swings their mighty blade up and around";
	return output;
}

bool Creature::operator<(std::shared_ptr<Creature> otherMonster)
{
	//Operator Overloaded ">" to determine if current monster has
	// greater health than monster chosen to compare with
	return (_health > otherMonster->_health);
}