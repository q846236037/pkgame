#pragma once
#include <string>

#include <fstream>
#include <iostream>
#include <string>
#include "color.h"
//#include "hud.h"
#include "hero.h"
using namespace std;

class hud;

class stage
{
public:
	stage();
	~stage();
	string name;//����
	hero *her;
	color *col;
	hud *hu;
	int id;//id
	int hid;//hid
	int money;//��Ǯ
	virtual void use() = 0;//ʹ��
	virtual void buy() = 0;//����
	void sethero(hero *her);
	void setcolor(color *col);
	void setHud(hud *hu);
	int add;//Ч��
	int getStaNum();//��ȡ��������
};

