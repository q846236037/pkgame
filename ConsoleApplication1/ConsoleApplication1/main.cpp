#include "main.h"




void play() {

	cout << "1����ʦ" << endl;
	cout << "2����ʦ" << endl;
	cout << "3��սʿ" << endl;
	int num;
	hero *her =NULL;
	cin >> num;
	bool is_while = true;
	while (is_while)
	{
		switch (num)
		{
		default:cout << "���������������" << endl; break;
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

	play();
	system("pause");
}