#ifndef MONSTER_HPP
#define MONSTER_HPP

class Monster 
{ 
	public:
		Monster(int);
		void setLevel(int);
		void setHealth(int);
		void setStrength(int);
		void setSpeed(int);
		void setMagic(int);
		int getLevel();
		int getHealth();
		int getStrength();
		int getSpeed();
		int getMagic();
		void monsterStats(Monster);
		
	private:
		int monsterLevel, monsterHealth, monsterStrength, monsterSpeed, monsterMagic, monsterWeight;	
};

#endif //MONSTER_HPP