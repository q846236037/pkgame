#pragma once
#include "color.h"
#include <iostream>
using namespace std;
class hud
{
public:
	hud();
	~hud();
	color *col;
	void drawBlood(int num = 20);
	void drawmp(int num = 20);
	void drawlevel(int num = 20);
	void setcolor(color *col);
};

