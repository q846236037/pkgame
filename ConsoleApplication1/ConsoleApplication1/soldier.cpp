#include "soldier.h"



soldier::soldier()
{
	name = "战士";
	mp = 100; // 法力值上限
	hp = 100;//血量上限
	level = 1;//级别
	max_level = level * 200;//升级所需经验
	money = 0;//金钱
	hurt = 20;//伤害
	defense = 10;//防御
	skillname = NULL;
	mon = NULL;
}

soldier::soldier(string name, int mp, int hp, int level, int max_level, int money, int hurt, int defense)
{
	this->name = name;
	this->mp = mp;
	this->hp = hp;
	this->level = level;
	this->max_level = max_level;
	this->money = money;
	this->hurt = hurt;
	this->defense = defense;
}


soldier::~soldier()
{
}

void soldier::setSkill(skill * name)
{
	this->skillname = name;
}

void soldier::setMonster(monster * mon)
{
	this->mon = mon;
}

void soldier::attack()
{
	if (mon->hp > 0)
	{
		//普通攻击
		if (this->skillname != NULL) {
			int hurt;
			hurt = this->hurt - mon->defense;
			mon->hp -= hurt;
			cout << this->name << "造成了" << hurt << "点伤害" << endl;
			cout << mon->name << "剩余" << mon->hp << "血量" << endl;
			mon->attack();

		}
	}
}
