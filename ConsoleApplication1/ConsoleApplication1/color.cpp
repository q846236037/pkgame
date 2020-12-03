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
	case 5:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_RED); break;
	case 6:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE); break;
	case 7:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); break;
	case 8:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE); break;
	case 9:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); break;
	}
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); //��ɫ

	/*FOREGROUND_BLUE ǰ��ɫΪ��
		FOREGROUND_GREEN ǰ��ɫΪ��
		FOREGROUND_RED ǰ��ɫΪ��
		FOREGROUND_INTENSITY ǰ��ɫΪǿ��
		BACKGROUND_BLUE ����ɫΪ��
		BACKGROUND_GREEN ����ɫΪ��
		BACKGROUND_RED ����ɫΪ��
		BACKGROUND_INTENSITY ����ɫΪǿ��*/

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
	SetConsoleTextAttribute(handle, wOldColorAttrs);//���ûس�ʼ��������ԣ���Ĭ������
}

void color::setXY(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

