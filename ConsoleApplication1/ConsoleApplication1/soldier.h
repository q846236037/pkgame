#pragma once
#include "hero.h"
class soldier :
	public hero
{
public:
	soldier();
	~soldier();
	soldier(string name,//����
		int mp,// ����ֵ����
		int hp,//Ѫ������
		int  level,//����
		int max_level,//�������辭��
		int money,//��Ǯ
		int hurt,//�˺�
		int defense,int id, int nowlevel);//����
	virtual  void setSkill(skill *name) override;
	virtual  void setMonster(monster  *mon) override;
	virtual void attack() override;
};

