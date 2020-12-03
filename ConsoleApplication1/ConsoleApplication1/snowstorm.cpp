#include "snowstorm.h"
#include "hero.h"
#include "hud.h"



snowstorm::snowstorm()
{
   name = "暴风雪"; //名字
	hurt = 20; //伤害
	mp = 25; // mp
	cold = true;//寒冷
	aoe = true;//是否范围伤害
	id = 0;
	hid = 1;
	level = 1;
	mon = NULL;
}


snowstorm::~snowstorm()
{
}

void snowstorm::useingSkill()
{
	int num = getIsStudent(id);
	if (num>0)
	{
		if (her->mp >= mp) {
			her->setMonster(mon);
			her->setSkill(this);
			her->attack();
		}
		else {
			col->setXY(28, 11);
			cout << "——————————————" << endl;
			col->setXY(28, 12);
			cout << "|  使用失败,原因：蓝量不足" << "  |" << endl;
			col->setXY(28, 13);
			cout << "——————————————" << endl;
			Sleep(1000);
			hu->selectpkSkill();
		}
	}
	else {
		col->setXY(28, 11);
		cout << "——————————————" << endl;
		col->setXY(28, 12);
		cout << "|  使用失败,原因：未拥有技能" << "  |" << endl;
		col->setXY(28, 13);
		cout << "——————————————" << endl;
		Sleep(1000);
		hu->selectpkSkill();
	}
	
}

void snowstorm::studentSkill()
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

void snowstorm::lookSkill()
{

	col->setXY(22, 8);
	cout << "—————————————————————" << endl;
	col->setXY(22, 9);
	cout << "| 对全部全体施加冰冻效果三回合，伤害较少" <<" |" << endl;
	col->setXY(22, 10);
	cout << "—————————————————————" << endl;
}
