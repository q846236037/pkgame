#include "scorchingSun.h"
#include "hero.h"
#include "hud.h"



scorchingSun::scorchingSun()
{
	name = "��������"; //����
	hurt = 20; //�˺�
	mp = 50; // mp
	paralysis = true;//���
	hot = true;//����
	aoe = true;//�Ƿ�Χ�˺�
	id = 1;
	hid = 0;
	level = 3;
	col = NULL;
	hu = NULL;
}


scorchingSun::~scorchingSun()
{
}

void scorchingSun::useingSkill()
{
	int num = getIsStudent(id);
	if (num > 0)
	{
		if (her->mp >= mp) {
			her->setMonster(mon);
			her->setSkill(this);
			her->attack();
		}
		else {
			col->setXY(28, 11);
			cout << "����������������������������" << endl;
			col->setXY(28, 12);
			cout << "|  ʹ��ʧ��,ԭ����������" << "  |" << endl;
			col->setXY(28, 13);
			cout << "����������������������������" << endl;
			Sleep(1000);
			hu->selectpkSkill();
		}
	}
	else {
		col->setXY(28, 11);
		cout << "����������������������������" << endl;
		col->setXY(28, 12);
		cout << "|  ʹ��ʧ��,ԭ��δӵ�м���" << "  |" << endl;
		col->setXY(28, 13);
		cout << "����������������������������" << endl;
		Sleep(1000);
		hu->selectpkSkill();
	}
}

void scorchingSun::studentSkill()
{
	if (her->level>=level)
	{
		int num = getIsStudent(id);
		if (num>0)
		{
			col->setXY(28, 11);
			cout << "����������������������������" << endl;
			col->setXY(28, 12);
			cout << "|�Ѿ�ѧ��, ����Ҫ������ѧϰ" << "|" << endl;
			col->setXY(28, 13);
			cout << "����������������������������" << endl;
		}
		else {
			ofstream ofs;
			ofs.open("skill.txt", ios::app);
			ofs << her->id << " " << id << endl;;
			col->setXY(28, 11);
			cout << "����������������������������" << endl;
			col->setXY(28, 12);
			cout << "|       ѧϰ�ɹ�" << "            |" << endl;
			col->setXY(28, 13);
			cout << "����������������������������" << endl;
		}
	}
	else {
		col->setXY(28, 11);
		cout << "����������������������������" << endl;
		col->setXY(28, 12);
		cout << "|  ѧϰʧ��,ԭ�򣺵ȼ�����" << "  |" << endl;
		col->setXY(28, 13);
		cout << "����������������������������" << endl;
	}
}

void scorchingSun::lookSkill()
{
	
	col->setXY(20, 8);
	cout << "������������������������������������������������" << endl;
	col->setXY(20, 9);
	cout << "| �Եз�ȫ��ʩ������Ч�����غϣ��и�����Եз�" << " |" << endl;
	col->setXY(20, 10);
	cout << "������������������������������������������������" << endl;
}
