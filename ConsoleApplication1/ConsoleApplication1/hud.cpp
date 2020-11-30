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
	heroNum = 0;
	x = 40;
	y = 5;
	this->her = NULL;
	this->t_her = NULL;
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
	drawHero(heroNum);
	col->setXY(x, y++);
	console("———————————————");
		 if (MenuNum == 0)
		 {
			 col->setColor(5);
		 }
		 else {
			 col->setColor();
		 }
		 col->setXY(x+=10, y++);
	console({ (MenuNum == 0 ? "→":""),"开始游戏" });
	col->setColor();
	if (MenuNum == 1)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	console({ (MenuNum == 1 ? "→" : ""),"设置难度" });
	col->setColor();
	if (MenuNum == 2)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	console({ (MenuNum == 2 ? "→" : ""),"退出游戏" });
	col->setColor();
	col->setXY(x = 40, y++);
	console("———————————————");
}

//菜单
void hud::Meun()
{
	int ch = 0;	
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
	drawHero(0);
	col->setXY(x, y++);
	console("————————————————");
	if (LoginNum == 0)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	col->setXY(x+=10, y++);
	console({LoginNum==0?"→":"","登录" });
	col->setColor();
	if (LoginNum == 1)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	console({ LoginNum == 1 ? "→" : "","退出" });
	col->setColor();
	col->setXY(x = 40, y++);
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
	system("cls");
	drawHero(0);
	col->setXY(x, y++);
	console("————————————————");
	if (this->log->loginAccount()) {
		moveSelectHero();
	}
	else {
		col->setXY(x, y++);
		console("账号或密码错误");
		col->setXY(x,y++);
		console("3s后请重新输入");
		Sleep(3000);
		LoginLoading();
	}
	console("————————————————");
}

void hud::drawtitle()
{

}

//画英雄
void hud::drawHero(int i,int xsize, int ysize)
{
	x = xsize;
	y = ysize;
	if (i == 0) {
		col->setXY(x, y++);
		console("                  ■          ■"); col->setXY(x, y++);
		console("                ■■■  ■  ■■■"); col->setXY(x, y++);
		console("                ■■■■■■■■■"); col->setXY(x, y++);
		console("      ■■■■  ■■■  ■  ■■■"); col->setXY(x, y++);
		console("      ■    ■    ■    ■    ■"); col->setXY(x, y++);
		console("      ■■■■          ■"); col->setXY(x, y++);
		console("  ■■■■■■■■■■■■■"); col->setXY(x, y++);
		console("■■■■■■■■        ■"); col->setXY(x, y++);
		console("■■■■■■■■        ■"); col->setXY(x, y++);
		console("    ■■    ■■"); col->setXY(x, y++);
		console("    ■■    ■■"); col->setXY(x, y++);
		console("    ■■    ■■");
	}
	else if (i == 1) {
		col->setXY(x, y++);
		console("    ■"); col->setXY(x, y++);
		console("  ■  ■       ■■■■■"); col->setXY(x, y++);
		console(" ■    ■    ■■■■■■■"); col->setXY(x, y++);
		console("■      ■  ■■■        ■"); col->setXY(x, y++);
		console("  ■■■  ■■■  ■    ■ ■"); col->setXY(x, y++);
		console("    ■    ■■■          ■■"); col->setXY(x, y++);
		console("    ■      ■■■■■■■■"); col->setXY(x, y++);
		console("    ■        ■          ■    "); col->setXY(x, y++);
		console("    ■       ■            ■ "); col->setXY(x, y++);
		console("    ■      ■              ■  "); col->setXY(x, y++);
		console("    ■     ■■■■■■■■■■");
	}
	else if (i == 2) {
		col->setXY(x, y++);
		console("                  ■ ■ ■"); col->setXY(x, y++);
		console("    ■         ■      ■  ■   "); col->setXY(x, y++);
		console("    ■         ■      ■   ■ "); col->setXY(x, y++);
		console("    ■       ■  ■■■■■■■"); col->setXY(x, y++);
		console("■■■■■  ■   ■  ■     ■ ■"); col->setXY(x, y++);
		console("    ■      ■    ■■■■■■■"); col->setXY(x, y++);
		console("    ■      ■         ■     ■"); col->setXY(x, y++);
		console("    ■      ■■■■■■■■■■ "); col->setXY(x, y++);
		console("    ■      ■         ■     ■ "); col->setXY(x, y++);
		console("    ■      ■         ■     ■"); col->setXY(x, y++);
		console("    ■     ■■■■■■■■■■");
	}
}

//选择英雄
void hud::drawSelectHero()
{
	system("cls");
	drawHero(heroNum);
	col->setXY(x, y++);
	console("————————————————");
	if (heroNum == 0)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	col->setXY(x+=5, y);
	cout << (heroNum == 0 ? "→" : "") << "战士"<<"    ";
	col->setColor();
	if (heroNum == 1)
	{
		col->setColor(5);
	}
	col->setXY(x += 10, y);
	cout << (heroNum == 1 ? "→" : "") << "法士" << "    ";
	col->setColor();
	if (heroNum == 2)
	{
		col->setColor(5);
	}
	col->setXY(x += 10, y++);
	cout << (heroNum == 2 ? "→" : "") << "牧士";
	col->setColor();
	cout << endl;
	col->setXY(x = 40, y++);
	console("————————————————");
}

//移动英雄选择
void hud::moveSelectHero()
{
	int ch = 0;
	drawSelectHero();
	while (1)
	{
		if (_kbhit()) {
			ch = _getch();
			//cout <<"ch="<< ch << endl;
			switch (ch)
			{
			case 13:enterMoveSelectHero(); break;
			case 77: heroNum >= 2 ? heroNum = 2 : heroNum++; drawSelectHero(); break;//右→
			case 75: heroNum <= 0 ? heroNum = 0 : heroNum--; drawSelectHero(); break;//左←
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//选择英雄
void hud::enterMoveSelectHero()
{
	hero *her = NULL;
	
	ifstream ifs;
	int title = gerHeroNumber();
	if (title>0) {
		ifs.open("hero.txt", ios::in);
		int num = 0;
		int heroNum;
		t_her = new hero *[title];
		int i = 0;
		string name;//名字
		int mp;// 法力值上限
		int hp;//血量上限
		int  level;//级别
		int max_level;//升级所需经验
		int money;//金钱
		int hurt;//伤害
		int defense;//防御
		while (ifs >> heroNum >> name >> mp >> hp >> level >> max_level >> money >> hurt >> defense);
		{
			if (heroNum == 0)
			{
				t_her[i] = new soldier(name, mp, hp, level, max_level, money, hurt, defense);
				her = t_her[i];
				Meun();
			}
			else if (heroNum == 1) {
				t_her[i] = new master(name,mp,hp,level,max_level,money,hurt,defense);
				her = t_her[i];
				Meun();
			}
			else if (heroNum == 2) {
				t_her[i] = new pastor(name, mp, hp, level, max_level, money, hurt, defense);
				her = t_her[i];
				Meun();
			}
			i++;
		}
		
	}
	else {
		if (heroNum == 0) {
			her = new soldier;
			this->her = her;
		}
		else if (heroNum == 1) {
			her = new master;
			this->her = her;
		}
		else if (heroNum == 2) {
			her = new pastor;
			this->her = her;
		}
		ofstream ofs;
		ofs.open("hero.txt", ios::app);
		string name;//名字
		col->setXY(x, y++);
		cout << "请输入名字:";
		cin >> name;
		/*int mp;// 法力值上限
		int hp;//血量上限
		int  level;//级别
		int max_level;//升级所需经验
		int money;//金钱
		int hurt;//伤害
		int defense;//防御*/
		ofs << heroNum << " " <<name <<" "<<her->mp <<" "<<her->hp << " " <<her->level << " " <<her->max_level << " " <<her->money << " " <<her->hurt << " " <<her->defense;
		ofstream;
		Meun();
	}
	
}

//设置英雄
void hud::sethero(hero *her)
{
	this->her = her;
}

//获得英雄数量
int hud::gerHeroNumber()
{
	int num = 0;
	ifstream ifs;
	ifs.open("hero.txt", ios::in);
	if (ifs.is_open()) {
		string name; //名字
		int mp; // 法力值上限
		int hp;//血量上限
		int  level;//级别
		int max_level;//升级所需经验
		int money;//金钱
		int hurt;//伤害
		int defense; //防御
		while (ifs >> heroNum >> name >> mp>> hp>> level>> max_level>> money>> hurt>> defense)
		{
			num++;
		}
		return num;

	}
	else {
		return 0;
	}
}


