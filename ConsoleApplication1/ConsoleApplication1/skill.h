#pragma once
#include<iostream>
#include <string>
#include "color.h"
#include <fstream>

class hud;
class hero;
using namespace std;
class skill
{
public:
	skill();
	~skill();
	string name; //Ãû×Ö
	int hurt; //ÉËº¦
	int mp; // mp
	int hid;//Ó¢ÐÛid;
	bool hot;//×ÆÉÕ
	bool cold;//º®Àä
	bool aoe;//ÊÇ·ñ·¶Î§ÉËº¦
	bool paralysis;//Âé±Ô
	int id;//¼¼ÄÜid
	virtual  void useingSkill() = 0;
	int level;//¿ÉÑ§Ï°µÈ¼¶
	virtual void studentSkill() = 0;
	virtual void lookSkill() = 0;
	color *col;
	hud *hu;
	hero *her;
	void setcolor(color *col);
	void sethero(hero*her);
	int getIsStudent(int id = -1);
};

