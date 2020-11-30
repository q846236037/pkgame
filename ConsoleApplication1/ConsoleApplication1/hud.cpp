#include "hud.h"
//��ӡ����
void console(string params) {
	cout << params << endl;
}
//��ӡ���������
void console(initializer_list<string> il) {
	for (auto par = il.begin(); par != il.end(); par++)
	{
		cout << *par << " ";
	}
	cout << endl;
}
//��ӡ����
void console(int params) {
	cout << params << endl;
}
//int���Ͷ������ӡ����
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

//Ѫ��
void hud::drawBlood(int num)
{
	cout << endl;
	cout << "Ѫ��:" << " ";
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
//����
void hud::drawmp(int num)
{
	cout << endl;
	cout << "����:" << " ";
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
//������
void hud::drawlevel(int num)
{
	cout << endl;
	cout << "����:" << " ";
	
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

//����color��
void hud::setcolor(color * col)
{
	this->col = col;
}

//���˵�
void hud::drawMeun()
{
	system("cls");
	drawHero(heroNum);
	col->setXY(x, y++);
	console("������������������������������");
		 if (MenuNum == 0)
		 {
			 col->setColor(5);
		 }
		 else {
			 col->setColor();
		 }
		 col->setXY(x+=10, y++);
	console({ (MenuNum == 0 ? "��":""),"��ʼ��Ϸ" });
	col->setColor();
	if (MenuNum == 1)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	console({ (MenuNum == 1 ? "��" : ""),"�����Ѷ�" });
	col->setColor();
	if (MenuNum == 2)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	console({ (MenuNum == 2 ? "��" : ""),"�˳���Ϸ" });
	col->setColor();
	col->setXY(x = 40, y++);
	console("������������������������������");
}

//�˵�
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
			case 72:MenuNum <= 0 ? MenuNum = 0 : MenuNum--; drawMeun(); break; //�ϡ�
			case 77: break;//�ҡ�
			case 75: break;//���
			case 80: MenuNum >= 2 ? MenuNum = 2 : MenuNum++; drawMeun(); break;//��
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//������
void hud::drawMonster()
{
	system("cls");
	console({ MonsterNum ==0?"      ��":"",MonsterNum == 1 ? "\t\t\t��" : "" });
	console({ "  ��      ��  " ,"","      ������" });
	console({ "    ������  " ,"","      ����������" });
	console({ "  ��  ��  ��  " ,"","  ����  ��  ����" });
	console({ "  ����������  " ,"","��  ����������  ��" });
	console({ "��  ��  ��  ��" ,"","    ��  ��  ��" });
	console({ "��  ��  ��  ��" ,"","  ����      ����" });
}

//ѡ�����
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
			case 72: break; //�ϡ�
			case 77: MonsterNum >= 1 ? MonsterNum = 1 : MonsterNum++; drawMonster(); break;//�ҡ�
			case 75: MonsterNum <= 0 ? MonsterNum = 0 : MonsterNum--; drawMonster(); break;//���
			case 80: break;//��
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//����¼
void hud::drawLogin()
{
	system("cls");
	drawHero(0);
	col->setXY(x, y++);
	console("��������������������������������");
	if (LoginNum == 0)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	col->setXY(x+=10, y++);
	console({LoginNum==0?"��":"","��¼" });
	col->setColor();
	if (LoginNum == 1)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	console({ LoginNum == 1 ? "��" : "","�˳�" });
	col->setColor();
	col->setXY(x = 40, y++);
	console("��������������������������������");
}

//ѡ���¼
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
			case 72: LoginNum <= 0 ? LoginNum = 0 : LoginNum--; drawLogin(); break; //�ϡ�
			case 77:break;//�ҡ�
			case 75:break;//���
			case 80: LoginNum >= 1? LoginNum = 1 : LoginNum++; drawLogin(); break; break;//��
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//��¼�س�
void hud::EnterLogin()
{
	switch (LoginNum)
	{
	default:break;
	case 0:LoginLoading(); break;
	case 1:exitfn(); break;
	}
}

//�˳�Game
void hud::exitfn()
{
	exit(0);
}

//���õ�¼��
void hud::setLogin(login * log)
{
	this->log = log;
}

//��¼�Ƿ�ɹ�
void hud::LoginLoading()
{
	system("cls");
	drawHero(0);
	col->setXY(x, y++);
	console("��������������������������������");
	if (this->log->loginAccount()) {
		moveSelectHero();
	}
	else {
		col->setXY(x, y++);
		console("�˺Ż��������");
		col->setXY(x,y++);
		console("3s������������");
		Sleep(3000);
		LoginLoading();
	}
	console("��������������������������������");
}

void hud::drawtitle()
{

}

//��Ӣ��
void hud::drawHero(int i,int xsize, int ysize)
{
	x = xsize;
	y = ysize;
	if (i == 0) {
		col->setXY(x, y++);
		console("                  ��          ��"); col->setXY(x, y++);
		console("                ������  ��  ������"); col->setXY(x, y++);
		console("                ������������������"); col->setXY(x, y++);
		console("      ��������  ������  ��  ������"); col->setXY(x, y++);
		console("      ��    ��    ��    ��    ��"); col->setXY(x, y++);
		console("      ��������          ��"); col->setXY(x, y++);
		console("  ��������������������������"); col->setXY(x, y++);
		console("����������������        ��"); col->setXY(x, y++);
		console("����������������        ��"); col->setXY(x, y++);
		console("    ����    ����"); col->setXY(x, y++);
		console("    ����    ����"); col->setXY(x, y++);
		console("    ����    ����");
	}
	else if (i == 1) {
		col->setXY(x, y++);
		console("    ��"); col->setXY(x, y++);
		console("  ��  ��       ����������"); col->setXY(x, y++);
		console(" ��    ��    ��������������"); col->setXY(x, y++);
		console("��      ��  ������        ��"); col->setXY(x, y++);
		console("  ������  ������  ��    �� ��"); col->setXY(x, y++);
		console("    ��    ������          ����"); col->setXY(x, y++);
		console("    ��      ����������������"); col->setXY(x, y++);
		console("    ��        ��          ��    "); col->setXY(x, y++);
		console("    ��       ��            �� "); col->setXY(x, y++);
		console("    ��      ��              ��  "); col->setXY(x, y++);
		console("    ��     ��������������������");
	}
	else if (i == 2) {
		col->setXY(x, y++);
		console("                  �� �� ��"); col->setXY(x, y++);
		console("    ��         ��      ��  ��   "); col->setXY(x, y++);
		console("    ��         ��      ��   �� "); col->setXY(x, y++);
		console("    ��       ��  ��������������"); col->setXY(x, y++);
		console("����������  ��   ��  ��     �� ��"); col->setXY(x, y++);
		console("    ��      ��    ��������������"); col->setXY(x, y++);
		console("    ��      ��         ��     ��"); col->setXY(x, y++);
		console("    ��      �������������������� "); col->setXY(x, y++);
		console("    ��      ��         ��     �� "); col->setXY(x, y++);
		console("    ��      ��         ��     ��"); col->setXY(x, y++);
		console("    ��     ��������������������");
	}
}

//ѡ��Ӣ��
void hud::drawSelectHero()
{
	system("cls");
	drawHero(heroNum);
	col->setXY(x, y++);
	console("��������������������������������");
	if (heroNum == 0)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	col->setXY(x+=5, y);
	cout << (heroNum == 0 ? "��" : "") << "սʿ"<<"    ";
	col->setColor();
	if (heroNum == 1)
	{
		col->setColor(5);
	}
	col->setXY(x += 10, y);
	cout << (heroNum == 1 ? "��" : "") << "��ʿ" << "    ";
	col->setColor();
	if (heroNum == 2)
	{
		col->setColor(5);
	}
	col->setXY(x += 10, y++);
	cout << (heroNum == 2 ? "��" : "") << "��ʿ";
	col->setColor();
	cout << endl;
	col->setXY(x = 40, y++);
	console("��������������������������������");
}

//�ƶ�Ӣ��ѡ��
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
			case 77: heroNum >= 2 ? heroNum = 2 : heroNum++; drawSelectHero(); break;//�ҡ�
			case 75: heroNum <= 0 ? heroNum = 0 : heroNum--; drawSelectHero(); break;//���
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//ѡ��Ӣ��
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
		string name;//����
		int mp;// ����ֵ����
		int hp;//Ѫ������
		int  level;//����
		int max_level;//�������辭��
		int money;//��Ǯ
		int hurt;//�˺�
		int defense;//����
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
		string name;//����
		col->setXY(x, y++);
		cout << "����������:";
		cin >> name;
		/*int mp;// ����ֵ����
		int hp;//Ѫ������
		int  level;//����
		int max_level;//�������辭��
		int money;//��Ǯ
		int hurt;//�˺�
		int defense;//����*/
		ofs << heroNum << " " <<name <<" "<<her->mp <<" "<<her->hp << " " <<her->level << " " <<her->max_level << " " <<her->money << " " <<her->hurt << " " <<her->defense;
		ofstream;
		Meun();
	}
	
}

//����Ӣ��
void hud::sethero(hero *her)
{
	this->her = her;
}

//���Ӣ������
int hud::gerHeroNumber()
{
	int num = 0;
	ifstream ifs;
	ifs.open("hero.txt", ios::in);
	if (ifs.is_open()) {
		string name; //����
		int mp; // ����ֵ����
		int hp;//Ѫ������
		int  level;//����
		int max_level;//�������辭��
		int money;//��Ǯ
		int hurt;//�˺�
		int defense; //����
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


