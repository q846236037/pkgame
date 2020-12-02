#include "soldier.h"



soldier::soldier()
{
	name = "սʿ";
	mp = 100; // ����ֵ����
	hp = 100;//Ѫ������
	level = 1;//����
	max_level = level * 200;//�������辭��
	money = 0;//��Ǯ
	hurt = 20;//�˺�
	defense = 10;//����
	skillname = NULL;
	mon = NULL;
	id = 0;
	nowlevel = 0;
}

soldier::soldier(string name, int mp, int hp, int level, int max_level, int money, int hurt, int defense, int id, int nowlevel)
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


soldier::~soldier()
{
}

void soldier::setSkill(skill * name)
{
	this->skillname = name;
}

void soldier::setMonster(monster * mon)
{
	this->mon = mon;
}

void soldier::attack()
{
	if (mon->hp > 0)
	{
		//��ͨ����
		if (this->skillname != NULL) {
			int hurt;
			hurt = this->hurt - mon->defense;
			mon->hp -= hurt;
			cout << this->name << "�����" << hurt << "���˺�" << endl;
			cout << mon->name << "ʣ��" << mon->hp << "Ѫ��" << endl;
			mon->attack();

		}
	}
}
