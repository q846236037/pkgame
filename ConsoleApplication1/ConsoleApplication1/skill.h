#pragma once
#include<iostream>
#include <string>
using namespace std;
class skill
{
public:
	skill();
	~skill();
	string name; //Ãû×Ö
	int hurt; //ÉËº¦
	int mp; // mp
	bool hot;//×ÆÉÕ
	bool cold;//º®Àä
	bool aoe;//ÊÇ·ñ·¶Î§ÉËº¦
	bool paralysis;//Âé±Ô
	virtual  void useingSkill() = 0;

};

