#ifndef MONSTER_HPP
#define MONSTER_HPP
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Moves_Class.h"

class Monster
{
	public:
		Monster(std::string name,int,int,int,int,int,int,int,std::string);
		Moves_Class moveO;
		Moves_Class moveT;
		Moves_Class moveTR;
		void setLevel(int);
		void setHealth(int);
		void setStrength(int);
		void setSpeed(int);
		void setMagic(int);
		void setWeight(int);
		int getWeight();
		int getLevel();
		int getHealth();
		int getStrength();
		int getSpeed();
		int getMagic();
		std::string getName();
		void monsterStats(Monster);
		void deductDamage(int);
		int getAccuracy();
		std::string getType();
		std::vector<Moves_Class> moveInventory;

	protected:

	    std::string name;
	    std::string type;
		int monsterLevel, monsterHealth, monsterStrength, monsterSpeed, monsterMagic, monsterWeight, accuracy;
};

#endif //MONSTER_HPP
