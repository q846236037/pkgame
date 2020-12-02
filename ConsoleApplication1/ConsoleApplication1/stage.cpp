#include "stage.h"



stage::stage()
{
}


stage::~stage()
{
}

void stage::sethero(hero *her)
{
	this->her = her;
}

void stage::setcolor(color * col)
{
	this->col = col;
}

void stage::setHud(hud * hu)
{
	this->hu = hu;
}




int stage::getStaNum()
{
	fstream ifs;
	ifs.open("stage.txt", ios::in);
	int h_id;
	int s_id;
	int num = 0;
	while (ifs >> h_id >> s_id)
	{
		num++;
	}
	ifs.close();
	return num;
}
