#include "scorchingSun.h"
#include "hero.h"



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
	level = 1;
	col = NULL;
	hu = NULL;
}


scorchingSun::~scorchingSun()
{
}

void scorchingSun::useingSkill()
{
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
