#pragma once
#include<windows.h>
class color
{
public:
	color();
	~color();
	HANDLE handle;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	WORD wOldColorAttrs;
	void setColor(int i = 0);
	void getdefault();
};

