#pragma once
#include "hero.h"
class soldier :
	public hero
{
public:
	soldier();
	~soldier();
	virtual  void setSkill(skill *name) override;
	virtual  void setMonster(monster  *mon) override;
	virtual void attack() override;
};

