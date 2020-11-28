#include "scaleph.h"



scaleph::scaleph()
{
	name = "ÕÂÓã"; //Ãû×Ö
	hero * player = NULL;//Íæ¼Ò
	hp = 200;//ÑªÁ¿
	defense = 2;//·ÀÓù
	hurt = 20;//ÉËº¦
	skill *skillname = NULL;
	level = 50;
	money = 50;//½ðÇ®
}


scaleph::~scaleph()
{
}

void scaleph::attack()
{
	if (player->hp > 0) {
		//ÆÕÍ¨¹¥»÷
		if (skillname == NULL) {
			int hurt = this->hurt - player->defense;
			
			player->hp -=hurt;
			cout << this->name << "Ôì³ÉÁË" << hurt << "µãÉËº¦" << endl;
			cout << player->name << "Ê£Óà" << player->hp << "ÑªÁ¿" << endl;
		}
	}
}

void scaleph::setPlayer(hero * her)
{
	this->player = her;
}
