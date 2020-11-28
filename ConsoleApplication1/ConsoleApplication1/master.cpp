#include "master.h"



master::master()
{
	 name = "法师";
	 mp = 200; // 法力值上限
	 hp = 100;//血量上限
	 level = 1;//级别
	max_level =level*200;//升级所需经验
	money = 0;//金钱
	hurt = 5;//伤害
	defense = 5;//防御
	skillname = NULL;
	mon = NULL;
}


master::~master()
{
}

void master::setSkill(skill * name)
{
	this->skillname = name;
}

void master::setMonster(monster * mon)
{
	this->mon = mon;
	cout << "选择了" << this->mon->name;
}

void master::attack()
{
	cout << mon->hp << endl;
	cout << this->skillname <<"name:"<< (this->skillname == NULL )<< endl;
	if (mon->hp>0)
	{
		//普通攻击
		if (this->skillname == NULL) {
			int hurt;
			hurt = this->hurt - mon->defense;
			mon->hp -= hurt;
			cout <<this->name<< "造成了" << hurt << "点伤害" << endl;
			cout << mon->name << "剩余" << mon->hp << "血量" << endl;
			mon->setPlayer(this);
			mon->attack();
			
		}
	}
	
	
}
