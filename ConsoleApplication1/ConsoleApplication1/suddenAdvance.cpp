#include "suddenAdvance.h"
#include "hero.h"




suddenAdvance::suddenAdvance()
{
	name = "��ͻ�ͽ�"; //����
	hurt = 50; //�˺�
	mp = 50; // mp
	id = 2;
	hid = 2;
	level = 1;
}


suddenAdvance::~suddenAdvance()
{
}

void suddenAdvance::useingSkill()
{

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
