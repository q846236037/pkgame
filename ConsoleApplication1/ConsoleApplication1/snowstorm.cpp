#include "snowstorm.h"
#include "hero.h"




snowstorm::snowstorm()
{
   name = "����ѩ"; //����
	hurt = 20; //�˺�
	mp = 50; // mp
	cold = true;//����
	aoe = true;//�Ƿ�Χ�˺�
	id = 0;
	hid = 1;
	level = 1;
}


snowstorm::~snowstorm()
{
}

void snowstorm::useingSkill()
{
}

void snowstorm::studentSkill()
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

void snowstorm::lookSkill()
{

	col->setXY(22, 8);
	cout << "������������������������������������������" << endl;
	col->setXY(22, 9);
	cout << "| ��ȫ��ȫ��ʩ�ӱ���Ч�����غϣ��˺�����" <<" |" << endl;
	col->setXY(22, 10);
	cout << "������������������������������������������" << endl;
}
