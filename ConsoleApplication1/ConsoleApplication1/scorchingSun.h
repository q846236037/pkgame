#pragma once
#include "skill.h"
#include "monster.h"
class scorchingSun :
	public skill
{
public:
	scorchingSun();
	~scorchingSun();
	virtual  void useingSkill() override;
	virtual void studentSkill() override;
	virtual void lookSkill() override;
};

