#include"utinity.h"

int main(void)
{
	short hang = 0;
	char ch = 1;

	system("color FC");
	system("cls");

	do {
		gotoxy(22, 8);
		printf("��ʼ��Ϸ\t\t�ϣ�%c\t�£�%c", UP, DOWN);
		gotoxy(22, 10);
		printf("��λ����\t\t��%c\t�ң�%c", LEFT, RIGHT);
		gotoxy(22, 12);
		printf("�Ѷ�����\t\t�Զ�Ѱ·��%c", AUTO);
		gotoxy(22, 14);
		printf("������Ա\t\t�˵���%c", MENU);
		gotoxy(22, 16);
		if (YES == 13) printf("�˳���Ϸ\t\tȷ�ϣ��س�");
		else printf("�˳���Ϸ\t\tȷ�ϣ�%c", YES);

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
			printf("�밴����˳�����������λ");

			game_setkey();

			key_up();
			key_down();
			key_left();
			key_right();
			key_menu();
			key_yes();
			key_auto();

			gotoxy(26, 24);
			printf("��λ������ɣ��밴ȷ�ϼ�����");

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


void gotoxy(short x, short y)//ָ��λ����ʾָ��
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}//ָ��λ����ʾָ��


void game_comeback(void)//����������
{
	char input = 0;

	while (input != YES)
		input = _getch();

	system("cls");
}//����������


void game_setkey(void)//��λ���ý���
{
	gotoxy(22, 8);
	printf("�ϣ�  ");
	gotoxy(22, 10);
	printf("�£�  ");
	gotoxy(22, 12);
	printf("��  ");
	gotoxy(22, 14);
	printf("�ң�  ");
	gotoxy(22, 16);
	printf("�˵���  ");
	gotoxy(22, 18);
	printf("ȷ�ϣ�  ");
	gotoxy(22, 20);
	printf("�Զ�Ѱ·��  ");
}//��λ���ý���

void key_up(void)//��λ����
{
	gotoxy(29, 8);
	UP = _getch();
	gotoxy(22, 8);
	printf("�ϣ�  %c", UP);//��
}
void key_down(void)
{
	gotoxy(29, 10);
	DOWN = _getch();
	gotoxy(22, 10);
	printf("�£�  %c", DOWN);//��
}
void key_left(void)
{
	gotoxy(29, 12);
	LEFT = _getch();
	gotoxy(22, 12);
	printf("��  %c", LEFT);//��
}
void key_right(void)
{
	gotoxy(29, 14);
	RIGHT = _getch();
	gotoxy(22, 14);
	printf("�ң�  %c", RIGHT);//��
}
void key_menu(void)
{
	gotoxy(31, 16);
	MENU = _getch();
	gotoxy(22, 16);
	printf("�˵���  %c", MENU);//��ɫ���
}
void key_yes(void)
{
	gotoxy(31, 18);
	YES = _getch();
	gotoxy(22, 18);
	if (YES == 13) printf("ȷ�ϣ��س�");//ȷ�ϼ�
	else printf("ȷ�ϣ�  %c", YES);
}
void key_auto(void)
{
	gotoxy(35, 20);
	AUTO = _getch();
	gotoxy(22, 20);
	printf("�Զ�Ѱ·��  %c", AUTO);//�Զ�Ѱ·
}//��λ����


void game_showmake(void)//ѡ�Ѷ�
{
	char ch1 = 1;

	system("cls");

	gotoxy(22, 8);
	printf("��");
	gotoxy(22, 10);
	printf("�е�");
	gotoxy(22, 12);
	printf("����");

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
}//ѡ�Ѷ�


void game_showdifficulty(void)//��ʾ�Ѷ�
{
	gotoxy(0, 0);
	switch (dif)
	{
	case 0:printf("��Ϸ�Ѷȣ���"); break;
	case 2:printf("��Ϸ�Ѷȣ��е�"); break;
	case 4:printf("��Ϸ�Ѷȣ�����"); break;
	default:printf("��Ϸ�Ѷȣ���"); break;
	}
}//��ʾ�Ѷ�


void game_staff(void)//������Ա
{
	system("cls");
	gotoxy(0, 0);

	gotoxy(22, 8);
	printf("�����ߣ�abc");
	gotoxy(22, 10);
	printf("2018��4��XX��");
	gotoxy(0, 0);
}//������Ա


void game_start(void)//��ʼ��Ϸ
{
	return_menu = 0;
	row = 15;
	column = 35;
	player_set();
	map1();
	system("cls");
	system("color FC");
	return;
}//��ʼ��Ϸ


void player_set(void)//������ɫ
{
	strcpy(player.name, "������");
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


void map1(void)//��Դ�塢�ƶ�
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
	printf("��Դ��");

	gotoxy(0, 2);

	/*��ʼ��*/
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

	for (j = 0; j < 70; j++) *(p + j) = '#';//Χǽ
	for (j = 0; j < 70; j++) *(p + 71 * 19 + j) = '#';
	for (i = 0; i < 20; i++) *(p + 71 * i) = '#';
	for (i = 0; i < 20; i++) *(p + 71 * i + 69) = '#';//Χǽ

	*(p + 71 * 9 + 69) = ' ';//����

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

	for (i = 7; i < 10; ++i)//�̴�
	{
		for (j = 31; j < 35; ++j)
			*(p + 71 * i + j) = '*';
	}
	*(p + (71 << 3) + 32) = ' ';
	*(p + (71 << 3) + 33) = ' ';//�̴�

	for (i = 0; i < 20; i++)
		puts(map_1_A[i]);//��ʾ��ͼ

	for (i = 0; i < 20; i++)//����
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
	}//����

	*(q + 71 * 11 + 70) = 2;//����

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

}//��Դ��

void player_status(void)//��ɫ״̬
{
	gotoxy(73, 1);
	printf("LV:%d", player.lv);
	gotoxy(73, 3);
	printf("HP:%d/%d", player.hp, player.hpmax);
	gotoxy(73, 5);
	printf("MP:%d/%d", player.mp, player.mpmax);
	gotoxy(85, 1);
	printf("������");
	gotoxy(85, 3);
	printf("���ߣ�");
	gotoxy(85, 5);
	printf("GOLD:%d", player.gold);
	gotoxy(73, 6);
	printf("�D�D�D�D�D�D�D�D�D�D�D�D�D�D");
	gotoxy(73, 7);
	printf("���Ե㣺%d", player.attributes);
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
	printf("�D�D�D�D�D�D�D�D�D�D�D�D�D�D");
	gotoxy(73, 15);
	printf("С�죺%d", player.hpmed);
	gotoxy(85, 15);
	printf("��죺%d", player.hpmed2);
	gotoxy(73, 17);
	printf("С����%d", player.mpmed);
	gotoxy(85, 17);
	printf("������%d", player.mpmed2);
	gotoxy(73, 18);
	printf("�D�D�D�D�D�D�D�D�D�D�D�D�D�D");
	gotoxy(73, 19);
	printf("����");
	gotoxy(85, 19);
	printf("����");
	gotoxy(73, 21);
	printf("����");
	gotoxy(85, 21);
	printf("����");
	gotoxy(73, 23);
	printf("����");
	gotoxy(85, 23);
	printf("����");
	gotoxy(73, 25);
	printf("����");
	gotoxy(85, 25);
	printf("����");
	gotoxy(73, 26);
	printf("�D�D�D�D�D�D�D�D�D�D�D�D�D�D");
	gotoxy(73, 27);
	printf("����");
	gotoxy(85, 27);
	printf("����");
	gotoxy(73, 29);
	printf("����");
	gotoxy(85, 29);
	printf("���˵�");
}

void player_menu(void)//��ɫ�˵�����
{
	short hang = 0;//��
	short lie = 0;//��
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
		else if (ch1 == YES)//ȷ��
		{
			switch (lie)
			{

			case 0:
			{
				switch (hang)
				{
				case 0: //+��
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
				case 2://+��
				{
					if (player.attributes)
					{
						player.Agi++;
						player.attributes--;
					}
					break;
				}
				case 4://��ҩ
				{
					if (player.hpmed)
					{
						player.hp += (40 + player.Str);
						if (player.hp > player.hpmax) player.hp = player.hpmax;
						player.hpmed--;
					}
					break;
				}
				case 6://��ҩ
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
				case 0://+��
				{
					if (player.attributes)
					{
						player.Int++;
						player.attributes--;
					}
					break;
				}
				case 2://+��
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
				case 4://���
				{
					if (player.hpmed2)
					{
						player.hp = player.hpmax;
						player.hpmed2--;
					}
					break;
				}
				case 6://����
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
}//��ɫ�˵�����
/*
void player_lvup(void)//���������Ա��
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
}//���������Ա��
*/
void game_findway(char(*q)[71])//�Զ�Ѱ·��bfs��
{
	queue<Poi> a;//����������
	stack<Poi> b;//��¼·�����ա�ʼ��
	stack<Poi> c;//Ѱ·

	for (register int i = 0; i < 20; i++)//��ʼ��
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

	poi[row][column].x = column;//��ǰλ��
	poi[row][column].y = row;
	poi[row][column].px = column;
	poi[row][column].py = row;
	poi[row][column].dis = 0;
	poi[row][column].flag = 1;

	a.push(poi[row][column]);

	while (!a.empty())//ȷ�����ڵ����
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

	b.push(poi[11][69]);//����

	while (!b.empty())//��¼·�����Ӻ���ǰ
	{
		Poi t = b.top();
		c.push(t);//�ߵ�˳��
		b.pop();
		if (t.px == column&&t.py == row) break;
		short h = t.py;
		short l = t.px;
		b.push(poi[h][l]);
	}

	while (!c.empty())//�ƶ�
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
}//�Զ�Ѱ·

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
		printf("����ʧ��");
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
}//����

void load(void)
{
	FILE *fp;
	fp = fopen("save.txt", "r");
	if (fp == NULL)
	{
		gotoxy(0, 23);
		printf("����ʧ��");
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
}//����

void npc1(void)
{
	short hang = 0;
	char ch = 0;
	gotoxy(0, 22);
	printf("�÷죺�����и��ֻ��ף���Ҫ������ %c\n%c ������δʵ�֣�\n  �뿪", 31, 16);
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
	printf("�÷죺������ö��˶������ˣ���������Ҳ�������ˣ�           \n                    \n                   ");
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
		printf("����ˣ�����ö��˶������ˣ������ҵ��ϰ顣���ܰ��������� %c\n%c �ã��Ұ������Ұɡ�\n  ���ˣ��һ����¡�", 31, 16);
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
			printf("����ˣ����һ����������˰ɡ�                                  \n                    \n                   ");
			gotoxy(14, 0);
			Sleep(2000);
			gotoxy(0, 22);
			printf("                             ");
		}
		else if (hang == 0)
		{
			player.quest = 1;
			printf("����ˣ�����ȥ�������һ��ɽ�������Ҳû�������ˣ�               \n                    \n                   ");
			gotoxy(14, 0);
			Sleep(2000);
			gotoxy(0, 22);
			printf("��ӵ�һ������ȥɽ��Ѱ��ʧ�ٵ����ǡ�             ");
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
		printf("����ˣ���ȥɽ���Ⱦ����ǰɡ�лл�ˣ�׳ʿ��");
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
	printf("�����������и�����������Ҫ������ %c\n%c ������δʵ�֣�\n  �뿪", 31, 16);
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
	printf("������������ö��˶������ˣ���������Ҳ�������ˣ�           \n                    \n                   ");
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
	printf("ҩʦ�������и���ҩƷ����Ҫ������ %c\n%c ������δʵ�֣�\n  �뿪", 31, 16);
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
	printf("ҩʦ��������ö��˶������ˣ���������Ҳ�������ˣ�           \n                    \n                   ");
	gotoxy(14, 0);
	Sleep(2000);
	gotoxy(0, 22);
	printf("                                                          ");
	gotoxy(14, 0);
}//npc4