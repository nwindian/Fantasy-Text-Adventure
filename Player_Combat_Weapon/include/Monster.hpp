#ifndef MONSTER_HPP
#define MONSTER_HPP
#include <string>

class Monster
{
	public:
		Monster(std::string name,int,int,int,int,int,int);
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

	private:
	    std::string name;
		int monsterLevel, monsterHealth, monsterStrength, monsterSpeed, monsterMagic, monsterWeight;
};

#endif //MONSTER_HPP
