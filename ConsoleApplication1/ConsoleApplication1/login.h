#pragma once
#include <iostream>
using namespace std;
class login
{
public:
	login();
	~login();
	bool loginAccount(string account, string password);
private:
	string account;
	string password;
};

