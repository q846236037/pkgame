#include "hud.h"
//打印函数
void console(string params) {
	cout << params << endl;
}
//打印函数多参数
void console(initializer_list<string> il) {
	for (auto par = il.begin(); par != il.end(); par++)
	{
		cout << *par << " ";
	}
	cout << endl;
}
//打印函数
void console(int params) {
	cout << params << endl;
}
//int类型多参数打印函数
void console(initializer_list<int> il) {

	for (auto par = il.begin(); par != il.end(); par++)
	{
		cout << *par << " ";
	}
	cout << endl;
}


hud::hud()
{
	
	this->col = NULL;
	MenuNum = 0;
	MonsterNum = 0;
	LoginNum = 0;
	this->log = NULL;
}


hud::~hud()
{
}

//血条
void hud::drawBlood(int num)
{
	cout << endl;
	cout << "血量:" << " ";
	this->col->setColor(1);
	for (int i = 0;i <= num;i++)
	{
		cout << " ";
	}
	this->col->setColor(4);
	for (int i = 0; i < 20 - num; i++)
	{
		cout << " ";
	}
	cout << endl;
	this->col->getdefault();
	
}
//蓝条
void hud::drawmp(int num)
{
	cout << endl;
	cout << "蓝量:" << " ";
	this->col->setColor(2);
	for (int i = 0; i <= num; i++)
	{
		cout << " ";
	}this->col->setColor(4);
	for (int i = 0; i < 20 - num; i++)
	{
		cout << " ";
	}
	cout << endl;
	this->col->getdefault();
}
//经验条
void hud::drawlevel(int num)
{
	cout << endl;
	cout << "经验:" << " ";
	
	this->col->setColor(3);
	for (int i = 0; i <=num; i++)
	{
		cout << " ";
	}
	this->col->setColor(4);
	for (int i = 0; i <20 - num; i++)
	{
		cout << " ";
	}
	cout << endl;
	this->col->getdefault();
	
}

//设置color类
void hud::setcolor(color * col)
{
	this->col = col;
}

//画菜单
void hud::drawMeun()
{
	system("cls");
	console("———————————————");
		 if (MenuNum == 0)
		 {
			 col->setColor(5);
		 }
		 else {
			 col->setColor();
		 }
	console({ (MenuNum == 0 ? "→":""),"开始游戏" });
	col->setColor();
	if (MenuNum == 1)
	{
		col->setColor(5);
	}
	console({ (MenuNum == 1 ? "→" : ""),"设置难度" });
	col->setColor();
	if (MenuNum == 2)
	{
		col->setColor(5);
	}
	console({ (MenuNum == 2 ? "→" : ""),"退出游戏" });
	col->setColor();
	console("———————————————");
}

//菜单
void hud::Meun()
{
	int ch = 0;
	system("cls");
	drawMonster();
	drawMeun();
	while (1)
	{
		if (_kbhit()) {
			ch = _getch();
			//cout <<"ch="<< ch << endl;
			switch (ch)
			{
			case 13:break;
			case 72:MenuNum <= 0 ? MenuNum = 0 : MenuNum--; drawMeun(); break; //上↑
			case 77: break;//右→
			case 75: break;//左←
			case 80: MenuNum >= 2 ? MenuNum = 2 : MenuNum++; drawMeun(); break;//↓
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//画怪兽
void hud::drawMonster()
{
	system("cls");
	console({ MonsterNum ==0?"      ↓":"",MonsterNum == 1 ? "\t\t\t↓" : "" });
	console({ "  ■      ■  " ,"","      ■■■" });
	console({ "    ■■■  " ,"","      ■■■■■" });
	console({ "  ■  ■  ■  " ,"","  ■■  ■  ■■" });
	console({ "  ■■■■■  " ,"","■  ■■■■■  ■" });
	console({ "■  ■  ■  ■" ,"","    ■  ■  ■" });
	console({ "■  ■  ■  ■" ,"","  ■■      ■■" });
}

//选择怪兽
void hud::selectMonster()
{
	drawMonster();
	int ch = 0;
	while (1)
	{
		if (_kbhit()) {
			ch = _getch();
			//cout <<"ch="<< ch << endl;
			switch (ch)
			{
			case 13:break;
			case 72: break; //上↑
			case 77: MonsterNum >= 1 ? MonsterNum = 1 : MonsterNum++; drawMonster(); break;//右→
			case 75: MonsterNum <= 0 ? MonsterNum = 0 : MonsterNum--; drawMonster(); break;//左←
			case 80: break;//↓
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//画登录
void hud::drawLogin()
{
	system("cls");
	console("————————————————");
	if (LoginNum == 0)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	console({LoginNum==0?"→":"","登录" });
	col->setColor();
	if (LoginNum == 1)
	{
		col->setColor(5);
	}
	console({ LoginNum == 1 ? "→" : "","退出" });
	col->setColor();
	console("————————————————");
}

//选择登录
void hud::selectLogin()
{
	drawLogin();
	int ch = 0;
	while (1)
	{
		if (_kbhit()) {
			ch = _getch();
			//cout <<"ch="<< ch << endl;
			switch (ch)
			{
			case 13:EnterLogin(); break;
			case 72: LoginNum <= 0 ? LoginNum = 0 : LoginNum--; drawLogin(); break; //上↑
			case 77:break;//右→
			case 75:break;//左←
			case 80: LoginNum >= 1? LoginNum = 1 : LoginNum++; drawLogin(); break; break;//↓
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//登录回车
void hud::EnterLogin()
{
	switch (LoginNum)
	{
	default:break;
	case 0:LoginLoading(); break;
	case 1:exitfn(); break;
	}
}

//退出Game
void hud::exitfn()
{
	exit(0);
}

//设置登录类
void hud::setLogin(login * log)
{
	this->log = log;
}

//登录是否成功
void hud::LoginLoading()
{
	console("————————————————");
	if (this->log->loginAccount()) {
		Meun();
	}
	else {
		console("账号或密码错误");
	}
	console("————————————————");
}

void hud::drawtitle()
{

}

//画英雄
void hud::drawHero(int i)
{
	if (i == 1) {
		console("                  ■          ■");
		console("                ■■■  ■  ■■■");
		console("                ■■■■■■■■■");
		console("      ■■■■  ■■■  ■  ■■■");
		console("      ■    ■    ■    ■    ■");
		console("      ■■■■          ■");
		console("  ■■■■■■■■■■■■■");
		console("■■■■■■■■        ■");
		console("■■■■■■■■        ■");
		console("    ■■    ■■");
		console("    ■■    ■■");
		console("    ■■    ■■");
	}
	else if (i == 2) {
		console("    ■");
		console("  ■  ■       ■■■■■");
		console(" ■    ■    ■■■■■■■");
		console("■      ■  ■■■        ■");
		console("  ■■■  ■■■  ■    ■ ■");
		console("    ■    ■■■          ■■");
		console("    ■      ■■■■■■■■");
		console("    ■        ■          ■    ");
		console("    ■       ■            ■ ");
		console("    ■      ■              ■  ");
		console("    ■     ■■■■■■■■■■");
	}
	else if (i == 3) {
		console("                  ■ ■ ■");
		console("    ■         ■      ■  ■   ");
		console("    ■         ■      ■   ■ ");
		console("    ■       ■  ■■■■■■■");
		console("■■■■■  ■   ■  ■     ■ ■");
		console("    ■      ■    ■■■■■■■");
		console("    ■      ■         ■     ■");
		console("    ■      ■■■■■■■■■■ ");
		console("    ■      ■         ■     ■ ");
		console("    ■      ■         ■     ■");
		console("    ■     ■■■■■■■■■■");	  
	}
}


