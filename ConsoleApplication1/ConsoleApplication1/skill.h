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
	string name; //����
	int hurt; //�˺�
	int mp; // mp
	int hid;//Ӣ��id;
	bool hot;//����
	bool cold;//����
	bool aoe;//�Ƿ�Χ�˺�
	bool paralysis;//���
	int id;//����id
	virtual  void useingSkill() = 0;
	int level;//��ѧϰ�ȼ�
	virtual void studentSkill() = 0;
	virtual void lookSkill() = 0;
	color *col;
	hud *hu;
	hero *her;
	void setcolor(color *col);
	void sethero(hero*her);
	int getIsStudent(int id = -1);
};

