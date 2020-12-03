#include "suddenAdvance.h"
#include "hero.h"
#include "hud.h"



suddenAdvance::suddenAdvance()
{
	name = "��ͻ�ͽ�"; //����
	hurt = 50; //�˺�
	mp = 50; // mp
	id = 2;
	hid = 2;
	level = 10;
}


suddenAdvance::~suddenAdvance()
{
}

void suddenAdvance::useingSkill()
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

void suddenAdvance::studentSkill()
{
	if (her->level >= level)
	{
		int num = getIsStudent(id);
		if (num > 0)
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

void suddenAdvance::lookSkill()
{
	col->setXY(22, 8);
	cout << "������������������������������������������" << endl;
	col->setXY(22, 9);
	cout << "|      ��ǰ������Ե���Ŀ����ɸ߶��˺�" << "  |" << endl;
	col->setXY(22, 10);
	cout << "������������������������������������������" << endl;
}
