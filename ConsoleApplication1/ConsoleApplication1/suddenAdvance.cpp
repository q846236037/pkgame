#include "suddenAdvance.h"
#include "hero.h"




suddenAdvance::suddenAdvance()
{
	name = "猪突猛进"; //名字
	hurt = 50; //伤害
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
			cout << "——————————————" << endl;
			col->setXY(28, 12);
			cout << "|已经学会, 不需要在重新学习" << "|" << endl;
			col->setXY(28, 13);
			cout << "——————————————" << endl;
		}
		else {
			ofstream ofs;
			ofs.open("skill.txt", ios::app);
			ofs << her->id << " " << id << endl;;
			col->setXY(28, 11);
			cout << "——————————————" << endl;
			col->setXY(28, 12);
			cout << "|       学习成功" << "            |" << endl;
			col->setXY(28, 13);
			cout << "——————————————" << endl;
		}
	}
	else {
		col->setXY(28, 11);
		cout << "——————————————" << endl;
		col->setXY(28, 12);
		cout << "|  学习失败,原因：等级不足" << "  |" << endl;
		col->setXY(28, 13);
		cout << "——————————————" << endl;
	}
}

void suddenAdvance::lookSkill()
{
	col->setXY(22, 8);
	cout << "—————————————————————" << endl;
	col->setXY(22, 9);
	cout << "|      向前冲击，对单体目标造成高额伤害" << "  |" << endl;
	col->setXY(22, 10);
	cout << "—————————————————————" << endl;
}
