#pragma once
#include "stage.h"
class stage;
class redmedicine :
	public stage
{
public:
	redmedicine();
	~redmedicine();
	virtual void use() override;//ʹ��
	virtual void buy() override;//����
	stage**sta;
	redmedicine(int hid, int id =1);
};

