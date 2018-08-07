#include <iostream>
#include <fstream>
#include <map>
#include "../include/Monster.hpp"
#include "../include/Player_Class.h"
#include "../include/Weapon_Class.h"
#include "../include/Damage_Calculator.h"
#include "../include/Moves_Class.h"
#include "../include/Armor_Class.h"


double check_type(std::string att, std::string def)
{
    //E - Earth | P - Poison | F - Fire | I - Ice | S - Steel | D - Demon | H - Holy | L - Electric | B - Blood | W - Water
    std::string type = att + def;
    std::map<std::string, double> types;
    types["EE"] = 1.0;types["EP"] = 2.0; types["EF"] = 2.0; types["EI"] = .5; types["ES"] = 1.0; types["ED"] = 1.0; types["EH"] = 1.0; types["EL"] = 2.0; types["EB"] = 1.0; types["EW"] = .5;
    types["PE"] = .5; types["PP"] = 1.0; types["PF"] = 1.0; types["PI"] = 1.0; types["PS"] = .5; types["PD"] = 1.0; types["PH"] = 1.0; types["PL"] = 1.0; types["PB"] = 2.0; types["PW"] = 2.0;
    types["FE"] = .5; types["FP"] = 1.0; types["FF"] = 1.0; types["FI"] = 2.0; types["FS"] = 2.0; types["FD"] = 1.0; types["FH"] = 2.0; types["FL"] = 1.0; types["FB"] = 1.0; types["FW"] = .5;
    types["IE"] = 2.0; types["IP"] = 1.0; types["IF"] = .5; types["II"] = 1.0; types["IS"] = 2.0; types["ID"] = .5; types["IH"] = 1.0; types["IL"] = 1.0; types["IB"] = 1.0; types["IW"] = 1.0;
    types["SE"] = 1.0; types["SP"] = 2.0; types["SF"] = .5; types["SI"] = .5; types["SS"] = 1.0; types["SD"] = 1.0; types["SH"] = 1.0; types["SL"] = 2.0; types["SB"] = 1.0; types["SW"] = 1.0;
    types["DE"] = 1.0; types["DP"] = 1.0; types["DF"] = 1.0; types["DI"] = 2.0; types["DS"] = 1.0; types["DD"] = 1.0; types["DH"] = .5; types["DL"] = 1.0; types["DB"] = 1.0; types["DW"] = 1.0;
    types["HE"] = 1.0; types["HP"] = 1.0; types["HF"] = 1.0; types["HI"] = 1.0; types["HS"] =  1.0; types["HD"] = 2.0; types["HH"] = .5; types["HL"] = 1.0; types["HB"] = 2.0; types["HW"] = 1.0;
    types["LE"] = .5; types["LP"] = 1.0; types["LF"] = 1.0; types["LI"] = 1.0; types["LS"] = .5; types["LD"] = 1.0; types["LH"] = 1.0; types["LL"] = 1.0; types["LB"] = 2.0; types["LW"] = 2.0;
    types["BE"] = 1.0; types["BP"] = .5; types["BF"] = 1.0; types["BI"] = 1.0; types["BS"] = 1.0; types["BD"] = 1.0; types["BH"] = .5; types["BL"] = .5; types["BB"] = 1.0; types["BW"] = 1.0;
    types["WE"] = 2.0; types["WP"] = .5; types["WF"] = 2.0; types["WI"] = 1.0; types["WS"] = 1.0; types["WD"] = 1.0; types["WH"] = 1.0; types["WL"] = .5; types["WB"] = 1.0; types["WW"] = 1.0;
    return types[type];
}

int dmg_calc(Player_Class & player, Monster & enemy, Weapon_Class & weapon, Moves_Class & move)
{
    double type = check_type(move.getType(), enemy.getType());
    return (((player.getStrength() + weapon.getDmg()) / 10) + move.getDamage()) * type;
}

int dmg_calc(Player_Class & player, Monster & enemy, std::shared_ptr<Armor_Class> armor)
{
    std::string name = enemy.getName();
    double type = check_type(enemy.getType(), armor->getType());
    int damage = (enemy.getStrength() - ((armor->getArmor()/2))) * type;
    damage == 0 ? damage = 1 : damage = damage;
    return damage;
}


