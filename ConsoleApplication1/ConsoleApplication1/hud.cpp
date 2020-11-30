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
	console("������������������������������");
		 if (MenuNum == 0)
		 {
			 col->setColor(5);
		 }
		 else {
			 col->setColor();
		 }
	console({ (MenuNum == 0 ? "��":""),"��ʼ��Ϸ" });
	col->setColor();
	if (MenuNum == 1)
	{
		col->setColor(5);
	}
	console({ (MenuNum == 1 ? "��" : ""),"�����Ѷ�" });
	col->setColor();
	if (MenuNum == 2)
	{
		col->setColor(5);
	}
	console({ (MenuNum == 2 ? "��" : ""),"�˳���Ϸ" });
	col->setColor();
	console("������������������������������");
}

//�˵�
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
	console("��������������������������������");
	if (LoginNum == 0)
	{
		col->setColor(5);
	}
	else {
		col->setColor();
	}
	console({LoginNum==0?"��":"","��¼" });
	col->setColor();
	if (LoginNum == 1)
	{
		col->setColor(5);
	}
	console({ LoginNum == 1 ? "��" : "","�˳�" });
	col->setColor();
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
	console("��������������������������������");
	if (this->log->loginAccount()) {
		Meun();
	}
	else {
		console("�˺Ż��������");
	}
	console("��������������������������������");
}

void hud::drawtitle()
{

}

//��Ӣ��
void hud::drawHero(int i)
{
	if (i == 1) {
		console("                  ��          ��");
		console("                ������  ��  ������");
		console("                ������������������");
		console("      ��������  ������  ��  ������");
		console("      ��    ��    ��    ��    ��");
		console("      ��������          ��");
		console("  ��������������������������");
		console("����������������        ��");
		console("����������������        ��");
		console("    ����    ����");
		console("    ����    ����");
		console("    ����    ����");
	}
	else if (i == 2) {
		console("    ��");
		console("  ��  ��       ����������");
		console(" ��    ��    ��������������");
		console("��      ��  ������        ��");
		console("  ������  ������  ��    �� ��");
		console("    ��    ������          ����");
		console("    ��      ����������������");
		console("    ��        ��          ��    ");
		console("    ��       ��            �� ");
		console("    ��      ��              ��  ");
		console("    ��     ��������������������");
	}
	else if (i == 3) {
		console("                  �� �� ��");
		console("    ��         ��      ��  ��   ");
		console("    ��         ��      ��   �� ");
		console("    ��       ��  ��������������");
		console("����������  ��   ��  ��     �� ��");
		console("    ��      ��    ��������������");
		console("    ��      ��         ��     ��");
		console("    ��      �������������������� ");
		console("    ��      ��         ��     �� ");
		console("    ��      ��         ��     ��");
		console("    ��     ��������������������");	  
	}
}


