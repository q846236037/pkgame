#pragma once
#include "hero.h"
class pastor :
	public hero
{
public:
	pastor();
	~pastor();
	virtual  void setSkill(skill *name) override;
	virtual  void setMonster(monster  *mon) override;
	virtual void attack() override;
};

