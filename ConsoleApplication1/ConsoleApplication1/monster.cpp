#include "monster.h"
#include <ctime>


monster::monster()
{
	
}


monster::~monster()
{
}

bool monster::isstart()
{
	if (state == 2)
	{
		srand((unsigned int)time(NULL));
		int num = rand()%100+1;
		if (num>0&&num<50)
		{
			return true;
		}
	}
	return false;
}
