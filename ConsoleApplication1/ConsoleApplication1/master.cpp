#include "master.h"



master::master()
{
	 name = "��ʦ";
	 mp = 200; // ����ֵ����
	 hp = 100;//Ѫ������
	 level = 1;//����
	max_level =level*200;//�������辭��
	money = 0;//��Ǯ
	hurt = 5;//�˺�
	defense = 5;//����
	skillname = NULL;
	mon = NULL;
	id = 1;
	nowlevel = 0;
}


master::~master()
{
}

master::master(string name, int mp, int hp, int level, int max_level, int money, int hurt, int defense,int id,int nowlevel)
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

void master::setSkill(skill * name)
{
	this->skillname = name;
}

void master::setMonster(monster * mon)
{
	this->mon = mon;
	cout << "ѡ����" << this->mon->name;
}

void master::attack()
{
	cout << mon->hp << endl;
	cout << this->skillname <<"name:"<< (this->skillname == NULL )<< endl;
	if (mon->hp>0)
	{
		//��ͨ����
		if (this->skillname == NULL) {
			int hurt;
			hurt = this->hurt - mon->defense;
			mon->hp -= hurt;
			cout <<this->name<< "�����" << hurt << "���˺�" << endl;
			cout << mon->name << "ʣ��" << mon->hp << "Ѫ��" << endl;
			mon->setPlayer(this);
			mon->attack();
		}
	}
	
	
}
