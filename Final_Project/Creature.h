#pragma once
#include <string>
#include <memory>
#include <vector>

class Creature
{
private:
	std::string _name;
	std::vector <std::shared_ptr<Creature>> _Subordinates;

protected:
	int _health;
	std::string _monsterType;

public:
	Creature(std::string name);
	Creature();
	~Creature();

	std::string GetName();
	std::string GetMonsterType();
	std::string ListSubordinates();
	void AddMonster(std::shared_ptr<Creature> newMonster);
	std::shared_ptr<Creature> FindMonster(std::string name);
	std::string GetStats(std::shared_ptr<Creature> currentMonster);
	int MonsterCount(std::string monsterType);
	std::string GetCombinedBranchStats(int CreatureCount, int OrcCount, int UrukHaiCount, int WraithCount, int DragonCount);
	virtual std::string Attack();
    bool operator>(Creature otherMonster);

};