#include "master.h"



master::master()
{
	 name = "法师";
	 mp = 200; // 法力值上限
	 hp = 200;//血量上限
	 level = 1;//级别
	max_level =level*200;//升级所需经验
	money = 0;//金钱
	hurt = 12;//伤害
	defense = 10;//防御
	skillname = NULL;
	mon = NULL;
	id = 1;
	nowlevel = 0;
}


master::~master()
{
}

master::master(string name, int mp, int hp, int level, int max_level, int money, int hurt, int defense,int id,int nowlevel)
{
	this->name = name;
	this->mp = mp;
	this->hp = hp;
	this->level = level;
	this->max_level = max_level;
	this->money = money;
	this->hurt = hurt;
	this->defense = defense;
	this->id = id;
	this->nowlevel = nowlevel;
}

void master::setSkill(skill * name)
{
	this->skillname = name;
}

void master::setMonster(monster * mon)
{
	this->mon = mon;
}

void master::attack()
{
	if (mon->hp>0)
	{
		//普通攻击
		if (this->skillname == NULL) {
			int hurt;
			hurt = this->hurt - mon->defense;
			mon->hp -= hurt;
		}
		if (this->skillname->name == "暴风雪") {
			mp -= this->skillname->mp;
			hurt = this->skillname->hurt - mon->defense;
			mon->hp -= hurt;
			mon->state = 1;
			mon->num = 3;
			this->skillname = NULL;
		}
		else if (this->skillname->name == "火焰喷射") {
			mp -= this->skillname->mp;
			hurt = this->skillname->hurt - mon->defense;
			mon->hp -= hurt;
			mon->state = 2;
			mon->num = 3;
			this->skillname = NULL;
		}
		else if (this->skillname->name == "猪突猛进") {
			mp -= this->skillname->mp;
			hurt = this->skillname->hurt - mon->defense;
			mon->hp -= hurt;
			mon->state = 2;
			mon->num = 3;
			this->skillname = NULL;
		}
	} 
	
	
}
