#include "scaleph.h"



scaleph::scaleph()
{
	name = "����"; //����
	hero * player = NULL;//���
	hp = 200;//Ѫ��
	defense = 2;//����
	hurt = 20;//�˺�
	skill *skillname = NULL;
	level = 100;
	money = 50;//��Ǯ
	state = 0;
	num = 0;
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
		}
	}
}

void scaleph::setPlayer(hero * her)
{
	this->player = her;
}
