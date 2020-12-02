#pragma once
#include "stage.h"
class stage;
class bluemedicine :
	public stage
{
public:
	bluemedicine();
	~bluemedicine();
	virtual void use() override;//Ê¹ÓÃ
	virtual void buy() override;//¹ºÂò
	stage**sta;
	bluemedicine(int hid,int id = 0);
};

