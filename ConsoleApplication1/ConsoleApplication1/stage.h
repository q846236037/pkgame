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
	string name;//名字
	hero *her;
	color *col;
	hud *hu;
	int id;//id
	int hid;//hid
	int money;//金钱
	virtual void use() = 0;//使用
	virtual void buy() = 0;//购买
	void sethero(hero *her);
	void setcolor(color *col);
	void setHud(hud *hu);
	int add;//效果
	int getStaNum();//获取道具数量
};

