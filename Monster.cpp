// Initialize monster level to player level
Monster::Monster(int playerLevel)
{
	monsterLevel = playerLevel;
}

// Set Monster class private member monsterLevel
void Monster::setLevel(int level)
{
	monsterLevel = level;
}

// Set Monster class private member monsterHealth
void Monster::setHealth(int health)
{
	monsterHealth = health;
}

// Set Monster class private member monsterStrength
void Monster::setStrength(int strength)
{
	monsterStrength = strength;
}

// Set Monster class private member monsterSpeed
void Monster::setSpeed(int speed)
{
	monsterSpeed = speed;
}

// Set Monster class private member monsterMagic
void Monster::setMagic(int magic)
{
	monsterMagic = magic;
}

// Set Monster class private member monsterLevel
void Monster::setWeight(int weight)
{
	monsterWeight = weight;
}

// Get Monster class private member monsterLevel
int Monster::getLevel()
{
	return monsterLevel;
}

// Get Monster class private member monsterLevel
int Monster::getHealth()
{
	return monsterHealth;
}

// Get Monster class private member monsterStrength
int Monster::getStrength()
{
	return monsterStrength;
}

// Get Monster class private member monsterSpeed
int Monster::getSpeed()
{
	return monsterSpeed;
}

// Get Monster class private member monsterMagic
int Monster::getMagic()
{
	return monsterMagic;
}

// Get Monster class private member monsterWeight
int Monster::getWeight()
{
	return monsterWeight;
}

// Display monster's stats
void Monster::monsterStats(Monster monster)
{
	std::cout << std::setw(35) << std::endl << "Monster Stats" << std::endl << std::endl;

	
	std::cout << "Level: " << monster.getLevel();
	std::cout << std::setw(20) << "Health: " << monster.getHealth();
	std::cout << std::setw(20) << "Strength: " << monster.getStrength() << std::endl;
	std::cout << "Speed: " << monster.getSpeed();
	std::cout << std::setw(19) << "Magic: " << monster.getMagic();
	std::cout << std::setw(17) << "Weight: " << monster.getWeight() << std::endl;
}
