#pragma once
#include<iostream>
#include <string>
using namespace std;
class skill
{
public:
	skill();
	~skill();
	string name; //����
	int hurt; //�˺�
	int mp; // mp
	bool hot;//����
	bool cold;//����
	bool aoe;//�Ƿ�Χ�˺�
	bool paralysis;//���
	virtual  void useingSkill() = 0;

};

