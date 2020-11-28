#pragma once
#include "monster.h"
class scaleph :
	public monster
{
public:
	scaleph();
	~scaleph();
	virtual void attack() override;
	virtual void setPlayer(hero *her) override;
};