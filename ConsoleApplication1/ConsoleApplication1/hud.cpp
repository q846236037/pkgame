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
	MonsterNum = -1;
	LoginNum = 0;
	startNum = 0;
	stageNum = 0;
	this->log = NULL;
	heroNum = 0;
	x = 25;
	y = 5;
	this->her = NULL;
	this->t_her = NULL;
	is_start = false;
	mon1 = NULL;
	mon2 = NULL;
	makemon = 0;
	pkskilNum = 0;
	is_anm = 0;
}


hud::~hud()
{
}

//血条
void hud::drawBlood(int x, int y, int num,string name)
{
	cout << endl;
	col->setXY(x, y);
	if (name == " ") {
		cout << "血量:" << " ";
	}
	else {
		cout <<name<<" 血量:" << " ";
	}
	
	this->col->setColor(1);
	
	for (int i = 0;i < num;i++)
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
void hud::drawmp(int x, int y, int num)
{
	cout << endl;
	col->setXY(x, y);
	cout << "蓝量:" << " ";
	this->col->setColor(2);
	for (int i = 0; i < num; i++)
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
void hud::drawlevel(int x, int y, int num)
{
	cout << endl;
	col->setXY(x, y);
	cout << "经验:" << " ";
	this->col->setColor(3);
	for (int i = 0; i <num; i++)
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
	console({ (MenuNum == 2 ? "→" : ""),"角色选择" });
	col->setColor();
	if (MenuNum == 3)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	console({ (MenuNum == 3 ? "→" : ""),"退出游戏" });
	col->setColor();
	col->setXY(x = 25, y++);
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
			case 13:enterMeun();break;
			case 72:MenuNum <= 0 ? MenuNum = 0 : MenuNum--; drawMeun(); break; //上↑
			case 77: break;//右→
			case 75: break;//左←
			case 80: MenuNum >= 3? MenuNum = 3 : MenuNum++; drawMeun(); break;//↓
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//菜单回车
void hud::enterMeun()
{
	if (MenuNum ==0)
	{
		selectstart();
	}
	else if (MenuNum == 1) {

	}else if (MenuNum ==2)
	{
		moveSelectHero();
	}
	else if (MenuNum == 3) {
		exitfn();
	}
}

//画怪兽
void hud::drawMonster(int x, int y,int num, int state)
{
	
	if (num ==1) {
		
		col->setXY(x, y++);
		col->setColor(5);
		console({ MonsterNum == 0 ? "      ↓" : ""}); col->setXY(x, y++);
		col->setColor(0);
		if (mon1 != NULL&&mon1->state == 1) {
			col->setColor(8);
		}
		if (mon1 != NULL&&mon1->state == 2) {
			col->setColor(9);
		}
		if (MonsterNum == 0)
		{
			col->setColor(5);
		}
		if (state == 1) {
			col->setColor(5);
		}
		console({ "  ■      ■  "  }); col->setXY(x, y++);
		console({ "    ■■■  "  }); col->setXY(x, y++);
		console({ "  ■  ■  ■  "  }); col->setXY(x, y++);
		console({ "  ■■■■■  " }); col->setXY(x, y++);
		console({ "■  ■  ■  ■"}); col->setXY(x, y++);
		console({ "■  ■  ■  ■" }); col->setXY(x, y);
		col->setColor();
	}
	else if(num ==2){
		col->setXY(x, y++);
		col->setColor(5);
		console({ MonsterNum == 1 ? "        ↓" : "" }); col->setXY(x, y++);
		col->setColor(0);
		if (mon2 != NULL&&mon2->state == 1) {
			col->setColor(8);
		}
		if (mon1 != NULL&&mon1->state == 2) {
			col->setColor(9);
		}
		if (MonsterNum ==1)
		{
			col->setColor(5);
		}
		if (state == 1) {
			col->setColor(5);
		}
	
		console({ "      ■■■" }); col->setXY(x, y++);
		console({"    ■■■■■" }); col->setXY(x, y++);
		console({"  ■■  ■  ■■" }); col->setXY(x, y++);
		console({"■  ■■■■■  ■" }); col->setXY(x, y++);
		console({"    ■  ■  ■" }); col->setXY(x, y++);
		console({"  ■■      ■■" }); col->setXY(x, y);
		col->setColor();
	}
	
}

//选择怪兽
void hud::selectMonster()
{
	MonsterNum = 0;
	drawpk();
	int ch = 0;
	if (mon1->hp>0&&mon2->hp>0)
	{
		while (1)
	{
		if (_kbhit()) {
			ch = _getch();
			//cout <<"ch="<< ch << endl;
			switch (ch)
			{
			case 13:enterselectpk();break;
			case 72: break; //上↑
			case 77: MonsterNum >= 1 ? MonsterNum = 1 : MonsterNum++; drawpk(); break;//右→
			case 75: MonsterNum <= 0 ? MonsterNum = 0 : MonsterNum--; drawpk(); break;//左←
			case 80: break;//↓
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
	}
	else if (mon1->hp > 0 && mon2->hp <= 0) {
		MonsterNum = 0;
		enterselectpk();
	}
	else if (mon2->hp > 0 && mon1->hp <= 0) {
		MonsterNum = 1;
		enterselectpk();
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
	col->setXY(x = 25, y++);
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
void hud::drawHero(int i,int xsize, int ysize,int state)
{
	system("cls");
	x = xsize;
	y = ysize;
	if (state ==1)
	{
		col->setColor(5);
	}

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
		col->setColor();
	
}

//画选择英雄
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
	col->setXY(x = 25, y++);
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
	this->her = NULL;
	ifstream  ifs;
	int title = gerHeroNumber();
	if (title>0) {
		ifs.open("hero.txt", ios::in);
		
		t_her = new hero *[title];
		string name; //名字
		int mp; // 法力值上限
		int hp;//血量上限
		int  level;//级别
		int max_level;//升级所需经验
		int money;//金钱
		int hurt;//伤害
		int defense; //防御
		int id;//id;
		int nowlevel;
		int num = 0;
		while (ifs >> name&&ifs >> mp&&ifs >> hp&&ifs >> level&&ifs >> max_level&&ifs >> money&&ifs >> hurt&&ifs >> defense&&ifs >> id&&ifs >> nowlevel)
		{
			if (id == 0)
			{
				t_her[num] = new soldier(name, mp, hp, level, max_level, money, hurt, defense, id, nowlevel);
			}
			else if (id == 1) {
				t_her[num] = new master(name, mp, hp, level, max_level, money, hurt, defense, id, nowlevel);
			}
			else if (id == 2) {
				t_her[num] = new pastor(name, mp, hp, level, max_level, money, hurt, defense, id, nowlevel);
			}
			num++;
			
		}
		ifs.close();
		for (int i = 0;i<title;i++)
		{
			if (this->heroNum == t_her[i]->id) {
				this->her = t_her[i];
				Meun();
			}
		}
	}
	if (heroNum == 0) {
		this->her = new soldier;
	}
	else if (heroNum == 1) {
		this->her = new master;
	}
	else if (heroNum == 2) {
		this->her = new pastor;
	}
		ofstream ofs;
	ofs.open("hero.txt", ios::app);
	string name;//名字
	col->setXY(x, y++);
	cout << "请输入名字:";
	cin >> name;
	int mp;// 法力值上限
	int hp;//血量上限
	int  level;//级别
	int max_level;//升级所需经验
	int money;//金钱
	int hurt;//伤害
	int defense;//防御
	int i = 0;
	int id;
	int nowlevel;
	her->name = name;
	ofs<< her->name <<" "<<her->mp <<" "<<her->hp << " " <<her->level << " " <<her->max_level << " " <<her->money << " " <<her->hurt << " " <<her->defense<<" "<<her->id<<" "<< her->nowlevel<<endl;
	ofs.close();
	ifs.open("hero.txt", ios::in);
	t_her = new hero *[title];
	while (ifs >> name&&ifs >> mp&&ifs >> hp&&ifs >> level&&ifs >> max_level&&ifs >> money&&ifs >> hurt&&ifs >> defense&&ifs >> id&&ifs >> nowlevel);
	{

		if (id == 0)
		{
			t_her[i] = new soldier(name, mp, hp, level, max_level, money, hurt, defense, id, nowlevel);
		}
		else if (id == 1) {
			t_her[i] = new master(name, mp, hp, level, max_level, money, hurt, defense, id, nowlevel);
		}
		else if (id == 2) {
			t_her[i] = new pastor(name, mp, hp, level, max_level, money, hurt, defense, id, nowlevel);
		}
		i++;
	}
	ifs.close();
	Meun();
	
	
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
		int id;//id;
		int nowlevel;
		while (ifs >> name&&ifs >> mp&&ifs >> hp&&ifs >> level&&ifs >> max_level&&ifs >> money&&ifs >> hurt&&ifs >> defense&&ifs >>id&&ifs >> nowlevel)
		{
			num++;
		}
		ifs.close();
		return num;

	}
	else {
		ifs.close();
		return 0;
	}
	return 0;
}

//画开始界面
void hud::drawstart()
{
	drawHero(heroNum);
	col->setXY(x, y++);
	console("————————————————");
	if (startNum == 0)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	col->setXY(x, y);
	cout << (startNum == 0 ? "→" : "") << "战斗" << "    ";
	col->setColor();
	if (startNum == 1)
	{
		col->setColor(5);
	}
	col->setXY(x += 9, y);
	cout << (startNum == 1 ? "→" : "") << "技能" << "    ";
	col->setColor();
	if (startNum == 2)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	col->setXY(x += 9, y);
	cout << (startNum == 2 ? "→" : "") << "道具" << "    ";
	col->setColor();
	if (startNum == 3)
	{
		col->setColor(5);
	}
	col->setXY(x += 9, y++);
	cout << (startNum == 3 ? "→" : "") << "商城" << "    ";
	col->setColor();
	if (startNum == 4)
	{
		col->setColor(5);
	}
	col->setXY(x =25, y+=2);
	cout << (startNum == 4 ? "→" : "") << "信息" << "    ";
	col->setColor();
	if (startNum == 5)
	{
		col->setColor(5);
	}
	col->setXY(x +=9, y++);
	cout << (startNum == 5 ? "→" : "") << "返回" << "    ";
	col->setColor();
	col->setXY(x =25, y++);
	console("————————————————");
}

//开始界面选择
void hud::selectstart()
{
	int ch = 0;
	drawstart();
	while (1)
	{
		if (_kbhit()) {
			ch = _getch();
			//cout <<"ch="<< ch << endl;
			switch (ch)
			{
			case 13:enterSelectStart(); break;
			case 72:(startNum - 4)< 0 ? startNum  : startNum -= 4; drawstart(); break; //上↑
			case 77: startNum >= 5 ? startNum = 5 : startNum++; drawstart(); break;//右→
			case 75: startNum <= 0 ? startNum = 0 : startNum--; drawstart(); break;//左←
			case 80: (startNum + 4)> 5 ? startNum  : startNum += 4; drawstart(); break;//↓
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//开始界面回车事件
void hud::enterSelectStart()
{
	
	switch (startNum)
	{
	default:break;
	case 0:selectPkNum(); break;
	case 1:selecskill();break;
	case 2:this->is_start = false;selectstage(); break;
	case 3:selectshop(); break;
	case 4:showHeroInfo(); break;
	case 5:Meun(); break;
	}
}

//信息展示界面
void hud::showHeroInfo()
{
	drawHero(heroNum);
	col->setXY(x, y++);
	console("————————————————");
	col->setXY(x+=10, y++);
	console({ "姓名：",her->name });
	col->setXY(x, y++);
	console({ "血量：",to_string(her->hp) });
	col->setXY(x, y++);
	console({ "法力值：",to_string(her->mp) });
	col->setXY(x, y++);
	console({ "攻击力：",to_string(her->hurt) });
	col->setXY(x, y++);
	console({ "防御：",to_string(her->defense) });
	col->setXY(x, y++);
	console({ "等级：",to_string(her->level) });
	col->setXY(x, y++);
	console({ "金钱：",to_string(her->money) });
	col->setXY(x, y++);
	console({ "经验：",to_string(her->nowlevel) });
	col->setXY(x = 25, y++);
	console("————————————————");
	Sleep(3000);
	selectstart();
}

//商店界面
void hud::showshop()
{
	drawHero(heroNum);
	col->setXY(x =25, y++);
	console("————————————————");
	if (shopNum == 0)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	col->setXY(x, y++);

	bluemedicine b;
	console({shopNum==0?"→":"",b.name,"：回复100蓝量  金钱:",to_string(b.money)});
	col->setColor();
	if (shopNum == 1)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	redmedicine r;
	console({ shopNum == 1 ? "→" : "",r.name,"：回复100血量  金钱:",to_string(r.money) });
	col->setColor();
	col->setXY(x, y++);
	if (shopNum == 2)
	{
		col->setColor(5);
	}
	quickmedicine q;
	console({ shopNum == 2 ? "→" : "",q.name,"：随机升降(1~3)级 金钱:",to_string(q.money) });
	col->setColor();
	col->setXY(x, y++);
	if (shopNum == 3)
	{
		col->setColor(5);
	}
	console({ shopNum == 3 ? "→" : "","返回"});
	col->setColor();
	col->setXY(x = 25, y++);
	console("————————————————");
}

//商店选择
void hud::selectshop()
{
	int ch = 0;
	showshop();
	while (1)
	{
		if (_kbhit()) {
			ch = _getch();
			//cout <<"ch="<< ch << endl;
			switch (ch)
			{
			case 13:entershop(); break;
			case 72:shopNum <= 0 ? shopNum = 0 : shopNum--; showshop(); break; //上↑
			case 80: shopNum >= 3 ? shopNum = 3 : shopNum++; showshop(); break;//↓
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//商店回车
void hud::entershop()
{
	stage *st = NULL;
	
	if (shopNum ==0)
	{
		st = new bluemedicine();
		st->setcolor(col);
		st->sethero(her);
		st->setHud(this);
		st->buy();
		Sleep(3000);
		selectshop();
	}
	else if (shopNum == 1) {
	  st = new redmedicine();
	  st->setcolor(col);
	  st->sethero(her);
	  st->setHud(this);
		st->buy();
		Sleep(3000);
		selectshop();
	}
	else if (shopNum == 2) {
		st = new quickmedicine();
		st->setcolor(col);
		st->sethero(her);
		st->setHud(this);
		st->buy();
		Sleep(3000);
		selectshop();
	}
	else if (shopNum == 3) {
		selectstart();
	}
}


//保存英雄
void hud::saveHero()
{
	int len = gerHeroNumber();
	for (int i = 0;i<len;i++)
	{
		if (t_her[i]->id == her->id) {
			t_her[i] = her;
		}
	}
	ofstream ofs;
	ofs.open("hero.txt", ios::out);
	for (int i = 0; i <len; i++)
	{
		
			ofs << t_her[i]->name << " " << t_her[i]->mp << " " << t_her[i]->hp << " " << t_her[i]->level << " " << t_her[i]->max_level << " " << t_her[i]->money << " " << t_her[i]->hurt << " " << t_her[i]->defense << " " << t_her[i]->id << " " << t_her[i]->nowlevel << endl;
		
	}
	ofs.close();
}

//画道具
void hud::drawstage()
{
	stage *sta;
	drawHero(heroNum);
	col->setXY(x, y++);
	console("————————————————");
	sta = new bluemedicine;
	col->setXY(x += 10, y++);
	if (stageNum == 0)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	console({stageNum ==0?"→":"" ,sta->name, to_string(getstageNum(0))});
	col->setColor();
	if (stageNum == 1)
	{
		col->setColor(5);
	}
	sta = new redmedicine;
	col->setXY(x, y++);
	console({ stageNum == 1 ? "→" : "" ,sta->name, to_string(getstageNum(1)) });
	col->setColor();
	sta = new quickmedicine;
	if (stageNum == 2)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	console({ stageNum == 2 ? "→" : "",sta->name, to_string(getstageNum(2)) });
	col->setColor();
	col->setXY(x, y++);
	if (stageNum == 3)
	{
		col->setColor(5);
	}
	console({ stageNum == 3 ? "→" : "","返回"});
	col->setColor();
	col->setXY(x = 25, y++);
	console("————————————————");
}

//获取道具数量
int hud::getstageNum(int i)
{
	// 0 蓝药 1 红药 2灵药
	ifstream ifs;
	ifs.open("stage.txt", ios::in);
	int h_id;
	int s_id;
	int num = 0;
	while (ifs>> h_id >> s_id)
	{
		if (h_id == heroNum) {
			if (s_id == i) {
				num++;
			}
		}
	}
	ifs.close();
	return num;
}

//道具选择
void hud::selectstage()
{
	int ch = 0;
	drawstage();
	while (1)
	{
		if (_kbhit()) {
			ch = _getch();
			//cout <<"ch="<< ch << endl;
			switch (ch)
			{
			case 13:enterstage(); break;
			case 72:stageNum <= 0 ? stageNum = 0 : stageNum--; drawstage(); break; //上↑
			case 80: stageNum >= 3 ? stageNum = 3 : stageNum++; drawstage(); break;//↓
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//使用道具
void hud::enterstage()
{
	if (stageNum ==0)
	{

		stage *sta = new bluemedicine;
		sta->sethero(her);
		sta->setcolor(col);
		sta->setHud(this);
		sta->use();
		saveHero();
		Sleep(2000);
		if (is_start) {
			MonsterNum = -1;
			enterselectpk();
		}else{
			selectstage();
		}
	}
	else if (stageNum == 1) {
		stage *sta = new redmedicine;
		sta->sethero(her);
		sta->setcolor(col);
		sta->setHud(this);
		sta->use();
		saveHero();
		Sleep(2000);
		if (is_start) {
			MonsterNum = -1;
			enterselectpk();
		}
		else {
			selectstage();
		}
	}
	else if (stageNum == 2) {
		stage *sta = new quickmedicine;
		sta->sethero(her);
		sta->setcolor(col);
		sta->setHud(this);
		sta->use();
		saveHero();
		Sleep(2000);
		if (is_start) {
			MonsterNum = -1;
			enterselectpk();
		}
		else {
			selectstage();
		}
	}
	else if (stageNum == 3) {
		if (is_start) {
			selectPkNum();
		}
		else {
			selectstart();
		}
	}
}

//画技能
void hud::drawskill()
{
	skill *sk;
	drawHero(heroNum);
	switch (skillNum)
	{
	default:break;
	case 0: sk = new snowstorm; sk->setcolor(col); sk->lookSkill(); break;
	case 1: sk = new scorchingSun; sk->setcolor(col); sk->lookSkill(); break;
	case 2: sk = new suddenAdvance; sk->setcolor(col); sk->lookSkill(); break;
	}
	col->setXY(x, y++);
	console("————————————————");
	sk = new snowstorm;
	col->setXY(x += 1, y++);
	if (skillNum == 0)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	sk->sethero(her);
	int num = sk->getIsStudent(sk->id);
	console({ skillNum == 0 ? "→" : "" ,sk->name,"等级",to_string(sk->level),"可学习",num>0?"已学会":"未学会"});
	col->setColor();
	if (skillNum == 1)
	{
		col->setColor(5);
	}
	sk = new scorchingSun;
	col->setXY(x, y++);
	sk->sethero(her);
	num = sk->getIsStudent(sk->id);
	console({ skillNum == 1 ? "→" : "" ,sk->name,"等级",to_string(sk->level),"可学习",num>0 ? "已学会" : "未学会" });
	col->setColor();
	sk = new suddenAdvance;
	if (skillNum == 2)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	sk->sethero(her);
	num = sk->getIsStudent(sk->id);
	console({ skillNum == 2 ? "→" : "",sk->name,"等级",to_string(sk->level),"可学习",num>0 ? "已学会" : "未学会" });
	col->setColor();
	col->setXY(x, y++);
	if (skillNum == 3)
	{
		col->setColor(5);
	}
	console({ skillNum == 3 ? "→" : "","返回" });
	col->setColor();
	col->setXY(x = 25, y++);
	console("————————————————");
}

//选择技能
void hud::selecskill()
{
	
	int ch = 0;
	drawskill();
	while (1)
	{
		if (_kbhit()) {
			ch = _getch();
			//cout <<"ch="<< ch << endl;
			switch (ch)
			{
			case 13:enterskill(); break;
			case 72:skillNum <= 0 ? skillNum = 0 : skillNum--; drawskill(); break; //上↑
			case 80: skillNum >= 3 ? skillNum = 3 : skillNum++; drawskill(); break;//↓
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//技能回车
void hud::enterskill()
{
	if (skillNum == 0)
	{
		/*if (heroNum == 1)
		{*/
			skill *sk;
			sk = new snowstorm;
			sk->sethero(her);
			sk->setcolor(col);
			sk->studentSkill();
			Sleep(3000);
			drawskill();
		/*}*/
		
	}
	else if (skillNum == 1) {
		/*if (heroNum == 1)
		{*/
			skill *sk;
			sk = new scorchingSun;
			sk->sethero(her);
			sk->setcolor(col);
			sk->studentSkill();
			Sleep(3000);
			drawskill();
		/*}*/
	}
	else if (skillNum == 2) {
		/*if (heroNum == 1)
		{*/
			skill *sk;
			sk = new suddenAdvance;
			sk->sethero(her);
			sk->setcolor(col);
			sk->studentSkill();
			Sleep(3000);
			drawskill();
		/*}*/
	}
	else if (skillNum == 3) {
			selectstart();
	}

}

//画pk游戏
void hud::drawpk(int state )
{
	if (state ==0)
	{
		drawHero(heroNum, 2, 6);
	}
	else if (state == 1) {
		drawHero(heroNum, 2, 6,1);
	}
	if (mon1->hp>0)
	{
		drawMonster(45, 10, 1);
		drawBlood(45, 1, mon1->hp / 10, "乌贼");
	}
	if (mon2->hp>0)
	{
		drawMonster(60, 10, 2);
		drawBlood(45, 3, mon2->hp / 10, "章鱼");
	}
	
	drawBlood(2, 1,her->hp/10);
	drawmp(2, 3,her->mp/10);
	drawlevel(2, 5,(int)(her->nowlevel/10));
	col->setXY(x=0, y++);
	console("————————————————————————————————————————");
	if(is_anm == 0){
		if (pkNum == 0)
		{
			col->setColor(5);
		}
		else {
			col->setColor();
		}
		col->setXY(x+=9, y);
		cout << (pkNum == 0 ? "→" : "") << "战斗" << "    ";
		col->setColor();
		if (pkNum == 1)
		{
			col->setColor(5);
		}
		col->setXY(x += 18, y);
		cout << (pkNum == 1 ? "→" : "") << "技能" << "    ";
		col->setColor();
		if (pkNum == 2)
		{
			col->setColor(5);
		}
		else {
			col->setColor();
		}
		col->setXY(x += 18, y);
		cout << (pkNum == 2 ? "→" : "") << "道具" << "    ";
		col->setColor();
		if (pkNum == 3)
		{
			col->setColor(5);
		}
		col->setXY(x += 18, y++);
		cout << (pkNum == 3 ? "→" : "") << "返回" << "    ";
		col->setColor();
		col->setXY(x = 0, y++);
	}
	else if (is_anm == 1) {
		col->setXY(x = 30, y++);
		console({ "我方发起了攻击造成了",to_string(her->hurt-mon1->defense),"伤害" });
	}
	else if (is_anm == 2) {
		col->setXY(x = 30, y++);
		console({ "乌贼发起了攻击造成了",to_string(mon2->hurt - her->defense),"伤害" });
	}
	else if (is_anm == 3) {
		col->setXY(x = 30, y++);
		console({ "章鱼发起了攻击造成了",to_string(mon2->hurt-her->defense),"伤害" });
	}
	else if (is_anm == 4) {
		col->setXY(x = 20, y++);
		console({ "战斗胜利获得",to_string(mon1->level+mon2->level),"经验"});
		col->setXY(x = 20, y++);
		console({ "获得",to_string(mon1->money + mon2->money),"金钱" });
	}
	else if (is_anm == 5) {
		col->setXY(x = 20, y++);
		console({ "恭喜升级当前等级",to_string(her->level),"快去学习新技能吧" });
	}
	else if (is_anm == 6) {
		col->setXY(x = 20, y++);
		console({ "怪物们都被冻结无法攻击"});
	}
	else if (is_anm == 7) {
		col->setXY(x = 20, y++);
		console({ "怪物们都被灼烧，持续掉血三回合，概率因麻痹不能攻击" });
	}
	else if (is_anm == 8) {
		col->setXY(x = 20, y++);
		skill *sk = new scorchingSun;
		console({ "乌贼因为灼烧效果，损失",to_string(sk->hurt),"血量" });
		
	}
	else if (is_anm == 9) {
		col->setXY(x = 20, y++);
		skill *sk = new scorchingSun;
		console({ "章鱼因为灼烧效果，损失",to_string(sk->hurt),"血量" });
	}
	else if (is_anm == 10) {
		col->setXY(x = 20, y++);
		skill *sk = new scorchingSun;
		console({ "乌贼因为灼烧效果，损失",to_string(sk->hurt),"血量" });
		col->setXY(x = 20, y++);
		console({ "乌贼因为麻痹效果，无法攻击" });
	}
	else if (is_anm == 11) {
		col->setXY(x = 20, y++);
		skill *sk = new scorchingSun;
		console({ "章鱼因为灼烧效果，损失",to_string(sk->hurt),"血量" });
		col->setXY(x = 20, y++);
		console({ "章鱼因为灼烧效果，无法攻击" });
	}
	console("————————————————————————————————————————");
}

//设置怪兽
void hud::setmon(monster *mon,int i)
{
	if (i==1)
	{
		this->mon1 = mon;
	}
	else if(i ==2) {
		this->mon2 = mon;
	}
	
}

//选择pkNum;
void hud::selectPkNum()
{
	MonsterNum = -1;
	is_start = true;
	if (makemon == 0) {
		monster *mon1 = new scaleph;
		monster *mon2 = new scaleph;
		setmon(mon1, 1);
		setmon(mon2, 2);
		makemon++;
	}
	int ch = 0;
	drawpk();
	while (1)
	{
		if (_kbhit()) {
			ch = _getch();
			//cout <<"ch="<< ch << endl;
			switch (ch)
			{
			case 13:enterPk(); break;
			case 77: pkNum >= 3 ? pkNum = 3 : pkNum++; drawpk(); break;//右→
			case 75: pkNum <= 0 ? pkNum = 0 : pkNum--; drawpk(); break;//左←
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//回车pk
void hud::enterPk()
{
	if (pkNum == 0) {
		selectMonster();
	}
	else if (pkNum == 1) {
		selectpkSkill();
	}
	else if (pkNum == 2) {
		selectstage();
	}
	else if (pkNum == 3) {
		is_start = false;
		makemon = 0;
		selectstart();
	}
}

//画pk界面技能
void hud::drawPkSkill()
{
	skill *sk;
	drawHero(heroNum);
	switch (pkskilNum)
	{
		default:break;
		case 0: sk = new snowstorm; sk->setcolor(col); sk->lookSkill(); break;
		case 1: sk = new scorchingSun; sk->setcolor(col); sk->lookSkill(); break;
		case 2: sk = new suddenAdvance; sk->setcolor(col); sk->lookSkill(); break;
	}
	col->setXY(x, y++);
	console("————————————————");
	sk = new snowstorm;
	col->setXY(x += 4, y++);
	if (pkskilNum == 0)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	sk->sethero(her);
	int num = sk->getIsStudent(sk->id);
	console({ pkskilNum == 0 ? "→" : "" ,sk->name,"消耗",to_string(sk->mp*2),"蓝量",num > 0?"":"未学习"});
	col->setColor();
	if (pkskilNum == 1)
	{
		col->setColor(5);
	}
	sk = new scorchingSun;
	col->setXY(x, y++);
	sk->sethero(her);
	num = sk->getIsStudent(sk->id);
	console({ pkskilNum == 1 ? "→" : "" ,sk->name,"消耗",to_string(sk->mp * 2),"蓝量",num > 0 ? "" : "未学习" });
	col->setColor();
	sk = new suddenAdvance;
	if (pkskilNum == 2)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	sk->sethero(her);
	num = sk->getIsStudent(sk->id);
	console({ pkskilNum == 2 ? "→" : "",sk->name,"消耗",to_string(sk->level),"蓝量",num > 0 ? "" : "未学习" });
	col->setColor();
	col->setXY(x, y++);
	if (pkskilNum == 3)
	{
		col->setColor(5);
	}
	console({ pkskilNum == 3 ? "→" : "","返回" });
	col->setColor();
	col->setXY(x = 25, y++);
	console("————————————————");
}

//选择pk技能
void hud::selectpkSkill()
{
	int ch = 0;
	drawPkSkill();
	while (1)
	{
		if (_kbhit()) {
			ch = _getch();
			//cout <<"ch="<< ch << endl;
			switch (ch)
			{
			case 13:enterSelectPkskill(); break;
			case 72:pkskilNum <= 0 ? pkskilNum = 0 : pkskilNum--; drawPkSkill(); break; //上↑
			case 80: pkskilNum >= 3 ? pkskilNum = 3 : pkskilNum++; drawPkSkill(); break;//↓
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//回车选择pk技能
void hud::enterSelectPkskill()
{
	if (pkskilNum == 0) {
		mon1->num--;
		mon2->num--;
		skill *sk = new snowstorm;
		sk->setcolor(col);
		sk->sethero(her);
		sk->sethud(this);
		sk->setmon(mon1);
		sk->useingSkill();
		sk->setmon(mon2);
		sk->useingSkill();
		MonsterNum = -1;
		Sleep(1000);
		enterselectpk();
	}
	else if (pkskilNum == 1) {
		mon1->num--;
		mon2->num--;
		skill *sk = new scorchingSun;
		sk->setcolor(col);
		sk->sethero(her);
		sk->sethud(this);
		sk->setmon(mon1);
		sk->useingSkill();
		sk->setmon(mon2);
		sk->useingSkill();
		MonsterNum = -1;
		Sleep(1000);
		enterselectpk();
	}
	else if (pkskilNum == 2) {
		mon1->num--;
		mon2->num--;
		skill *sk = new suddenAdvance;
		sk->setcolor(col);
		sk->sethero(her);
		sk->sethud(this);
		selectMonster();

		/*sk->setmon(mon1);
		sk->useingSkill();
		Sleep(1000);
		enterselectpk();*/
	}
	else if (pkskilNum == 3) {
		selectPkNum();
	}
}

//画立方体
void hud::drawcube(int x, int y,bool b)
{
	if (b){
					col->setXY(x, y);
					col->setColor(7);
					cout << "■ ■ ■ ■ ■" << endl;

					Sleep(200);
					col->setXY(x, y);
					col->setColor(7);
					cout << "■ ";
					col->setColor(6);
					cout << "■";
					col->setColor(7);
					cout<<"■ ■ ■" << endl;

					Sleep(200);
					col->setXY(x, y);
					col->setColor(7);
					cout << "■ ■";
					col->setColor(6);
					cout << "■";
					col->setColor(7);
					cout << "■ ■" << endl;

					Sleep(200);
					col->setXY(x, y);
					col->setColor(7);
					cout << "■ ■ ■";
					col->setColor(6);
					cout << "■";
					col->setColor(7);
					cout << "■" << endl;


					Sleep(200);
					col->setXY(x, y);
					col->setColor(7);
					cout << "■ ■ ■ ■";
					col->setColor(6);
					cout << "■"<<endl;
					col->setColor(7);
					Sleep(200);
					col->setXY(x, y);
					cout << "■ ■ ■ ■ ■" << endl;
					col->setColor();
			}
	else {
		col->setXY(x, y);
		col->setColor(7);
		cout << "■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■" << endl;
		col->setXY(x+36, y+1);
		cout << "■" << endl;

		Sleep(100);
		col->setXY(x, y);
		col->setColor(6);
		cout << "■ ";
		col->setColor(7);
		cout << "■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■" << endl;
		col->setXY(x + 36, y + 1);
		cout << "■" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "■ ";
		col->setColor(6);
		cout << "■";
		col->setColor(7);
		cout << "■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■" << endl;
		col->setXY(x + 36, y + 1);
		cout << "■" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "■ ■";
		col->setColor(6);
		cout << " ■ ";
		col->setColor(7);
		cout << "■ ■ ■ ■ ■ ■ ■ ■ ■ ■" << endl;
		col->setXY(x + 36, y + 1);
		cout << "■" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "■ ■ ■";
		col->setColor(6);
		cout << " ■ ";
		col->setColor(7);
		cout << "■ ■ ■ ■ ■ ■ ■ ■ ■" << endl;
		col->setXY(x + 36, y + 1);
		cout << "■" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "■ ■ ■ ■";
		col->setColor(6);
		cout << " ■ ";
		col->setColor(7);
		cout << "■ ■ ■ ■ ■ ■ ■ ■" << endl;
		col->setXY(x + 36, y + 1);
		cout << "■" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "■ ■ ■ ■ ■";
		col->setColor(6);
		cout << " ■ ";
		col->setColor(7);
		cout << "■ ■ ■ ■ ■ ■ ■" << endl;
		col->setXY(x + 36, y + 1);
		cout << "■" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "■ ■ ■ ■ ■ ■";
		col->setColor(6);
		cout << " ■ ";
		col->setColor(7);
		cout << "■ ■ ■ ■ ■ ■" << endl;
		col->setXY(x + 36, y + 1);
		cout << "■" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "■ ■ ■ ■ ■ ■ ■";
		col->setColor(6);
		cout << " ■ ";
		col->setColor(7);
		cout << "■ ■ ■ ■ ■" << endl;
		col->setXY(x + 36, y + 1);
		cout << "■" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "■ ■ ■ ■ ■ ■ ■ ■";
		col->setColor(6);
		cout << " ■ ";
		col->setColor(7);
		cout << "■ ■ ■ ■" << endl;
		col->setXY(x + 36, y + 1);
		cout << "■" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "■ ■ ■ ■ ■ ■ ■ ■ ■";
		col->setColor(6);
		cout << " ■";
		col->setColor(7);
		cout << " ■ ■ ■" << endl;
		col->setXY(x + 36, y + 1);
		cout << "■" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "■ ■ ■ ■ ■ ■ ■ ■ ■ ■";
		col->setColor(6);
		cout << " ■ ";
		col->setColor(7);
		cout << "■ ■" << endl;
		col->setXY(x + 36, y + 1);
		cout << "■" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■";
		col->setColor(6);
		cout << " ■ ";
		col->setColor(7);
		cout << "■" << endl;
		col->setXY(x + 36, y + 1);
		cout << "■" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■";
		col->setColor(6);
		cout << " ■ ";
		col->setColor(7);
		col->setXY(x + 36, y + 1);
		cout << "■" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■";
		col->setColor(6);
		
		col->setXY(x + 36, y + 1);
		cout << "■" << endl;

		Sleep(100);
		col->setColor(7);
		col->setXY(x, y);
		cout << "■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■";
		

		col->setXY(x + 36, y + 1);
		cout << "■" << endl;
		col->setColor();

	}
			
		

	
}

//普通攻击回车
void hud::enterselectpk()
{
	is_anm = 1;
	if (MonsterNum == 0)
	{   
			MonsterNum = -1;
			drawpk();
		   drawcube(33,14);
	   
		   drawMonster(45, 10, 1,1);
		   Sleep(300);
	  
		   drawMonster(45, 10, 1);
		   Sleep(300);
	
		   drawMonster(45, 10, 1, 1);
		   Sleep(300);
	 
		   drawMonster(45, 10, 1);
		   int hurt;
		   hurt = her->hurt - mon1->defense;
		   mon1->hp -= hurt;
		   drawpk();
	
		
	}
	 if (MonsterNum == 1) {
		 
			MonsterNum = -1;
			drawpk();
			drawcube(33, 9,false);
			drawMonster(60, 10, 2,1);
			Sleep(300);
		
			drawMonster(60, 10, 2);
			Sleep(300);
	
			drawMonster(60, 10, 2, 1);
			Sleep(300);
		
			drawMonster(60, 10, 2);
			/*her->setMonster(mon2);
			her->attack();*/
			int hurt;
			hurt = her->hurt - mon2->defense;
			mon2->hp -= hurt;
			drawpk();
		
	}
	
	if (mon1->num<=0)
	{
	
		if (her->hp > 0 && mon1->hp > 0) {
		Sleep(2000);
		is_anm = 2;
		drawpk();
		Sleep(300);
		drawpk(1);
		Sleep(300);
		drawpk();
		Sleep(300);
		drawpk(1);
		Sleep(300);
		mon1->setPlayer(her);
		mon1->attack();
		drawpk();
	}
	}

	if (mon2->num <= 0)
	{
		if (her->hp > 0 && mon2->hp > 0) {
		Sleep(2000);
		is_anm = 3;
		drawpk();
		Sleep(300);
		drawpk(1);
		Sleep(300);
		drawpk();
		Sleep(300);
		drawpk(1);
		Sleep(300);
		mon2->setPlayer(her);
		mon2->attack();
		
	}
	}

	

	if (mon1->num > 0 && mon2->num > 0) {
		if (mon1->state == 1 && mon2->state == 1)
		{
			is_anm = 6;
			drawpk();
			mon1->num--;
			mon2->num--;
			if (mon1->num == 0)
			{
				mon1->state = 0;
			}
			if (mon2->num == 0)
			{
				mon2->state = 0;
			}
			Sleep(2000);
			is_anm = 0;
			selectPkNum();
		}
		else if (mon1->state == 2 && mon2->state == 2) {
			is_anm = 1;
			drawpk();
			Sleep(1000);
			is_anm = 7;
			drawpk();
			bool mon1bo = mon1->isstart();
			Sleep(1000);
			
			if (mon1bo) {
				is_anm = 10;
				skill* sk = new scorchingSun;
				mon1->hp -= sk->hurt;
				drawpk();
				Sleep(1000);
			}
			else {
				is_anm = 8;
				skill* sk = new scorchingSun;
				mon1->hp -= sk->hurt;
				drawpk();
				Sleep(1000);
				if (her->hp > 0 && mon1->hp > 0) {
					is_anm = 2;
					drawpk();
					Sleep(300);
					drawpk(1);
					Sleep(300);
					drawpk();
					Sleep(300);
					drawpk(1);
					Sleep(300);
					mon1->setPlayer(her);
					mon1->attack();
					drawpk();
				}
			}
			Sleep(1000);
			bool mon2bo = mon2->isstart();
			if (mon2bo) {
				is_anm = 11;
				skill* sk = new scorchingSun;
				mon2->hp -= sk->hurt;
				drawpk();
				Sleep(2000);
			}
			else {
				is_anm = 9;
				skill* sk = new scorchingSun;
				drawpk();
				Sleep(2000);
				mon2->hp -= sk->hurt;
				if (her->hp > 0 && mon2->hp > 0) {
					Sleep(2000);
					is_anm = 3;
					drawpk();
					Sleep(300);
					drawpk(1);
					Sleep(300);
					drawpk();
					Sleep(300);
					drawpk(1);
					Sleep(300);
					mon2->setPlayer(her);
					mon2->attack();
					
				}
			};
			mon1->num--;
			mon2->num--;
			if (mon1->num == 0)
			{
				mon1->state = 0;
			}
			if (mon2->num == 0)
			{
				mon2->state = 0;
			}

			is_anm = 0;
			selectPkNum();
			
		}

	}

	if (her->hp > 0 && mon1->hp <= 0 && mon2->hp <=0) {
		is_anm = 4;
		her->nowlevel += mon1->level;
		her->nowlevel += mon2->level;
		her->money += mon1->money;
		her->money += mon2->money;
		drawpk();
		if (her->nowlevel >= her->max_level) {
			
			her->nowlevel -= her->max_level;
			her->max_level *= her->level;
			her->level++;
			is_anm = 5;
			Sleep(3000);
			drawpk();
		}
		this->saveHero();
		is_anm = 0;
		makemon = 0;
		is_start = false;
		Sleep(3000);
		selectstart();
	}


	if (mon1->hp > 0 || mon2->hp > 0)
	{
		is_anm = 0;
		selectPkNum();
	}
}





