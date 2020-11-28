#include "login.h"



login::login()
{
}


login::~login()
{
}

bool login::loginAccount(string account, string password)
{
	if (this->account == account&&this->password == password) {
		return true;
	}
	return false;
}
