#include "skill.h"
#include <fstream>
#include "hero.h"



skill::skill()
{
}


skill::~skill()
{
}

void skill::setcolor(color *col)
{
	this->col = col;
}

void skill::sethero(hero * her)
{
	this->her = her;
}

int skill::getIsStudent(int id)
{
	ifstream ifs;
	ifs.open("skill.txt", ios::in);
	if (ifs.is_open())
	{
		int hid;
		int sid;
		int num = 0;
		while (ifs>>hid>>sid)
		{
			if (id == -1) {
				num++;
			}
			else if(sid == id&&her->id ==hid){
				num++;
			}
			
		}
		return num;
	}
	else {
		return 0;
	}
}

void skill::setmon(monster * mon)
{
	this->mon = mon;
}

void skill::sethud(hud * hu)
{
	this->hu = hu;
}
