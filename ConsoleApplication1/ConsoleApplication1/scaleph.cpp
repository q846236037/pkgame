#include "scaleph.h"



scaleph::scaleph()
{
	name = "����"; //����
	hero * player = NULL;//���
	hp = 200;//Ѫ��
	defense = 2;//����
	hurt = 20;//�˺�
	skill *skillname = NULL;
	level = 50;
	money = 50;//��Ǯ
}


scaleph::~scaleph()
{
}

void scaleph::attack()
{
	if (player->hp > 0) {
		//��ͨ����
		if (skillname == NULL) {
			int hurt = this->hurt - player->defense;
			
			player->hp -=hurt;
			cout << this->name << "�����" << hurt << "���˺�" << endl;
			cout << player->name << "ʣ��" << player->hp << "Ѫ��" << endl;
		}
	}
}

void scaleph::setPlayer(hero * her)
{
	this->player = her;
}
