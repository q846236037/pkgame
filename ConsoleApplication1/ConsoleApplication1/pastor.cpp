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
