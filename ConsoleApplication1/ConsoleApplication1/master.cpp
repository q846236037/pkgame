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
}


master::~master()
{
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
