#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<windows.h>
#include<conio.h>
#include<queue>
#include<stack>

#define INF 9999
using namespace std;

void gotoxy(short x, short y);//选定位置显示指针
void game_comeback(void);//返回
void game_setkey(void);//键位设置界面
void key_up(void);//设置上
void key_down(void);//设置下
void key_left(void);//设置左
void key_right(void);//设置右
void key_menu(void);//菜单键
void key_yes(void);//确认键
void key_auto(void);//寻路键
void game_showmake(void);//选择难度
void game_showdifficulty(void);//显示难度
void game_staff(void);//制作人员
void game_start(void);//开始游戏
void player_set(void);//创建角色
void map1(void);//桃源村、移动
void player_status(void);//状态、菜单
void player_menu(void);//菜单操作
//void player_lvup(void);//升级后的属性变更
void game_findway(char(*q)[71]);//自动寻路
void save(void);//保存
void load(void);//载入
void npc1(void);//npc（仅对话）
void npc2(void);
void npc3(void);
void npc4(void);

short dif = 2;//默认难度：中等
short map = 1;//第一张图
char UP = 'w';
char DOWN = 's';
char LEFT = 'a';
char RIGHT = 'd';
char MENU = 'c';
char YES = 'e';
char AUTO = 'z';//初始键位
short row = 15;
short column = 35;//位置
bool return_menu = 0;//返回主菜单

struct Poi//位置，寻路
{
	short x, y, px, py, dis;
	bool flag;
}poi[22][70];

typedef struct character//角色
{
	char name[12];//名字
	short lv;//level
	int gold;//钱
	int exp, hpmax, mpmax, hp, mp;//经验、满红蓝、红蓝
	short Atk, Def, Str, Int, Agi, Men, Luc;//攻防力智敏精运
	short attributes;//属性点
	short hprec, mprec;//回血回蓝
	short hpmed, hpmed2, mpmed, mpmed2;//红药、大红、蓝药、大蓝
	short quest;//任务
				//short weaponon;//当前武器
				//short armoron;//当前防具
				//short weapon[4];//武器
				//short armor[4];//防具
				//short passive[5];//被动
				//short active[10];//主动
}character;

/*typedef struct monster//怪
{
char name[12];//名字
int gold;//掉钱
int exp;//经验
short hpmax;//满hp
short hp;//当前hp
short Atk, Def, Agi, Luc;//攻防敏运
short weapon;//掉武器
short armor;//掉装备
short medicine;//掉药
}monster;

typedef struct weapons//武器
{
char name[12];//名称
short Atk, Def, Str, Int, Agi, Men, Luc;//攻防力智敏精运
short addskill;//+技能
int gold;//价格
}weapons;

typedef struct armors//防具
{
char name[12];//名称
short Def, Str, Int, Agi, Men, Luc;//防力智敏精运
short addskill;//+技能
int gold;//价格
}armors;*/

character player;