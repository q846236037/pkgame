#include "pastor.h"



pastor::pastor()
{
	name = "��ʦ";
	mp = 200; // ����ֵ����
	hp = 200;//Ѫ������
	level = 1;//����
	max_level = level * 200;//�������辭��
	money = 0;//��Ǯ
	hurt = 15;//�˺�
	defense = 10;//����
	skillname = NULL;
	mon = NULL;
	id = 2;
	nowlevel = 0;
}


pastor::~pastor()
{
}

pastor::pastor(string name, int mp, int hp, int level, int max_level, int money, int hurt, int defense, int id,int nowlevel)
{
	this->name = name;
	this->mp = mp;
	this->hp = hp;
	this->level = level;
	this->max_level = max_level;
	this->money = money;
	this->hurt = hurt;
	this->defense = defense;
	this->id = id;
	this->nowlevel = nowlevel;
}

void pastor::setSkill(skill * name)
{
	this->skillname = name;
}

void pastor::setMonster(monster * mon)
{
	this->mon = mon;
}

void pastor::attack()
{
	if (mon->hp > 0)
	{
		//��ͨ����
		if (this->skillname == NULL) {
			int hurt;
			hurt = this->hurt - mon->defense;
			mon->hp -= hurt;
		}
		if (this->skillname->name == "����ѩ") {
			mp -= this->skillname->mp;
			hurt = this->skillname->hurt - mon->defense;
			mon->hp -= hurt;
			mon->state = 1;
			mon->num = 3;
			this->skillname = NULL;
		}
	}
}
