#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<windows.h>
#include<conio.h>
#include<queue>
#include<stack>

#define INF 9999
using namespace std;

void gotoxy(short x, short y);//ѡ��λ����ʾָ��
void game_comeback(void);//����
void game_setkey(void);//��λ���ý���
void key_up(void);//������
void key_down(void);//������
void key_left(void);//������
void key_right(void);//������
void key_menu(void);//�˵���
void key_yes(void);//ȷ�ϼ�
void key_auto(void);//Ѱ·��
void game_showmake(void);//ѡ���Ѷ�
void game_showdifficulty(void);//��ʾ�Ѷ�
void game_staff(void);//������Ա
void game_start(void);//��ʼ��Ϸ
void player_set(void);//������ɫ
void map1(void);//��Դ�塢�ƶ�
void player_status(void);//״̬���˵�
void player_menu(void);//�˵�����
//void player_lvup(void);//����������Ա��
void game_findway(char(*q)[71]);//�Զ�Ѱ·
void save(void);//����
void load(void);//����
void npc1(void);//npc�����Ի���
void npc2(void);
void npc3(void);
void npc4(void);

short dif = 2;//Ĭ���Ѷȣ��е�
short map = 1;//��һ��ͼ
char UP = 'w';
char DOWN = 's';
char LEFT = 'a';
char RIGHT = 'd';
char MENU = 'c';
char YES = 'e';
char AUTO = 'z';//��ʼ��λ
short row = 15;
short column = 35;//λ��
bool return_menu = 0;//�������˵�

struct Poi//λ�ã�Ѱ·
{
	short x, y, px, py, dis;
	bool flag;
}poi[22][70];

typedef struct character//��ɫ
{
	char name[12];//����
	short lv;//level
	int gold;//Ǯ
	int exp, hpmax, mpmax, hp, mp;//���顢������������
	short Atk, Def, Str, Int, Agi, Men, Luc;//��������������
	short attributes;//���Ե�
	short hprec, mprec;//��Ѫ����
	short hpmed, hpmed2, mpmed, mpmed2;//��ҩ����졢��ҩ������
	short quest;//����
				//short weaponon;//��ǰ����
				//short armoron;//��ǰ����
				//short weapon[4];//����
				//short armor[4];//����
				//short passive[5];//����
				//short active[10];//����
}character;

/*typedef struct monster//��
{
char name[12];//����
int gold;//��Ǯ
int exp;//����
short hpmax;//��hp
short hp;//��ǰhp
short Atk, Def, Agi, Luc;//��������
short weapon;//������
short armor;//��װ��
short medicine;//��ҩ
}monster;

typedef struct weapons//����
{
char name[12];//����
short Atk, Def, Str, Int, Agi, Men, Luc;//��������������
short addskill;//+����
int gold;//�۸�
}weapons;

typedef struct armors//����
{
char name[12];//����
short Def, Str, Int, Agi, Men, Luc;//������������
short addskill;//+����
int gold;//�۸�
}armors;*/

character player;