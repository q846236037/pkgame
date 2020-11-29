#include "hud.h"



hud::hud()
{
	
	this->col = NULL;
}


hud::~hud()
{
}

void hud::drawBlood(int num)
{
	cout << endl;
	cout << "血量:" << " ";
	this->col->setColor(1);
	for (int i = 0;i <= num;i++)
	{
		cout << " ";
	}
	this->col->setColor(4);
	for (int i = 0; i < 20 - num; i++)
	{
		cout << " ";
	}
	cout << endl;
	this->col->getdefault();
	
}

void hud::drawmp(int num)
{
	cout << endl;
	cout << "蓝量:" << " ";
	this->col->setColor(2);
	for (int i = 0; i <= num; i++)
	{
		cout << " ";
	}this->col->setColor(4);
	for (int i = 0; i < 20 - num; i++)
	{
		cout << " ";
	}
	cout << endl;
	this->col->getdefault();
}

void hud::drawlevel(int num)
{
	cout << endl;
	cout << "经验:" << " ";
	
	this->col->setColor(3);
	for (int i = 0; i <=num; i++)
	{
		cout << " ";
	}
	this->col->setColor(4);
	for (int i = 0; i <20 - num; i++)
	{
		cout << " ";
	}
	cout << endl;
	this->col->getdefault();
	
}

void hud::setcolor(color * col)
{
	this->col = col;
}
