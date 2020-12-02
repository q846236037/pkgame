#include "scorchingSun.h"
#include "hero.h"



scorchingSun::scorchingSun()
{
	name = "火焰喷射"; //名字
	hurt = 20; //伤害
	mp = 50; // mp
	paralysis = true;//麻痹
	hot = true;//灼烧
	aoe = true;//是否范围伤害
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

void scorchingSun::lookSkill()
{
	
	col->setXY(20, 8);
	cout << "————————————————————————" << endl;
	col->setXY(20, 9);
	cout << "| 对敌方全体施加灼烧效果三回合，有概率麻痹敌方" << " |" << endl;
	col->setXY(20, 10);
	cout << "————————————————————————" << endl;
}
