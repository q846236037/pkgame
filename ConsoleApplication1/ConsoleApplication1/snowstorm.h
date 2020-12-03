#pragma once
#include "skill.h"
#include "monster.h"
class snowstorm :
	public skill
{
public:
	snowstorm();
	~snowstorm();
	virtual  void useingSkill() override;
	virtual void studentSkill() override;
	virtual void lookSkill() override;
};

