#pragma once
#include "stage.h"
#include <ctime>
class stage;
class quickmedicine :
	public stage
{
public:
	quickmedicine();
	~quickmedicine();
	virtual void use() override;//ʹ��
	virtual void buy() override;//����
	stage**sta;
	quickmedicine(int hid, int id =2);
	int  setadd();
};

