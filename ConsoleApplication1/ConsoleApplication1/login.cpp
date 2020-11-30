#include "login.h"
#include "color.h"
#include "hud.h"



login::login()
{
	account = "admin";
	password = "88888888";
	col = NULL;
	hu = NULL;
}


login::~login()
{
}

bool login::loginAccount()
{
	string use_account;
	string use_password;
	col->setXY(hu->x, hu->y++);
	cout << "ÇëÊäÈëÕËºÅ:";
	cin >> use_account;
	col->setXY(hu->x, hu->y++);
	cout << "ÇëÊäÈëÃÜÂë:";
	cin >> use_password;
	if (this->account == use_account&&this->password == use_password) {
		return true;
	}
	return false;
}

void login::setCo_hud(color * col, hud * hu)
{
	this->col = col;
	this->hu = hu;
}
