#pragma once
#include "skill.h"
class suddenAdvance :
	public skill
{
public:
	suddenAdvance();
	~suddenAdvance();
	virtual  void useingSkill() override;
};

