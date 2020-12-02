#pragma once
#include "stage.h"
class stage;
class redmedicine :
	public stage
{
public:
	redmedicine();
	~redmedicine();
	virtual void use() override;//Ê¹ÓÃ
	virtual void buy() override;//¹ºÂò
	stage**sta;
	redmedicine(int hid, int id =1);
};

