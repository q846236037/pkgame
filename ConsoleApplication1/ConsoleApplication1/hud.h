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
	int MenuNum; //菜单数字
	int MonsterNum;//怪兽数字
	int LoginNum;//登录数字
	login *log;
	void drawBlood(int num = 20);//画血量
	void drawmp(int num = 20);//画蓝量
	void drawlevel(int num = 20);//画等级
	void setcolor(color *col);
	void drawMeun(); //画菜单
	void Meun();//菜单
	void drawMonster();//画怪兽
	void selectMonster();//选择怪兽
	void drawLogin(); //画登录页面
	void selectLogin(); //画登录页面
	void EnterLogin();//登录回车
	void exitfn(); //退出
	void setLogin(login *log);//设置登录类
	void LoginLoading();//登录
	void drawtitle();//画标题
	void drawHero(int i=1); //画英雄
};

