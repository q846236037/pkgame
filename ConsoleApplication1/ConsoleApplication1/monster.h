#pragma once
#include "hero.h"
class hero;
class monster
{
public:
	monster();
	~monster();
	string name;//����
	hero * player;//���
	int hp;//Ѫ��
	int defense;//����
	int hurt;//�˺�
	skill *skillname;//��������
	int level;//����
	int money;//��Ǯ
	virtual void attack() = 0;
	virtual void setPlayer(hero *her) = 0;
};

