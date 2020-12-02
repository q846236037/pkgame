#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include "windows.h"
#include "login.h"
#include <fstream>
#include "color.h"
#include "hero.h"
#include "master.h"
#include "pastor.h"
#include "soldier.h"
#include "stage.h"
#include "redmedicine.h"
#include "bluemedicine.h"
#include "quickmedicine.h"
#include "skill.h";
#include "scorchingSun.h";
#include "snowstorm.h";
#include "suddenAdvance.h";
#include "scaleph.h"
using namespace std;
class login;
class stage;
class hud
{
public:
	hud();
	~hud();
	color *col;
	int MenuNum; //菜单数字
	int MonsterNum;//怪兽数字
	int LoginNum;//登录数字
	int heroNum;//英雄数字
	int startNum;//开始数字
	int shopNum;//商品数字
	int stageNum;//道具数字
	int skillNum;//技能数字
	int pkNum;//pk数字
	int makemon;
	int x;//X轴
	int y;//y轴
	hero *her;
	monster *mon1;
	monster *mon2;
	hero **t_her;//二级指针
	login *log;
	void drawBlood(int x, int y,int num = 20,string name =" ");//画血量
	void drawmp(int x, int y, int num = 20);//画蓝量
	void drawlevel(int x, int y, int num = 20);//画等级
	void setcolor(color *col);
	void drawMeun(); //画菜单
	void Meun();//菜单
	void enterMeun();//菜单回车
	void drawMonster(int x,int y,int num = 1,int state = 0);//画怪兽
	void selectMonster();//选择怪兽
	void drawLogin(); //画登录页面
	void selectLogin(); //画登录页面
	void EnterLogin();//登录回车
	void exitfn(); //退出
	void setLogin(login *log);//设置登录类
	void LoginLoading();//登录
	void drawtitle();//画标题
	void drawHero(int i=1,int xsize = 25, int ysize = 5,int state =0); //画英雄
	void drawSelectHero();//画选择英雄
	void moveSelectHero();//移动英雄选择
	void enterMoveSelectHero();//回车移动英雄选择
	void sethero(hero *her);//设置英雄
	int gerHeroNumber();//获得英雄数量
	void drawstart();//画开始界面
	void selectstart(); //开始选择
	void enterSelectStart();//选择回车
	void showHeroInfo();//信息展示界面
	void showshop();//商店界面
	void selectshop();//商店界面
	void entershop();//商店确定
	void saveHero();//保存英雄数据
	void drawstage();//画道具
	int getstageNum(int i);//数量
	void selectstage();//选择道具
	void enterstage();//道具回车
	bool is_start;//是否开始
	void drawskill();//画技能
	void selecskill();//选择技能
	void enterskill();//技能回车
	void drawpk(int state =0);//战斗界面
	void setmon(monster *mon,int i);//设置mon;
	void selectPkNum();//选择pk界面
	void enterPk();//pk 回车
	void drawPkSkill();//画战斗技能
	int pkskilNum;//战斗技能数字
	void selectpkSkill();//选择战斗技能
	void enterSelectPkskill();//回车战斗技能
	void drawcube(int x, int y,bool b = true);//画立方体
	void enterselectpk();//选择战斗怪兽回车;
	int is_anm;
};

