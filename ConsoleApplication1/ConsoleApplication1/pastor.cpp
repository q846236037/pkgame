#include "pastor.h"



pastor::pastor()
{
	name = "��ʦ";
	mp = 200; // ����ֵ����
	hp = 100;//Ѫ������
	level = 1;//����
	max_level = level * 200;//�������辭��
	money = 0;//��Ǯ
	hurt = 5;//�˺�
	defense = 5;//����
	skillname = NULL;
	mon = NULL;
}


pastor::~pastor()
{
}

pastor::pastor(string name, int mp, int hp, int level, int max_level, int money, int hurt, int defense)
{
	this->name = name;
	this->mp = mp;
	this->hp = hp;
	this->level = level;
	this->max_level = max_level;
	this->money = money;
	this->hurt = hurt;
	this->defense = defense;
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
