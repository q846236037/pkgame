#pragma once
#include "hero.h"
class pastor :
	public hero
{
public:
	pastor();
	~pastor();
	pastor(string name,//����
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

