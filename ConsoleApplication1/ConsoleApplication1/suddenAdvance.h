#pragma once
#include "skill.h"
#include "monster.h"
class suddenAdvance :
	public skill
{
public:
	suddenAdvance();
	~suddenAdvance();
	virtual  void useingSkill() override;
	virtual void studentSkill() override;
	virtual void lookSkill() override;
};

