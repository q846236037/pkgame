#pragma once
#include "color.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "windows.h"
#include "login.h"
using namespace std;
class hud
{
public:
	hud();
	~hud();
	color *col;
	int MenuNum; //�˵�����
	int MonsterNum;//��������
	int LoginNum;//��¼����
	login *log;
	void drawBlood(int num = 20);//��Ѫ��
	void drawmp(int num = 20);//������
	void drawlevel(int num = 20);//���ȼ�
	void setcolor(color *col);
	void drawMeun(); //���˵�
	void Meun();//�˵�
	void drawMonster();//������
	void selectMonster();//ѡ�����
	void drawLogin(); //����¼ҳ��
	void selectLogin(); //����¼ҳ��
	void EnterLogin();//��¼�س�
	void exitfn(); //�˳�
	void setLogin(login *log);//���õ�¼��
	void LoginLoading();//��¼
	void drawtitle();//������
	void drawHero(int i=1); //��Ӣ��
};

