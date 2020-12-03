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

//Ѫ��
void hud::drawBlood(int x, int y, int num,string name)
{
	cout << endl;
	col->setXY(x, y);
	if (name == " ") {
		cout << "Ѫ��:" << " ";
	}
	else {
		cout <<name<<" Ѫ��:" << " ";
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
//����
void hud::drawmp(int x, int y, int num)
{
	cout << endl;
	col->setXY(x, y);
	cout << "����:" << " ";
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
//������
void hud::drawlevel(int x, int y, int num)
{
	cout << endl;
	col->setXY(x, y);
	cout << "����:" << " ";
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
	console({ (MenuNum == 2 ? "��" : ""),"��ɫѡ��" });
	col->setColor();
	if (MenuNum == 3)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	console({ (MenuNum == 3 ? "��" : ""),"�˳���Ϸ" });
	col->setColor();
	col->setXY(x = 25, y++);
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
			case 13:enterMeun();break;
			case 72:MenuNum <= 0 ? MenuNum = 0 : MenuNum--; drawMeun(); break; //�ϡ�
			case 77: break;//�ҡ�
			case 75: break;//���
			case 80: MenuNum >= 3? MenuNum = 3 : MenuNum++; drawMeun(); break;//��
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//�˵��س�
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

//������
void hud::drawMonster(int x, int y,int num, int state)
{
	
	if (num ==1) {
		
		col->setXY(x, y++);
		col->setColor(5);
		console({ MonsterNum == 0 ? "      ��" : ""}); col->setXY(x, y++);
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
		console({ "  ��      ��  "  }); col->setXY(x, y++);
		console({ "    ������  "  }); col->setXY(x, y++);
		console({ "  ��  ��  ��  "  }); col->setXY(x, y++);
		console({ "  ����������  " }); col->setXY(x, y++);
		console({ "��  ��  ��  ��"}); col->setXY(x, y++);
		console({ "��  ��  ��  ��" }); col->setXY(x, y);
		col->setColor();
	}
	else if(num ==2){
		col->setXY(x, y++);
		col->setColor(5);
		console({ MonsterNum == 1 ? "        ��" : "" }); col->setXY(x, y++);
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
	
		console({ "      ������" }); col->setXY(x, y++);
		console({"    ����������" }); col->setXY(x, y++);
		console({"  ����  ��  ����" }); col->setXY(x, y++);
		console({"��  ����������  ��" }); col->setXY(x, y++);
		console({"    ��  ��  ��" }); col->setXY(x, y++);
		console({"  ����      ����" }); col->setXY(x, y);
		col->setColor();
	}
	
}

//ѡ�����
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
			case 72: break; //�ϡ�
			case 77: MonsterNum >= 1 ? MonsterNum = 1 : MonsterNum++; drawpk(); break;//�ҡ�
			case 75: MonsterNum <= 0 ? MonsterNum = 0 : MonsterNum--; drawpk(); break;//���
			case 80: break;//��
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
	col->setXY(x = 25, y++);
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
		col->setColor();
	
}

//��ѡ��Ӣ��
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
	col->setXY(x = 25, y++);
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
	this->her = NULL;
	ifstream  ifs;
	int title = gerHeroNumber();
	if (title>0) {
		ifs.open("hero.txt", ios::in);
		
		t_her = new hero *[title];
		string name; //����
		int mp; // ����ֵ����
		int hp;//Ѫ������
		int  level;//����
		int max_level;//�������辭��
		int money;//��Ǯ
		int hurt;//�˺�
		int defense; //����
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
	string name;//����
	col->setXY(x, y++);
	cout << "����������:";
	cin >> name;
	int mp;// ����ֵ����
	int hp;//Ѫ������
	int  level;//����
	int max_level;//�������辭��
	int money;//��Ǯ
	int hurt;//�˺�
	int defense;//����
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

//����ʼ����
void hud::drawstart()
{
	drawHero(heroNum);
	col->setXY(x, y++);
	console("��������������������������������");
	if (startNum == 0)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	col->setXY(x, y);
	cout << (startNum == 0 ? "��" : "") << "ս��" << "    ";
	col->setColor();
	if (startNum == 1)
	{
		col->setColor(5);
	}
	col->setXY(x += 9, y);
	cout << (startNum == 1 ? "��" : "") << "����" << "    ";
	col->setColor();
	if (startNum == 2)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	col->setXY(x += 9, y);
	cout << (startNum == 2 ? "��" : "") << "����" << "    ";
	col->setColor();
	if (startNum == 3)
	{
		col->setColor(5);
	}
	col->setXY(x += 9, y++);
	cout << (startNum == 3 ? "��" : "") << "�̳�" << "    ";
	col->setColor();
	if (startNum == 4)
	{
		col->setColor(5);
	}
	col->setXY(x =25, y+=2);
	cout << (startNum == 4 ? "��" : "") << "��Ϣ" << "    ";
	col->setColor();
	if (startNum == 5)
	{
		col->setColor(5);
	}
	col->setXY(x +=9, y++);
	cout << (startNum == 5 ? "��" : "") << "����" << "    ";
	col->setColor();
	col->setXY(x =25, y++);
	console("��������������������������������");
}

//��ʼ����ѡ��
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
			case 72:(startNum - 4)< 0 ? startNum  : startNum -= 4; drawstart(); break; //�ϡ�
			case 77: startNum >= 5 ? startNum = 5 : startNum++; drawstart(); break;//�ҡ�
			case 75: startNum <= 0 ? startNum = 0 : startNum--; drawstart(); break;//���
			case 80: (startNum + 4)> 5 ? startNum  : startNum += 4; drawstart(); break;//��
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//��ʼ����س��¼�
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

//��Ϣչʾ����
void hud::showHeroInfo()
{
	drawHero(heroNum);
	col->setXY(x, y++);
	console("��������������������������������");
	col->setXY(x+=10, y++);
	console({ "������",her->name });
	col->setXY(x, y++);
	console({ "Ѫ����",to_string(her->hp) });
	col->setXY(x, y++);
	console({ "����ֵ��",to_string(her->mp) });
	col->setXY(x, y++);
	console({ "��������",to_string(her->hurt) });
	col->setXY(x, y++);
	console({ "������",to_string(her->defense) });
	col->setXY(x, y++);
	console({ "�ȼ���",to_string(her->level) });
	col->setXY(x, y++);
	console({ "��Ǯ��",to_string(her->money) });
	col->setXY(x, y++);
	console({ "���飺",to_string(her->nowlevel) });
	col->setXY(x = 25, y++);
	console("��������������������������������");
	Sleep(3000);
	selectstart();
}

//�̵����
void hud::showshop()
{
	drawHero(heroNum);
	col->setXY(x =25, y++);
	console("��������������������������������");
	if (shopNum == 0)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	col->setXY(x, y++);

	bluemedicine b;
	console({shopNum==0?"��":"",b.name,"���ظ�100����  ��Ǯ:",to_string(b.money)});
	col->setColor();
	if (shopNum == 1)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	redmedicine r;
	console({ shopNum == 1 ? "��" : "",r.name,"���ظ�100Ѫ��  ��Ǯ:",to_string(r.money) });
	col->setColor();
	col->setXY(x, y++);
	if (shopNum == 2)
	{
		col->setColor(5);
	}
	quickmedicine q;
	console({ shopNum == 2 ? "��" : "",q.name,"���������(1~3)�� ��Ǯ:",to_string(q.money) });
	col->setColor();
	col->setXY(x, y++);
	if (shopNum == 3)
	{
		col->setColor(5);
	}
	console({ shopNum == 3 ? "��" : "","����"});
	col->setColor();
	col->setXY(x = 25, y++);
	console("��������������������������������");
}

//�̵�ѡ��
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
			case 72:shopNum <= 0 ? shopNum = 0 : shopNum--; showshop(); break; //�ϡ�
			case 80: shopNum >= 3 ? shopNum = 3 : shopNum++; showshop(); break;//��
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//�̵�س�
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


//����Ӣ��
void hud::saveHero()
{
	int len = sizeof(t_her) / sizeof(t_her[0]);
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
		if(heroNum == t_her[i]->id){
			ofs << t_her[i]->name << " " << t_her[i]->mp << " " << t_her[i]->hp << " " << t_her[i]->level << " " << t_her[i]->max_level << " " << t_her[i]->money << " " << t_her[i]->hurt << " " << t_her[i]->defense << " " << t_her[i]->id << " " << t_her[i]->nowlevel << endl;
		}
	}
	ofs.close();
}

//������
void hud::drawstage()
{
	stage *sta;
	drawHero(heroNum);
	col->setXY(x, y++);
	console("��������������������������������");
	sta = new bluemedicine;
	col->setXY(x += 10, y++);
	if (stageNum == 0)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	console({stageNum ==0?"��":"" ,sta->name, to_string(getstageNum(0))});
	col->setColor();
	if (stageNum == 1)
	{
		col->setColor(5);
	}
	sta = new redmedicine;
	col->setXY(x, y++);
	console({ stageNum == 1 ? "��" : "" ,sta->name, to_string(getstageNum(1)) });
	col->setColor();
	sta = new quickmedicine;
	if (stageNum == 2)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	console({ stageNum == 2 ? "��" : "",sta->name, to_string(getstageNum(2)) });
	col->setColor();
	col->setXY(x, y++);
	if (stageNum == 3)
	{
		col->setColor(5);
	}
	console({ stageNum == 3 ? "��" : "","����"});
	col->setColor();
	col->setXY(x = 25, y++);
	console("��������������������������������");
}

//��ȡ��������
int hud::getstageNum(int i)
{
	// 0 ��ҩ 1 ��ҩ 2��ҩ
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

//����ѡ��
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
			case 72:stageNum <= 0 ? stageNum = 0 : stageNum--; drawstage(); break; //�ϡ�
			case 80: stageNum >= 3 ? stageNum = 3 : stageNum++; drawstage(); break;//��
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//ʹ�õ���
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

//������
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
	console("��������������������������������");
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
	console({ skillNum == 0 ? "��" : "" ,sk->name,"�ȼ�",to_string(sk->level),"��ѧϰ",num>0?"��ѧ��":"δѧ��"});
	col->setColor();
	if (skillNum == 1)
	{
		col->setColor(5);
	}
	sk = new scorchingSun;
	col->setXY(x, y++);
	sk->sethero(her);
	num = sk->getIsStudent(sk->id);
	console({ skillNum == 1 ? "��" : "" ,sk->name,"�ȼ�",to_string(sk->level),"��ѧϰ",num>0 ? "��ѧ��" : "δѧ��" });
	col->setColor();
	sk = new suddenAdvance;
	if (skillNum == 2)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	sk->sethero(her);
	num = sk->getIsStudent(sk->id);
	console({ skillNum == 2 ? "��" : "",sk->name,"�ȼ�",to_string(sk->level),"��ѧϰ",num>0 ? "��ѧ��" : "δѧ��" });
	col->setColor();
	col->setXY(x, y++);
	if (skillNum == 3)
	{
		col->setColor(5);
	}
	console({ skillNum == 3 ? "��" : "","����" });
	col->setColor();
	col->setXY(x = 25, y++);
	console("��������������������������������");
}

//ѡ����
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
			case 72:skillNum <= 0 ? skillNum = 0 : skillNum--; drawskill(); break; //�ϡ�
			case 80: skillNum >= 3 ? skillNum = 3 : skillNum++; drawskill(); break;//��
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//���ܻس�
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

//��pk��Ϸ
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
		drawBlood(45, 1, mon1->hp / 10, "����");
	}
	if (mon2->hp>0)
	{
		drawMonster(60, 10, 2);
		drawBlood(45, 3, mon2->hp / 10, "����");
	}
	
	drawBlood(2, 1,her->hp/10);
	drawmp(2, 3,her->mp/10);
	drawlevel(2, 5,(int)(her->nowlevel/10));
	col->setXY(x=0, y++);
	console("��������������������������������������������������������������������������������");
	if(is_anm == 0){
		if (pkNum == 0)
		{
			col->setColor(5);
		}
		else {
			col->setColor();
		}
		col->setXY(x+=9, y);
		cout << (pkNum == 0 ? "��" : "") << "ս��" << "    ";
		col->setColor();
		if (pkNum == 1)
		{
			col->setColor(5);
		}
		col->setXY(x += 18, y);
		cout << (pkNum == 1 ? "��" : "") << "����" << "    ";
		col->setColor();
		if (pkNum == 2)
		{
			col->setColor(5);
		}
		else {
			col->setColor();
		}
		col->setXY(x += 18, y);
		cout << (pkNum == 2 ? "��" : "") << "����" << "    ";
		col->setColor();
		if (pkNum == 3)
		{
			col->setColor(5);
		}
		col->setXY(x += 18, y++);
		cout << (pkNum == 3 ? "��" : "") << "����" << "    ";
		col->setColor();
		col->setXY(x = 0, y++);
	}
	else if (is_anm == 1) {
		col->setXY(x = 30, y++);
		console({ "�ҷ������˹��������",to_string(her->hurt-mon1->defense),"�˺�" });
	}
	else if (is_anm == 2) {
		col->setXY(x = 30, y++);
		console({ "���������˹��������",to_string(mon2->hurt - her->defense),"�˺�" });
	}
	else if (is_anm == 3) {
		col->setXY(x = 30, y++);
		console({ "���㷢���˹��������",to_string(mon2->hurt-her->defense),"�˺�" });
	}
	else if (is_anm == 4) {
		col->setXY(x = 20, y++);
		console({ "ս��ʤ�����",to_string(mon1->level+mon2->level),"����"});
		col->setXY(x = 20, y++);
		console({ "���",to_string(mon1->money + mon2->money),"��Ǯ" });
	}
	else if (is_anm == 5) {
		col->setXY(x = 20, y++);
		console({ "��ϲ������ǰ�ȼ�",to_string(her->level),"��ȥѧϰ�¼��ܰ�" });
	}
	else if (is_anm == 6) {
		col->setXY(x = 20, y++);
		console({ "�����Ƕ��������޷�����"});
	}
	else if (is_anm == 7) {
		col->setXY(x = 20, y++);
		console({ "�����Ƕ������գ�������Ѫ���غϣ���������Բ��ܹ���" });
	}
	else if (is_anm == 8) {
		col->setXY(x = 20, y++);
		skill *sk = new scorchingSun;
		console({ "������Ϊ����Ч������ʧ",to_string(sk->hurt),"Ѫ��" });
		
	}
	else if (is_anm == 9) {
		col->setXY(x = 20, y++);
		skill *sk = new scorchingSun;
		console({ "������Ϊ����Ч������ʧ",to_string(sk->hurt),"Ѫ��" });
	}
	else if (is_anm == 10) {
		col->setXY(x = 20, y++);
		skill *sk = new scorchingSun;
		console({ "������Ϊ����Ч������ʧ",to_string(sk->hurt),"Ѫ��" });
		col->setXY(x = 20, y++);
		console({ "������Ϊ���Ч�����޷�����" });
	}
	else if (is_anm == 11) {
		col->setXY(x = 20, y++);
		skill *sk = new scorchingSun;
		console({ "������Ϊ����Ч������ʧ",to_string(sk->hurt),"Ѫ��" });
		col->setXY(x = 20, y++);
		console({ "������Ϊ����Ч�����޷�����" });
	}
	console("��������������������������������������������������������������������������������");
}

//���ù���
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

//ѡ��pkNum;
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
			case 77: pkNum >= 3 ? pkNum = 3 : pkNum++; drawpk(); break;//�ҡ�
			case 75: pkNum <= 0 ? pkNum = 0 : pkNum--; drawpk(); break;//���
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//�س�pk
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

//��pk���漼��
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
	console("��������������������������������");
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
	console({ pkskilNum == 0 ? "��" : "" ,sk->name,"����",to_string(sk->mp*2),"����",num > 0?"":"δѧϰ"});
	col->setColor();
	if (pkskilNum == 1)
	{
		col->setColor(5);
	}
	sk = new scorchingSun;
	col->setXY(x, y++);
	sk->sethero(her);
	num = sk->getIsStudent(sk->id);
	console({ pkskilNum == 1 ? "��" : "" ,sk->name,"����",to_string(sk->mp * 2),"����",num > 0 ? "" : "δѧϰ" });
	col->setColor();
	sk = new suddenAdvance;
	if (pkskilNum == 2)
	{
		col->setColor(5);
	}
	col->setXY(x, y++);
	sk->sethero(her);
	num = sk->getIsStudent(sk->id);
	console({ pkskilNum == 2 ? "��" : "",sk->name,"����",to_string(sk->level),"����",num > 0 ? "" : "δѧϰ" });
	col->setColor();
	col->setXY(x, y++);
	if (pkskilNum == 3)
	{
		col->setColor(5);
	}
	console({ pkskilNum == 3 ? "��" : "","����" });
	col->setColor();
	col->setXY(x = 25, y++);
	console("��������������������������������");
}

//ѡ��pk����
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
			case 72:pkskilNum <= 0 ? pkskilNum = 0 : pkskilNum--; drawPkSkill(); break; //�ϡ�
			case 80: pkskilNum >= 3 ? pkskilNum = 3 : pkskilNum++; drawPkSkill(); break;//��
			default:cout << " " << endl; break;
			}
			if (ch == 27) {
				break;
			}

		}
	}
}

//�س�ѡ��pk����
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

//��������
void hud::drawcube(int x, int y,bool b)
{
	if (b){
					col->setXY(x, y);
					col->setColor(7);
					cout << "�� �� �� �� ��" << endl;

					Sleep(200);
					col->setXY(x, y);
					col->setColor(7);
					cout << "�� ";
					col->setColor(6);
					cout << "��";
					col->setColor(7);
					cout<<"�� �� ��" << endl;

					Sleep(200);
					col->setXY(x, y);
					col->setColor(7);
					cout << "�� ��";
					col->setColor(6);
					cout << "��";
					col->setColor(7);
					cout << "�� ��" << endl;

					Sleep(200);
					col->setXY(x, y);
					col->setColor(7);
					cout << "�� �� ��";
					col->setColor(6);
					cout << "��";
					col->setColor(7);
					cout << "��" << endl;


					Sleep(200);
					col->setXY(x, y);
					col->setColor(7);
					cout << "�� �� �� ��";
					col->setColor(6);
					cout << "��"<<endl;
					col->setColor(7);
					Sleep(200);
					col->setXY(x, y);
					cout << "�� �� �� �� ��" << endl;
					col->setColor();
			}
	else {
		col->setXY(x, y);
		col->setColor(7);
		cout << "�� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
		col->setXY(x+36, y+1);
		cout << "��" << endl;

		Sleep(100);
		col->setXY(x, y);
		col->setColor(6);
		cout << "�� ";
		col->setColor(7);
		cout << "�� �� �� �� �� �� �� �� �� �� �� ��" << endl;
		col->setXY(x + 36, y + 1);
		cout << "��" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "�� ";
		col->setColor(6);
		cout << "��";
		col->setColor(7);
		cout << "�� �� �� �� �� �� �� �� �� �� ��" << endl;
		col->setXY(x + 36, y + 1);
		cout << "��" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "�� ��";
		col->setColor(6);
		cout << " �� ";
		col->setColor(7);
		cout << "�� �� �� �� �� �� �� �� �� ��" << endl;
		col->setXY(x + 36, y + 1);
		cout << "��" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "�� �� ��";
		col->setColor(6);
		cout << " �� ";
		col->setColor(7);
		cout << "�� �� �� �� �� �� �� �� ��" << endl;
		col->setXY(x + 36, y + 1);
		cout << "��" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "�� �� �� ��";
		col->setColor(6);
		cout << " �� ";
		col->setColor(7);
		cout << "�� �� �� �� �� �� �� ��" << endl;
		col->setXY(x + 36, y + 1);
		cout << "��" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "�� �� �� �� ��";
		col->setColor(6);
		cout << " �� ";
		col->setColor(7);
		cout << "�� �� �� �� �� �� ��" << endl;
		col->setXY(x + 36, y + 1);
		cout << "��" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "�� �� �� �� �� ��";
		col->setColor(6);
		cout << " �� ";
		col->setColor(7);
		cout << "�� �� �� �� �� ��" << endl;
		col->setXY(x + 36, y + 1);
		cout << "��" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "�� �� �� �� �� �� ��";
		col->setColor(6);
		cout << " �� ";
		col->setColor(7);
		cout << "�� �� �� �� ��" << endl;
		col->setXY(x + 36, y + 1);
		cout << "��" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "�� �� �� �� �� �� �� ��";
		col->setColor(6);
		cout << " �� ";
		col->setColor(7);
		cout << "�� �� �� ��" << endl;
		col->setXY(x + 36, y + 1);
		cout << "��" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "�� �� �� �� �� �� �� �� ��";
		col->setColor(6);
		cout << " ��";
		col->setColor(7);
		cout << " �� �� ��" << endl;
		col->setXY(x + 36, y + 1);
		cout << "��" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "�� �� �� �� �� �� �� �� �� ��";
		col->setColor(6);
		cout << " �� ";
		col->setColor(7);
		cout << "�� ��" << endl;
		col->setXY(x + 36, y + 1);
		cout << "��" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "�� �� �� �� �� �� �� �� �� �� ��";
		col->setColor(6);
		cout << " �� ";
		col->setColor(7);
		cout << "��" << endl;
		col->setXY(x + 36, y + 1);
		cout << "��" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "�� �� �� �� �� �� �� �� �� �� �� ��";
		col->setColor(6);
		cout << " �� ";
		col->setColor(7);
		col->setXY(x + 36, y + 1);
		cout << "��" << endl;

		Sleep(100);
		col->setXY(x, y);
		cout << "�� �� �� �� �� �� �� �� �� �� �� �� ��";
		col->setColor(6);
		
		col->setXY(x + 36, y + 1);
		cout << "��" << endl;

		Sleep(100);
		col->setColor(7);
		col->setXY(x, y);
		cout << "�� �� �� �� �� �� �� �� �� �� �� �� ��";
		

		col->setXY(x + 36, y + 1);
		cout << "��" << endl;
		col->setColor();

	}
			
		

	
}

//��ͨ�����س�
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
		is_anm = 0;
		selectPkNum();
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
}





