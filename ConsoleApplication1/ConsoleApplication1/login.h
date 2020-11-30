#pragma once
#include <iostream>
#include <string>
#include "color.h"
#include "hud.h"
using namespace std;
class color;
class hud;
class login
{
public:
	login();
	~login();
	bool loginAccount();
	color *col;
	hud *hu;
	void setCo_hud(color *col, hud *hu);
	
private:
	string account;
	string password;
};

