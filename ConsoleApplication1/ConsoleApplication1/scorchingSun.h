#pragma once
#include "skill.h"
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

