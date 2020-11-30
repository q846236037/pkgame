#pragma once
#include "color.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "windows.h"
#include "login.h"
#include <fstream>
#include "hero.h"
#include "master.h"
#include "pastor.h"
#include "soldier.h"
using namespace std;
class login;
class hud
{
public:
	hud();
	~hud();
	color *col;
	int MenuNum; //�˵�����
	int MonsterNum;//��������
	int LoginNum;//��¼����
	int heroNum;//Ӣ������
	int x;//X��
	int y;//y��
	hero *her;
	hero **t_her;//����ָ��
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
	void drawHero(int i=1,int xsize = 40, int ysize = 5); //��Ӣ��
	void drawSelectHero();//ѡ��Ӣ��
	void moveSelectHero();//�ƶ�Ӣ��ѡ��
	void enterMoveSelectHero();//�س��ƶ�Ӣ��ѡ��

	void sethero(hero *her);//����Ӣ��
	int gerHeroNumber();//���Ӣ������
};

