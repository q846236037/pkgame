#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include "windows.h"
#include "login.h"
#include <fstream>
#include "color.h"
#include "hero.h"
#include "master.h"
#include "pastor.h"
#include "soldier.h"
#include "stage.h"
#include "redmedicine.h"
#include "bluemedicine.h"
#include "quickmedicine.h"
#include "skill.h";
#include "scorchingSun.h";
#include "snowstorm.h";
#include "suddenAdvance.h";
#include "scaleph.h"
using namespace std;
class login;
class stage;
class hud
{
public:
	hud();
	~hud();
	color *col;
	int MenuNum; //�˵�����
	int MonsterNum;//��������
	int LoginNum;//��¼����
	int heroNum;//Ӣ������
	int startNum;//��ʼ����
	int shopNum;//��Ʒ����
	int stageNum;//��������
	int skillNum;//��������
	int pkNum;//pk����
	int makemon;
	int x;//X��
	int y;//y��
	hero *her;
	monster *mon1;
	monster *mon2;
	hero **t_her;//����ָ��
	login *log;
	void drawBlood(int x, int y,int num = 20,string name =" ");//��Ѫ��
	void drawmp(int x, int y, int num = 20);//������
	void drawlevel(int x, int y, int num = 20);//���ȼ�
	void setcolor(color *col);
	void drawMeun(); //���˵�
	void Meun();//�˵�
	void enterMeun();//�˵��س�
	void drawMonster(int x,int y,int num = 1,int state = 0);//������
	void selectMonster();//ѡ�����
	void drawLogin(); //����¼ҳ��
	void selectLogin(); //����¼ҳ��
	void EnterLogin();//��¼�س�
	void exitfn(); //�˳�
	void setLogin(login *log);//���õ�¼��
	void LoginLoading();//��¼
	void drawtitle();//������
	void drawHero(int i=1,int xsize = 25, int ysize = 5,int state =0); //��Ӣ��
	void drawSelectHero();//��ѡ��Ӣ��
	void moveSelectHero();//�ƶ�Ӣ��ѡ��
	void enterMoveSelectHero();//�س��ƶ�Ӣ��ѡ��
	void sethero(hero *her);//����Ӣ��
	int gerHeroNumber();//���Ӣ������
	void drawstart();//����ʼ����
	void selectstart(); //��ʼѡ��
	void enterSelectStart();//ѡ��س�
	void showHeroInfo();//��Ϣչʾ����
	void showshop();//�̵����
	void selectshop();//�̵����
	void entershop();//�̵�ȷ��
	void saveHero();//����Ӣ������
	void drawstage();//������
	int getstageNum(int i);//����
	void selectstage();//ѡ�����
	void enterstage();//���߻س�
	bool is_start;//�Ƿ�ʼ
	void drawskill();//������
	void selecskill();//ѡ����
	void enterskill();//���ܻس�
	void drawpk(int state =0);//ս������
	void setmon(monster *mon,int i);//����mon;
	void selectPkNum();//ѡ��pk����
	void enterPk();//pk �س�
	void drawPkSkill();//��ս������
	int pkskilNum;//ս����������
	void selectpkSkill();//ѡ��ս������
	void enterSelectPkskill();//�س�ս������
	void drawcube(int x, int y,bool b = true);//��������
	void enterselectpk();//ѡ��ս�����޻س�;
	int is_anm;
};

