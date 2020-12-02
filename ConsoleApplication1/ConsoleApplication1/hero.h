#pragma once
#include <string>
#include "skill.h"
#include "monster.h"
class monster;
using namespace std;
class hero
{
public:
	hero();
	~hero();
	string name; //名字
	int mp; // 法力值上限
	int hp;//血量上限
	int  level;//级别
	int max_level;//升级所需经验
	int money;//金钱
	int hurt;//伤害
	int defense; //防御
	int id;//
	int nowlevel;//当前经验
	skill*skillname;
	monster*mon;
	virtual  void setSkill(skill *name) = 0;
	virtual  void setMonster(monster  *mon) = 0;
	virtual void attack() = 0;
};

