#pragma once
#include "hero.h"
class master :
	public hero
{
public:
	master();
	~master();
	virtual  void setSkill(skill *name) override;
	virtual  void setMonster(monster  *mon) override;
	virtual void attack() override;
};

