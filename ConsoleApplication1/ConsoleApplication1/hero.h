#pragma once
#include <string>
#include "skill.h"
#include "monster.h"
class monster;
using namespace std;
class hero
{
public:
	hero();
	~hero();
	string name; //����
	int mp; // ����ֵ����
	int hp;//Ѫ������
	int  level;//����
	int max_level;//�������辭��
	int money;//��Ǯ
	int hurt;//�˺�
	int defense; //����
	skill*skillname;
	monster*mon;
	virtual  void setSkill(skill *name) = 0;
	virtual  void setMonster(monster  *mon) = 0;
	virtual void attack() = 0;
};

