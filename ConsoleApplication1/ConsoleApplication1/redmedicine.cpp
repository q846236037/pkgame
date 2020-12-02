#include "redmedicine.h"
#include "hud.h"


redmedicine::redmedicine()
{
	this->name = "碕勞";
	this->money = 200;
	id = 1;
	col = NULL;
	add = 100;
	hid = -1;
	sta = NULL;
	hid = -1;
}


redmedicine::~redmedicine()
{
	
}

void redmedicine::use()
{
	if (hu->getstageNum(1) > 0)
	{
		her->hp += add;
		if (her->hp > 200)
		{
			her->hp = 200;
		}
		ifstream ifs;
		ifs.open("stage.txt", ios::in);
		int len = getStaNum();
		sta = new stage*[len];
		int h_id;
		int s_id;
		int i = 0;
		while (ifs >> h_id >> s_id)
		{
			if (s_id == 0)
			{
				sta[i] = new bluemedicine(h_id);
			}
			else if (s_id == 1) {
				sta[i] = new redmedicine(h_id);
			}
			else if (s_id == 2) {
				sta[i] = new quickmedicine(h_id);
			}
			i++;
		}
		ifs.close();
		int index = 0;
		for (int i = 0; i < len; i++)
		{
			if (her->id == sta[i]->hid&&sta[i]->id == id) {
				index = i;
				break;
			}
		}
		for (int i = index; i < len; i++)
		{
			if (i == getStaNum() - 1)
			{
				sta[i] = NULL;
			}
			else {
				sta[i] = sta[i + 1];
			}

		}
		ofstream ofs;
		ofs.open("stage.txt", ios::out);
		for (int i = 0; i < len - 1; i++)
		{
			ofs << sta[i]->hid << " " << sta[i]->id << endl;
		}
		ofs.close();
		col->setXY(25, 8);
		cout << "！！！！！！！！！！！！！！！！！" << endl;
		col->setXY(25, 9);
		cout << "|     聞喘撹孔:朕念僮楚��" << her->hp << "     |" << endl;
		col->setXY(25, 10);
		cout << "！！！！！！！！！！！！！！！！！" << endl;
	}
	else {
		col->setXY(25, 8);
		cout << "！！！！！！！！！！！！！！！！！" << endl;
		col->setXY(25, 9);
		cout << "|             聞喘払移           |" << endl;
		col->setXY(25, 10);
		cout << "|          圻咀:方楚音怎         |" << endl;
		col->setXY(25, 11);
		cout << "！！！！！！！！！！！！！！！！！" << endl;
	}
}

void redmedicine::buy()
{
	if (her->money >= money) {
		for (int i = 0; i < hu->gerHeroNumber(); i++)
		{
			if (hu->t_her[i]->id == her->id) {
				hu->t_her[i]->money -= money;
			}
		}
		hu->saveHero();
		ofstream ofs;
		ofs.open("stage.txt", ios::app);
		ofs << her->id << " " << id << endl;
		col->setXY(25, 8);
		cout << "！！！！！！！！！！！！！！！！！" << endl;
		col->setXY(25, 9);
		cout << "|             杭択撹孔           |" << endl;
		col->setXY(25, 10);
		cout << "！！！！！！！！！！！！！！！！！" << endl;
		ofs.close();

	}
	else {
		col->setXY(25, 8);
		cout << "！！！！！！！！！！！！！！！！！" << endl;
		col->setXY(25, 9);
		cout << "|             杭択払移           |" << endl;
		col->setXY(25, 10);
		cout << "|          圻咀:署駆音怎         |" << endl;
		col->setXY(25, 11);
		cout << "！！！！！！！！！！！！！！！！！" << endl;

	}
}

redmedicine::redmedicine(int hid, int id)
{
	this->hid = hid;
	this->id = id;
}
