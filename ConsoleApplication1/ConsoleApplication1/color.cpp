#include "color.h"



color::color()
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handle, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

}

color::~color()
{

}

void color::setColor(int i)
{

	switch (i)
	{
	default:getdefault(); break;
	case 1:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED); break;
	case 2:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); break;
	case 3:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN); break;
	case 4:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE); break;
	case 5:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); break;
	case 6:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE); break;
	case 7:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); break;
	}
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); //红色

	/*FOREGROUND_BLUE 前景色为蓝
		FOREGROUND_GREEN 前景色为绿
		FOREGROUND_RED 前景色为红
		FOREGROUND_INTENSITY 前景色为强光
		BACKGROUND_BLUE 背景色为蓝
		BACKGROUND_GREEN 背景色为绿
		BACKGROUND_RED 背景色为红
		BACKGROUND_INTENSITY 背景色为强光*/

	/*enmCFC_Red = FOREGROUND_INTENSITY | FOREGROUND_RED,
		enmCFC_Green = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
		enmCFC_Blue = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
		enmCFC_Yellow = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
		enmCFC_Purple = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
		enmCFC_Cyan = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
		enmCFC_Gray = FOREGROUND_INTENSITY,
		enmCFC_White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
		enmCFC_HighWhite = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
		enmCFC_Black = 0,*/


	/*enmCBC_Red = BACKGROUND_INTENSITY | BACKGROUND_RED,
		enmCBC_Green = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
		enmCBC_Blue = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
		enmCBC_Yellow = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
		enmCBC_Purple = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
		enmCBC_Cyan = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
		enmCBC_White = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
		enmCBC_HighWhite = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
		enmCBC_Black = 0,*/
}

void color::getdefault()
{
	SetConsoleTextAttribute(handle, wOldColorAttrs);//设置回初始定义的属性，即默认属性
}

void color::setXY(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

