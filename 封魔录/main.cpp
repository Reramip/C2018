#include"utinity.h"

int main(void)
{
	short hang = 0;
	char ch = 1;

	system("color FC");
	system("cls");

	do {
		gotoxy(22, 8);
		printf("开始游戏\t\t上：%c\t下：%c", UP, DOWN);
		gotoxy(22, 10);
		printf("键位设置\t\t左：%c\t右：%c", LEFT, RIGHT);
		gotoxy(22, 12);
		printf("难度设置\t\t自动寻路：%c", AUTO);
		gotoxy(22, 14);
		printf("制作人员\t\t菜单：%c", MENU);
		gotoxy(22, 16);
		if (YES == 13) printf("退出游戏\t\t确认：回车");
		else printf("退出游戏\t\t确认：%c", YES);

		game_showdifficulty();

		gotoxy(20, hang + 8);
		printf("%c%c", 16, 16);
		gotoxy(14, 0);

		ch = _getch();

		if (ch == UP)
		{
			gotoxy(20, hang + 8);
			printf("  ");
			hang -= 2;
			if (hang < 0) hang = 0;
			gotoxy(20, hang + 8);
			printf("%c%c", 16, 16);
		}
		else if (ch == DOWN)
		{
			gotoxy(20, hang + 8);
			printf("  ");
			hang += 2;
			if (hang > 8) hang = 8;
			gotoxy(20, hang + 8);
			printf("%c%c", 16, 16);
		}

		if (hang == 0 && ch == YES)
		{
			game_start();
		}
		else if (hang == 2 && ch == YES)
		{
			system("cls");
			gotoxy(26, 4);
			printf("请按如下顺序依次输入键位");

			game_setkey();

			key_up();
			key_down();
			key_left();
			key_right();
			key_menu();
			key_yes();
			key_auto();

			gotoxy(26, 24);
			printf("键位更改完成，请按确认键返回");

			game_comeback();
		}
		else if (hang == 4 && ch == YES)
			game_showmake();
		else if (hang == 6 && ch == YES)
		{
			game_staff();
			gotoxy(0, 0);
			game_comeback();
		}
	} while (!(hang == 8 && ch == YES));

	return 0;
}


void gotoxy(short x, short y)//指定位置显示指针
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}//指定位置显示指针


void game_comeback(void)//返回主界面
{
	char input = 0;

	while (input != YES)
		input = _getch();

	system("cls");
}//返回主界面


void game_setkey(void)//键位设置界面
{
	gotoxy(22, 8);
	printf("上：  ");
	gotoxy(22, 10);
	printf("下：  ");
	gotoxy(22, 12);
	printf("左：  ");
	gotoxy(22, 14);
	printf("右：  ");
	gotoxy(22, 16);
	printf("菜单：  ");
	gotoxy(22, 18);
	printf("确认：  ");
	gotoxy(22, 20);
	printf("自动寻路：  ");
}//键位设置界面

void key_up(void)//键位设置
{
	gotoxy(29, 8);
	UP = _getch();
	gotoxy(22, 8);
	printf("上：  %c", UP);//上
}
void key_down(void)
{
	gotoxy(29, 10);
	DOWN = _getch();
	gotoxy(22, 10);
	printf("下：  %c", DOWN);//下
}
void key_left(void)
{
	gotoxy(29, 12);
	LEFT = _getch();
	gotoxy(22, 12);
	printf("左：  %c", LEFT);//左
}
void key_right(void)
{
	gotoxy(29, 14);
	RIGHT = _getch();
	gotoxy(22, 14);
	printf("右：  %c", RIGHT);//右
}
void key_menu(void)
{
	gotoxy(31, 16);
	MENU = _getch();
	gotoxy(22, 16);
	printf("菜单：  %c", MENU);//角色面板
}
void key_yes(void)
{
	gotoxy(31, 18);
	YES = _getch();
	gotoxy(22, 18);
	if (YES == 13) printf("确认：回车");//确认键
	else printf("确认：  %c", YES);
}
void key_auto(void)
{
	gotoxy(35, 20);
	AUTO = _getch();
	gotoxy(22, 20);
	printf("自动寻路：  %c", AUTO);//自动寻路
}//键位设置


void game_showmake(void)//选难度
{
	char ch1 = 1;

	system("cls");

	gotoxy(22, 8);
	printf("简单");
	gotoxy(22, 10);
	printf("中等");
	gotoxy(22, 12);
	printf("困难");

	while (ch1 != YES)
	{
		gotoxy(20, dif + 8);
		printf("%c%c", 16, 16);
		gotoxy(0, 0);

		ch1 = _getch();

		if (ch1 == UP)
		{
			gotoxy(20, dif + 8);
			printf("  ");
			dif -= 2;
			if (dif < 0) dif = 0;
			gotoxy(20, dif + 8);
			printf("%c%c", 16, 16);
		}
		if (ch1 == DOWN)
		{
			gotoxy(20, dif + 8);
			printf("  ");
			dif += 2;
			if (dif > 4) dif = 4;
			gotoxy(20, dif + 8);
			printf("%c%c", 16, 16);
		}
		gotoxy(20, dif + 8);
		printf("  ");
	}
}//选难度


void game_showdifficulty(void)//显示难度
{
	gotoxy(0, 0);
	switch (dif)
	{
	case 0:printf("游戏难度：简单"); break;
	case 2:printf("游戏难度：中等"); break;
	case 4:printf("游戏难度：困难"); break;
	default:printf("游戏难度：简单"); break;
	}
}//显示难度


void game_staff(void)//制作人员
{
	system("cls");
	gotoxy(0, 0);

	gotoxy(22, 8);
	printf("制作者：abc");
	gotoxy(22, 10);
	printf("2018年4月XX日");
	gotoxy(0, 0);
}//制作人员


void game_start(void)//开始游戏
{
	return_menu = 0;
	row = 15;
	column = 35;
	player_set();
	map1();
	system("cls");
	system("color FC");
	return;
}//开始游戏


void player_set(void)//创建角色
{
	strcpy(player.name, "咕星星");
	player.lv = 1;
	player.exp = 0;
	player.quest = 0;
	player.gold = (4 - dif) * 250;
	player.Luc = 2;
	player.Str = 6;
	player.Int = 6;
	player.Agi = 4;
	player.Men = 4;
	player.attributes = 4;
	player.hpmed = (4 - dif) / 2;
	player.mpmed = (4 - dif) / 2;
	player.hpmed2 = 0;
	player.mpmed2 = 0;
	player.hprec = 5;
	player.mprec = 3;
	player.Atk = 15;
	player.Def = 8;
	player.hp = player.hpmax = 100;
	player.mp = player.mpmax = 100;
}


void map1(void)//桃源村、移动
{

	char map_1_A[20][71];
	char go_1_A[22][71];
	char *p = map_1_A[0];
	char *q = go_1_A[0];
	short i, j;

	system("cls");
	system("color F2");

	game_showdifficulty();
	gotoxy(30, 1);
	printf("桃源村");

	gotoxy(0, 2);

	/*初始化*/
	for (i = 0; i < 20; i++)
	{
		map_1_A[i][70] = '\0';
		go_1_A[i + 2][70] = '\0';
	}

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 70; j++)
		{
			*(p + i * 71 + j) = ' ';
			*(q + (i + 2) * 71 + j) = 1;
		}
	}

	for (j = 0; j < 70; j++) *(p + j) = '#';//围墙
	for (j = 0; j < 70; j++) *(p + 71 * 19 + j) = '#';
	for (i = 0; i < 20; i++) *(p + 71 * i) = '#';
	for (i = 0; i < 20; i++) *(p + 71 * i + 69) = '#';//围墙

	*(p + 71 * 9 + 69) = ' ';//出口

	for (i = 3; i < 5; ++i)//npc1
	{
		for (j = 8; j < 15; ++j)
			*(p + i * 71 + j) = '#';
	}
	*(p + 71 * 5 + 11) = '@';//npc1
	for (i = 3; i < 5; ++i)//npc2
	{
		for (j = 56; j < 63; ++j)
			*(p + i * 71 + j) = '#';
	}
	*(p + 71 * 5 + 59) = '!';//npc2
	for (i = 14; i < 16; ++i)//npc3
	{
		for (j = 8; j < 15; ++j)
			*(p + i * 71 + j) = '#';
	}
	*(p + 71 * 16 + 11) = '&';//npc3
	for (i = 14; i < 16; ++i)//npc4
	{
		for (j = 56; j < 63; ++j)
			*(p + i * 71 + j) = '#';
	}
	*(p + (71 << 4) + 59) = '$';//npc4

	for (i = 7; i < 10; ++i)//烟囱
	{
		for (j = 31; j < 35; ++j)
			*(p + 71 * i + j) = '*';
	}
	*(p + (71 << 3) + 32) = ' ';
	*(p + (71 << 3) + 33) = ' ';//烟囱

	for (i = 0; i < 20; i++)
		puts(map_1_A[i]);//显示地图

	for (i = 0; i < 20; i++)//设障
	{
		for (j = 0; j < 70; j++)
		{
			if (*(p + 71 * i + j) != ' ')
				*(q + 71 * (i + 2) + j) = 0;
		}
	}
	for (i = 6; i < 11; ++i)
	{
		for (j = 30; j < 36; ++j)
			*(q + 71 * (i + 2) + j) = 0;
	}//设障

	*(q + 71 * 11 + 70) = 2;//出口

	player_status();

	do {
		gotoxy(column, row);
		printf("%c", 1);
		gotoxy(14, 0);

		char ch = _getch();

		if (ch == UP)
		{
			if (*(q + 71 * (row - 1) + column) != 0)
			{
				row -= 1;
				gotoxy(column, row + 1);
				printf(" ");
			}
		}
		if (ch == DOWN)
		{
			if (*(q + 71 * (row + 1) + column) != 0)
			{
				row += 1;
				gotoxy(column, row - 1);
				printf(" ");
			}
		}
		if (ch == LEFT)
		{
			if (*(q + 71 * row + (column - 1)) != 0)
			{
				column -= 1;
				gotoxy(column + 1, row);
				printf(" ");
			}
		}
		if (ch == RIGHT)
		{
			if (*(q + 71 * row + (column + 1)) != 0)
			{
				column += 1;
				gotoxy(column - 1, row);
				printf(" ");
			}
		}
		if (ch == AUTO)
		{
			game_findway(go_1_A);
		}

		if (ch == MENU)
		{
			player_menu();
			if (return_menu == 1) return;
		}

		if (ch == YES)
		{
			if (row == 7)
			{
				if (column == 10 || column == 12) npc1();
				else if (column == 58 || column == 60) npc2();
			}
			else if (row == 8)
			{
				if (column == 11) npc1();
				else if (column == 59) npc2();
			}
			else if (row == 18)
			{
				if (column == 10 || column == 12) npc3();
				else if (column == 58 || column == 60) npc4();
			}
			else if (row == 19)
			{
				if (column == 11) npc3();
				else if (column == 59) npc4();
			}
		}
	} while (*(q + 71 * row + column) != 2);

}//桃源村

void player_status(void)//角色状态
{
	gotoxy(73, 1);
	printf("LV:%d", player.lv);
	gotoxy(73, 3);
	printf("HP:%d/%d", player.hp, player.hpmax);
	gotoxy(73, 5);
	printf("MP:%d/%d", player.mp, player.mpmax);
	gotoxy(85, 1);
	printf("武器：");
	gotoxy(85, 3);
	printf("防具：");
	gotoxy(85, 5);
	printf("GOLD:%d", player.gold);
	gotoxy(73, 6);
	printf("――――――――――――――");
	gotoxy(73, 7);
	printf("属性点：%d", player.attributes);
	gotoxy(85, 7);
	printf("LUC:%d", player.Luc);
	gotoxy(73, 9);
	printf("ATK:%d", player.Atk);
	gotoxy(85, 9);
	printf("DEF:%d", player.Def);
	gotoxy(73, 11);
	printf("STR:%d", player.Str);
	gotoxy(85, 11);
	printf("INT:%d", player.Int);
	gotoxy(73, 13);
	printf("AGI:%d", player.Agi);
	gotoxy(85, 13);
	printf("MEN:%d", player.Men);
	gotoxy(73, 14);
	printf("――――――――――――――");
	gotoxy(73, 15);
	printf("小红：%d", player.hpmed);
	gotoxy(85, 15);
	printf("大红：%d", player.hpmed2);
	gotoxy(73, 17);
	printf("小蓝：%d", player.mpmed);
	gotoxy(85, 17);
	printf("大蓝：%d", player.mpmed2);
	gotoxy(73, 18);
	printf("――――――――――――――");
	gotoxy(73, 19);
	printf("武器");
	gotoxy(85, 19);
	printf("武器");
	gotoxy(73, 21);
	printf("武器");
	gotoxy(85, 21);
	printf("武器");
	gotoxy(73, 23);
	printf("防具");
	gotoxy(85, 23);
	printf("防具");
	gotoxy(73, 25);
	printf("防具");
	gotoxy(85, 25);
	printf("防具");
	gotoxy(73, 26);
	printf("――――――――――――――");
	gotoxy(73, 27);
	printf("保存");
	gotoxy(85, 27);
	printf("载入");
	gotoxy(73, 29);
	printf("返回");
	gotoxy(85, 29);
	printf("主菜单");
}

void player_menu(void)//角色菜单操作
{
	short hang = 0;//行
	short lie = 0;//列
	char ch1 = 0;

	gotoxy(lie + 72, hang + 11);
	printf("%c", 16);
	gotoxy(14, 0);

	do {
		ch1 = _getch();

		if (ch1 == UP)
		{
			gotoxy(lie + 72, hang + 11);
			printf(" ");
			hang -= 2;
			if (hang < 0) hang = 0;
			gotoxy(lie + 72, hang + 11);
			printf("%c", 16);
		}
		else if (ch1 == DOWN)
		{
			gotoxy(lie + 72, hang + 11);
			printf(" ");
			hang += 2;
			if (hang > 18) hang = 18;
			gotoxy(lie + 72, hang + 11);
			printf("%c", 16);
		}
		else if (ch1 == LEFT)
		{
			gotoxy(lie + 72, hang + 11);
			printf(" ");
			lie -= 12;
			if (lie < 0) lie = 0;
			gotoxy(lie + 72, hang + 11);
			printf("%c", 16);
		}
		else if (ch1 == RIGHT)
		{
			gotoxy(lie + 72, hang + 11);
			printf(" ");
			lie += 12;
			if (lie > 12) lie = 12;
			gotoxy(lie + 72, hang + 11);
			printf("%c", 16);
		}
		else if (ch1 == YES)//确认
		{
			switch (lie)
			{

			case 0:
			{
				switch (hang)
				{
				case 0: //+力
				{
					if (player.attributes)
					{
						player.Str++;
						player.attributes--;
						if (player.Str % 2 == 0) player.Atk++;
						if (player.Str % 10 == 0)
						{
							player.hpmax += 5;
							player.hp += 5;
						}
					}
					break;
				}
				case 2://+敏
				{
					if (player.attributes)
					{
						player.Agi++;
						player.attributes--;
					}
					break;
				}
				case 4://红药
				{
					if (player.hpmed)
					{
						player.hp += (40 + player.Str);
						if (player.hp > player.hpmax) player.hp = player.hpmax;
						player.hpmed--;
					}
					break;
				}
				case 6://蓝药
				{
					if (player.mpmed)
					{
						player.mp += (40 + player.Men);
						if (player.mp > player.mpmax) player.mp = player.mpmax;
						player.mpmed--;
					}
					break;
				}
				case 8:break;//back_weapon1
				case 10:break;//back_weapon3
				case 12:break;//back_armor1
				case 14:break;//back_armor3
				case 16:save(); break; 
				case 18:gotoxy(lie + 72, hang + 11); printf(" "); return;
				default:break;
				}
				break;
			}
			
			case 12:
			{
				switch (hang)
				{
				case 0://+智
				{
					if (player.attributes)
					{
						player.Int++;
						player.attributes--;
					}
					break;
				}
				case 2://+精
				{
					if (player.attributes)
					{
						player.Men++;
						player.mpmax += 5;
						player.mp += 5;
						player.attributes--;
					}
					break;
				}
				case 4://大红
				{
					if (player.hpmed2)
					{
						player.hp = player.hpmax;
						player.hpmed2--;
					}
					break;
				}
				case 6://大蓝
				{
					if (player.mpmed2)
					{
						player.mp = player.mpmax;
						player.mpmed2--;
					}
					break;
				}
				case 8:break;//back_weapon2
				case 10:break;//back_weapon4
				case 12:break;//back_armor2
				case 14:break;//back_armor4
				case 16:load(); player_status(); break;
				case 18:return_menu = 1; return;
				default:break;
				}
				break;
			}

			default:break;
			}
			player_status();
		}
		gotoxy(14, 0);

	} while (1);

	gotoxy(lie + 72, hang + 11);
	printf(" ");
}//角色菜单操作
/*
void player_lvup(void)//升级后属性变更
{
	player.lv++;
	if (!(player.lv % 4)) player.Luc++;
	player.Str++;
	player.Int++;
	player.Agi++;
	player.Men++;
	player.attributes += 4;
	player.Atk += (2 + player.Str / 7);
	player.Def += (1 + player.Str / 13 + player.Men / 20);
	player.hpmax += (15 + player.Str / 7);
	player.mpmax += (6 + player.Men / 3);
	player.hp = player.hpmax;
	player.mp = player.mpmax;
}//升级后属性变更
*/
void game_findway(char(*q)[71])//自动寻路（bfs）
{
	queue<Poi> a;//遍历定距离
	stack<Poi> b;//记录路径（终→始）
	stack<Poi> c;//寻路

	for (register int i = 0; i < 20; i++)//初始化
	{
		for (register int j = 0; j < 70; j++)
		{
			if (q[i + 2][j] == 0)
			{
				poi[i + 2][j].flag = 1;
				poi[i + 2][j].dis = -1;
			}
			else
			{
				poi[i + 2][j].flag = 0;
				poi[i + 2][j].dis = INF;
			}
		}
	}

	poi[row][column].x = column;//当前位置
	poi[row][column].y = row;
	poi[row][column].px = column;
	poi[row][column].py = row;
	poi[row][column].dis = 0;
	poi[row][column].flag = 1;

	a.push(poi[row][column]);

	while (!a.empty())//确定各节点距离
	{
		Poi t = a.front();
		if (t.y == 11 && t.x == 69) break;
		short h = t.y;
		short l = t.x;
		a.pop();

		if (poi[h - 1][l].flag == 0 && (poi[h - 1][l].dis > poi[h][l].dis))
		{
			poi[h - 1][l].flag = 1;
			poi[h - 1][l].x = l;
			poi[h - 1][l].y = h - 1;
			poi[h - 1][l].px = poi[h][l].x;
			poi[h - 1][l].py = poi[h][l].y;
			poi[h - 1][l].dis = poi[h][l].dis + 1;
			a.push(poi[h - 1][l]);
		}
		if (poi[h + 1][l].flag == 0 && (poi[h + 1][l].dis > poi[h][l].dis))
		{
			poi[h + 1][l].flag = 1;
			poi[h + 1][l].x = l;
			poi[h + 1][l].y = h + 1;
			poi[h + 1][l].px = poi[h][l].x;
			poi[h + 1][l].py = poi[h][l].y;
			poi[h + 1][l].dis = poi[h][l].dis + 1;
			a.push(poi[h + 1][l]);
		}
		if (poi[h][l - 1].flag == 0 && (poi[h][l - 1].dis > poi[h][l].dis))
		{
			poi[h][l - 1].flag = 1;
			poi[h][l - 1].x = l - 1;
			poi[h][l - 1].y = h;
			poi[h][l - 1].px = poi[h][l].x;
			poi[h][l - 1].py = poi[h][l].y;
			poi[h][l - 1].dis = poi[h][l].dis + 1;
			a.push(poi[h][l - 1]);
		}
		if (poi[h][l + 1].flag == 0 && (poi[h][l + 1].dis > poi[h][l].dis))
		{
			poi[h][l + 1].flag = 1;
			poi[h][l + 1].x = l + 1;
			poi[h][l + 1].y = h;
			poi[h][l + 1].px = poi[h][l].x;
			poi[h][l + 1].py = poi[h][l].y;
			poi[h][l + 1].dis = poi[h][l].dis + 1;
			a.push(poi[h][l + 1]);
		}
	}

	b.push(poi[11][69]);//出口

	while (!b.empty())//记录路径，从后往前
	{
		Poi t = b.top();
		c.push(t);//颠倒顺序
		b.pop();
		if (t.px == column&&t.py == row) break;
		short h = t.py;
		short l = t.px;
		b.push(poi[h][l]);
	}

	while (!c.empty())//移动
	{
		Poi t = c.top();
		c.pop();
		gotoxy(column, row);
		printf(" ");
		column = t.x;
		row = t.y;
		gotoxy(column, row);
		printf("%c", 1);
		gotoxy(14, 0);
		Sleep(80);
	}
}//自动寻路

void save(void)
{
	FILE *fp;
	fp = fopen("save.txt", "w");
	fprintf(fp, "                                                                                                         	                                                                                                  ");
	fclose(fp);
	fp = fopen("save.txt", "w");
	if (fp == NULL)
	{
		gotoxy(0, 23);
		printf("保存失败");
		gotoxy(14, 0);
		Sleep(2000);
		gotoxy(0, 23);
		printf("             ");
		gotoxy(14, 0);
		return;
	}
	fprintf(fp, "%hd %hd %hd %hd %d %d %d %d %d %d %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %s"
		, row, column, player.quest, player.lv, player.gold, player.exp, player.hpmax, player.hp, player.mpmax
		, player.mp, player.hpmed, player.hpmed2, player.mpmed, player.mpmed2, player.hprec, player.mprec
		, player.attributes, player.Atk, player.Def, player.Luc, player.Str, player.Int, player.Agi, player.Men
		, player.name);
	fclose(fp);
}//保存

void load(void)
{
	FILE *fp;
	fp = fopen("save.txt", "r");
	if (fp == NULL)
	{
		gotoxy(0, 23);
		printf("载入失败");
		gotoxy(14, 0);
		Sleep(2000);
		gotoxy(0, 23);
		printf("             ");
		gotoxy(14, 0);
		return;
	}
	gotoxy(column, row);
	printf(" ");
	fscanf(fp, "%hd %hd %hd %hd %d %d %d %d %d %d %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %hd %s"
		, &row, &column, &player.quest, &player.lv, &player.gold, &player.exp, &player.hpmax, &player.hp
		, &player.mpmax, &player.mp, &player.hpmed, &player.hpmed2, &player.mpmed, &player.mpmed2
		, &player.hprec, &player.mprec, &player.attributes, &player.Atk, &player.Def, &player.Luc
		, &player.Str, &player.Int, &player.Agi, &player.Men, player.name);
	fclose(fp);
	gotoxy(column, row);
	printf("%c", 1);
}//载入

void npc1(void)
{
	short hang = 0;
	char ch = 0;
	gotoxy(0, 22);
	printf("裁缝：我这有各种护甲，你要看看吗？ %c\n%c 买卖（未实现）\n  离开", 31, 16);
	gotoxy(14, 0);
	do {
		ch = _getch();
		if (ch == UP)
		{
			gotoxy(0, hang + 23);
			printf(" ");
			hang--;
			if (hang < 0) hang = 0;
			gotoxy(0, hang + 23);
			printf("%c", 16);
			gotoxy(14, 0);
		}
		else if (ch == DOWN)
		{
			gotoxy(0, hang + 23);
			printf(" ");
			hang++;
			if (hang > 1) hang = 1;
			gotoxy(0, hang + 23);
			printf("%c", 16);
			gotoxy(14, 0);
		}
	} while (!(hang == 1 && ch == YES));
	gotoxy(0, 22);
	printf("裁缝：村子里好多人都不见了！我这生意也不好做了！           \n                    \n                   ");
	gotoxy(14, 0);
	Sleep(2000);
	gotoxy(0, 22);
	printf("                                                          ");
	gotoxy(14, 0);
}//npc1

void npc2(void)
{
	short hang = 0;
	char ch = 0;
	if (!player.quest)
	{
		gotoxy(0, 22);
		printf("黎夫人：村里好多人都不见了，还有我的老伴。你能帮我找找吗？ %c\n%c 好！我帮你找找吧。\n  不了，我还有事。", 31, 16);
		gotoxy(14, 0);
		do {
			ch = _getch();
			if (ch == UP)
			{
				gotoxy(0, hang + 23);
				printf(" ");
				hang--;
				if (hang < 0) hang = 0;
				gotoxy(0, hang + 23);
				printf("%c", 16);
				gotoxy(14, 0);
			}
			else if (ch == DOWN)
			{
				gotoxy(0, hang + 23);
				printf(" ");
				hang++;
				if (hang > 1) hang = 1;
				gotoxy(0, hang + 23);
				printf("%c", 16);
				gotoxy(14, 0);
			}
		} while (ch != YES);
		gotoxy(0, 22);
		if (hang == 1)
		{ 
			printf("黎夫人：那我还是另找他人吧。                                  \n                    \n                   ");
			gotoxy(14, 0);
			Sleep(2000);
			gotoxy(0, 22);
			printf("                             ");
		}
		else if (hang == 0)
		{
			player.quest = 1;
			printf("黎夫人：他们去了外面的一个山洞里，就再也没回来过了！               \n                    \n                   ");
			gotoxy(14, 0);
			Sleep(2000);
			gotoxy(0, 22);
			printf("你接到一个任务：去山洞寻找失踪的人们。             ");
			gotoxy(14, 0);
			Sleep(2000);
			gotoxy(0, 22);
			printf("                                            ");
		}
		gotoxy(14, 0);
	}
	else
	{
		gotoxy(0, 22);
		printf("黎夫人：你去山洞救救他们吧。谢谢了，壮士！");
		gotoxy(14, 0);
		Sleep(2000);
		gotoxy(0, 22);
		printf("                                                ");
		gotoxy(14, 0);
	}
}//npc2

void npc3(void)
{
	short hang = 0;
	char ch = 0;
	gotoxy(0, 22);
	printf("铁匠：我这有各种武器，你要看看吗？ %c\n%c 买卖（未实现）\n  离开", 31, 16);
	gotoxy(14, 0);
	do {
		ch = _getch();
		if (ch == UP)
		{
			gotoxy(0, hang + 23);
			printf(" ");
			hang--;
			if (hang < 0) hang = 0;
			gotoxy(0, hang + 23);
			printf("%c", 16);
			gotoxy(14, 0);
		}
		else if (ch == DOWN)
		{
			gotoxy(0, hang + 23);
			printf(" ");
			hang++;
			if (hang > 1) hang = 1;
			gotoxy(0, hang + 23);
			printf("%c", 16);
			gotoxy(14, 0);
		}
	} while (!(hang == 1 && ch == YES));
	gotoxy(0, 22);
	printf("铁匠：村子里好多人都不见了！我这生意也不好做了！           \n                    \n                   ");
	gotoxy(14, 0);
	Sleep(2000);
	gotoxy(0, 22);
	printf("                                                          ");
	gotoxy(14, 0);
}//npc3

void npc4(void)
{
	short hang = 0;
	char ch = 0;
	gotoxy(0, 22);
	printf("药师：我这有各种药品，你要看看吗？ %c\n%c 买卖（未实现）\n  离开", 31, 16);
	gotoxy(14, 0);
	do {
		ch = _getch();
		if (ch == UP)
		{
			gotoxy(0, hang + 23);
			printf(" ");
			hang--;
			if (hang < 0) hang = 0;
			gotoxy(0, hang + 23);
			printf("%c", 16);
			gotoxy(14, 0);
		}
		else if (ch == DOWN)
		{
			gotoxy(0, hang + 23);
			printf(" ");
			hang++;
			if (hang > 1) hang = 1;
			gotoxy(0, hang + 23);
			printf("%c", 16);
			gotoxy(14, 0);
		}
	} while (!(hang == 1 && ch == YES));
	gotoxy(0, 22);
	printf("药师：村子里好多人都不见了！我这生意也不好做了！           \n                    \n                   ");
	gotoxy(14, 0);
	Sleep(2000);
	gotoxy(0, 22);
	printf("                                                          ");
	gotoxy(14, 0);
}//npc4
