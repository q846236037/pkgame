#pragma once
#include "skill.h"
class snowstorm :
	public skill
{
public:
	snowstorm();
	~snowstorm();
	virtual  void useingSkill() override;
};

