#pragma once
#include <iostream>
#include <string>
using namespace std;
class login
{
public:
	login();
	~login();
	bool loginAccount();
	
private:
	string account;
	string password;
};

