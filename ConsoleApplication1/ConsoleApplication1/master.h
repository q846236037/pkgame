#pragma once
#include "hero.h"
class master :
	public hero
{
public:
	master();
	~master();
	master(string name,//名字
		int mp,// 法力值上限
		int hp,//血量上限
		int  level,//级别
		int max_level,//升级所需经验
		int money,//金钱
		int hurt,//伤害
		int defense);//防御
	virtual  void setSkill(skill *name) override;
	virtual  void setMonster(monster  *mon) override;
	virtual void attack() override;
};

