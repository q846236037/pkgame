#include "main.h"




void play() {

	cout << "1、法师" << endl;
	cout << "2、牧师" << endl;
	cout << "3、战士" << endl;
	int num;
	hero *her =NULL;
	cin >> num;
	bool is_while = true;
	while (is_while)
	{
		switch (num)
		{
		default:cout << "输入错误重新输入" << endl; break;
		case 1:her = new master; is_while = false; break;
		case 2:her = new pastor; is_while = false;  break;
		case 3:her = new soldier; is_while = false; break;
		}
	}
	monster*mon = new scaleph();
	her->setMonster(mon);
	her->attack();


}


void main() {
	cout<<"蓝色"<<endl;
	color c;
	c.setColor();
	cout << "红色" << endl;
	c.getdefault();
	cout << "lv" << endl;
	play();
	system("pause");
}