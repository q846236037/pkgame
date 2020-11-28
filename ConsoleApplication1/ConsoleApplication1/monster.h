#pragma once
#include "hero.h"
class hero;
class monster
{
public:
	monster();
	~monster();
	string name;//名字
	hero * player;//玩家
	int hp;//血量
	int defense;//防御
	int hurt;//伤害
	skill *skillname;//技能名字
	int level;//经验
	int money;//金钱
	virtual void attack() = 0;
	virtual void setPlayer(hero *her) = 0;
};

