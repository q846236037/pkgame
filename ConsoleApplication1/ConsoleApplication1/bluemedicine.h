#pragma once
#include "stage.h"
class stage;
class bluemedicine :
	public stage
{
public:
	bluemedicine();
	~bluemedicine();
	virtual void use() override;//ʹ��
	virtual void buy() override;//����
	stage**sta;
	bluemedicine(int hid,int id = 0);
};

