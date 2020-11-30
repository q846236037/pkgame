#include "login.h"



login::login()
{
	account = "admin";
	password = "88888888";
}


login::~login()
{
}

bool login::loginAccount()
{
	string use_account;
	string use_password;
	cout << "ÇëÊäÈëÕËºÅ:";
	cin >> use_account;
	cout << "ÇëÊäÈëÃÜÂë:";
	cin >> use_password;
	if (this->account == use_account&&this->password == use_password) {
		return true;
	}
	return false;
}