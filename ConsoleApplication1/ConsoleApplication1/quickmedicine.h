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
	virtual void use() override;//Ê¹ÓÃ
	virtual void buy() override;//¹ºÂò
	stage**sta;
	quickmedicine(int hid, int id =2);
	int  setadd();
};

