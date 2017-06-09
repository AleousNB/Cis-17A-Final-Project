//Program for Sauron (From LOTR) to keep track of his demon army
//There are different types of monsters deriving from the base creature class
//Monsters can be added to existing monsters(making the new monsters subordinates)
//Structure of program simillar to folder/file project
//Kind of a Expanded mash-up between project 3 part 1 and 2
//Navigating through different creatures code used from folder/file project

#include <iostream>
#include <stack>
#include "Creature.h"
#include "Orc.h"
#include "UrukHai.h"
#include "Wraith.h"
#include "Dragon.h"
#include "Maia.h"
using namespace std;

void DisplayMenu(shared_ptr<Creature> currentMonster, shared_ptr<Creature> parent);
void AddMonsterMenu(shared_ptr<Creature> currentMonster);
shared_ptr<Creature> PickMonster(shared_ptr<Creature> currentMonster);
void ShowStats(shared_ptr<Creature> currentMonster);
void BranchStats(shared_ptr<Creature> currentMonster);

int main()
{
	stack <shared_ptr<Creature>> parentMonsterStack;
	auto currentMonster = make_shared<Creature>();
	currentMonster = make_shared<Maia>("Sauron");
	auto parentMonster = make_shared<Creature>();
	parentMonster = nullptr;

	int choice = 0;
	while (choice != -1)
	{
		DisplayMenu(currentMonster, parentMonster);
		cin >> choice;
		switch (choice)
		{
			case 1: system("cls"); 
			{
				cout << "Subordinates of " << currentMonster->GetName() << currentMonster->ListSubordinates() << endl;
				system("pause");
				break;
			}
			case 2:
			{
				AddMonsterMenu(currentMonster);
				break;
			}
			case 3:
			{
				auto newCurrent = make_shared<Creature>();
				newCurrent = nullptr;
				try
				{
					newCurrent = PickMonster(currentMonster);
					if (newCurrent == nullptr)
					{
						string error = "Non Existent Monster";
						throw error;
					}
				}
				catch(string errorMessage)
				{
					system("pause");
					while (newCurrent == nullptr)
					{
						system("cls");
						cout << "Error has occured" << endl;
						cout << errorMessage << endl;
						cout << "Enter a Monster that exists" << endl;
						system("pause");

						system("cls");
						newCurrent = PickMonster(currentMonster);
					}
				}
				
				parentMonsterStack.push(currentMonster);
				parentMonster = currentMonster;
				currentMonster = newCurrent;
				break;
			}
			case 4:
			{
				ShowStats(currentMonster);
				break;
			}
			case 5:
			{
				BranchStats(currentMonster);
				break;
			}
			case 6:
			{
				cout << currentMonster->GetName() << " " << currentMonster->Attack() << endl;
				system("pause");
				break;
			}
			case 7:
			{
				auto otherMonster = PickMonster(currentMonster);
				try
				{
					if (otherMonster == nullptr)
					{
						string error = "Non Existent Monster";
						throw error;
					}
				}
				catch (string errorMessage)
				{
					system("pause");
					while (otherMonster == nullptr)
					{
						system("cls");
						cout << "Error has occured" << endl;
						cout << errorMessage << endl;
						cout << "Enter a Monster that exists" << endl;
						system("pause");

						system("cls");
						otherMonster = PickMonster(currentMonster);
					}
				}
				bool CurrentHasGreaterHealth;
				CurrentHasGreaterHealth = *currentMonster > *otherMonster;
				
				cout << "Does " << currentMonster->GetName() << " have more health than " << otherMonster->GetName() << "?" << endl;
				cout << boolalpha << CurrentHasGreaterHealth << endl;
				if (CurrentHasGreaterHealth == true)
				{
					cout << currentMonster->GetName() << " has more health" << endl;
				}
				else
				{
					cout << currentMonster->GetName() << " has less health" << endl;
				}
				system("pause");
				break;
			}
			case 8: 
			{
				if (parentMonster != nullptr) 
				{
					currentMonster = parentMonsterStack.top();
					parentMonsterStack.pop();

					if (parentMonsterStack.empty() == false)
					{
						parentMonster = parentMonsterStack.top();
					}
					else
					{
						parentMonster = nullptr;
					}
				}
				break;
			}
			default:
			{
				cout << "Invalid choice!";
				break;
			}
		}
	}
	system("pause");
	return 0;
}

void DisplayMenu(shared_ptr<Creature> currentMonster, shared_ptr<Creature> parent)
{
	system("cls");
	cout << "Sauron's Army Logistics" << endl;
	cout << "Now looking at " << currentMonster->GetName() << " the " << currentMonster->GetMonsterType() << endl;
	cout << "*****************************************" << endl;
	cout << "1) List Current Monster's Direct Subordinates" << endl;
	cout << "2) Add Monster as Direct subordinate" << endl;
	cout << "3) Go to particular Direct Subordiate" << endl;
	cout << "4) Look at Current Monster's Stats" << endl;
	cout << "5) Assess Power of Army Branch Under Monster" << endl;
	cout << "6) Command Current Monster to Demonstrate Attack" << endl;
	cout << "7) Pick Direct Subordinate monster to compare health with current monster" << endl;
	if (parent != nullptr) {
		cout << "8) Return to [" << parent->GetName() << "]";
	}

}

shared_ptr<Creature> PickMonster(shared_ptr<Creature> currentMonster)
{
	cout << "Monster Name: ";
	string name;
	cin >> name;
	cin.ignore();

	auto monster = currentMonster->FindMonster(name);
	return monster;
}

//modified add adventurer code from project 3 part1
void AddMonsterMenu(shared_ptr<Creature> currentMonster)
{
	system("cls");

	cout << "Enter name of new subordinate monster ";
	string name;
	cin >> name;
	cin.ignore();

	system("cls");

	cout << "What type of Monster would you like to add?" << endl;
	cout << "1) Creature" << endl;
	cout << "2) Orc" << endl;
	cout << "3) Uruk Hai" << endl;
	cout << "4) Wraith" << endl;
	cout << "5) Dragon" << endl;

	int choice = -1;
	cin >> choice;
	switch (choice)
	{
		case 1:
		{
			auto newMonster = make_shared<Creature>(name);
			currentMonster->AddMonster(newMonster);
			break;
		}
		case 2:
		{
			auto newMonster = make_shared<Orc>(name);
			currentMonster->AddMonster(newMonster);
			break;
		}
		case 3:
		{
			auto newMonster = make_shared<UrukHai>(name);
			currentMonster->AddMonster(newMonster);
			break;
		}
		case 4:
		{
			auto newMonster = make_shared<Wraith>(name);
			currentMonster->AddMonster(newMonster);
			break;
		}
		case 5:
		{
			auto newMonster = make_shared<Dragon>(name);
			currentMonster->AddMonster(newMonster);
			break;
		}
		default: 
		{
			cout << "Invalid choice!"; 
			break;
		}
	}
	system("pause");
}

void ShowStats(shared_ptr<Creature> currentMonster)
{
	system("cls");
	cout << "These are " << currentMonster->GetName() << "'s Stats:" << endl;
	cout << currentMonster->GetStats(currentMonster) << endl;
	system("pause");
}
void BranchStats(shared_ptr<Creature> currentMonster)
{
	system("cls");
	int CreatureCount = currentMonster->MonsterCount("Creature");
	int OrcCount = currentMonster->MonsterCount("Orc");
	int UrukHaiCount = currentMonster->MonsterCount("Uruk Hai");
	int WraithCount = currentMonster->MonsterCount("Wraith");
	int DragonCount = currentMonster->MonsterCount("Dragon");

	cout << "Subordinates of each type under branch leader:" << endl;
	cout << "Creatures: " << CreatureCount << endl;
	cout << "Orcs: " << OrcCount << endl;
	cout << "Uruk Hai: " << UrukHaiCount << endl;
	cout << "Wraiths : " << WraithCount << endl;
	cout << "Dragons: " << DragonCount << endl << endl;
	
	cout << "Stats of Army Branch Under " << currentMonster->GetName() << ":" << endl;
	cout << currentMonster->GetCombinedBranchStats(CreatureCount, OrcCount, UrukHaiCount, WraithCount, DragonCount) << endl;
	system("pause");
}
