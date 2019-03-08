#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>


void gotoxy(short x, short y);//指定位置显示指针
void printnum(void);
void setnum(void);
void move(void);
void up(void);
void down(void);
void left(void);
void right(void);

int num[4][4] = { 0 };
char map[4][5];

short hang = 0;
short lie = 0;

int main(void)
{
	setnum();
	printnum();
	while (1)
	{
		move();
		setnum();
		printnum();
	}

	system("pause>nul echo");
	return 0;
}

void gotoxy(short x, short y)//指定位置显示指针
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}//指定位置显示指针

void printnum(void)
{
	system("cls");
	for (register int i = 0; i < 4; i++)
	{
		for (register int j = 0; j < 4; j++)
		{
			gotoxy(5 + j * 5, 5 + i * 5);
			printf("%d", num[i][j]);
		}
	}
	gotoxy(0, 0);
}

void setnum(void)
{
	srand((unsigned int)time(NULL));
	for (register int i = 0; i < 4; i++)
	{
		for (register int j = 0; j < 4; j++)
		{
			if (num[i][j] == 0)
			{
				while (1)
				{
					hang = rand() % 4;
					lie = rand() % 4;
					if (num[hang][lie] == 0) break;
				}	
				num[hang][lie] = 2 * (rand() % 2 + 1);
				goto stop;
			}
		}
	}
stop:;
}

void move(void)
{
	char ch = getch();
	switch (ch)
	{
	case 72:up(); break;
	case 80:down(); break;
	case 75:left(); break;
	case 77:right(); break;
	default:break;
	}
}

void up(void)
{
	for (register int i = 0; i < 4; i++)
	{
		for (register int j = 0; j < 3; j++)
		{
			if (num[j][i] == num[j + 1][i] || num[j][i] == 0)
			{
				num[j][i] += num[j + 1][i];
				num[j + 1][i] = 0;
			}
		}
		for (register int j = 1; j < 3; j++)
		{
			if (num[j][i] == num[j + 1][i] || num[j][i] == 0)
			{
				num[j][i] += num[j + 1][i];
				num[j + 1][i] = 0;
			}
		}
		for (register int j = 2; j < 3; j++)
		{
			if (num[j][i] == num[j + 1][i] || num[j][i] == 0)
			{
				num[j][i] += num[j + 1][i];
				num[j + 1][i] = 0;
			}
		}
	}
}
void down(void)
{
	for (register int i = 0; i < 4; i++)
	{
		for (register int j = 3; j > 0; j--)
		{
			if (num[j][i] == num[j - 1][i] || num[j][i] == 0)
			{
				num[j][i] += num[j - 1][i];
				num[j - 1][i] = 0;
			}
		}
		for (register int j = 2; j > 0; j--)
		{
			if (num[j][i] == num[j - 1][i] || num[j][i] == 0)
			{
				num[j][i] += num[j - 1][i];
				num[j - 1][i] = 0;
			}
		}
		for (register int j = 1; j > 0; j--)
		{
			if (num[j][i] == num[j - 1][i] || num[j][i] == 0)
			{
				num[j][i] += num[j - 1][i];
				num[j - 1][i] = 0;
			}
		}
	}
}
void left(void)
{
	for (register int i = 0; i < 4; i++)
	{
		for (register int j = 0; j < 3; j++)
		{
			if (num[i][j] == num[i][j + 1] || num[i][j] == 0)
			{
				num[i][j] += num[i][j + 1];
				num[i][j + 1] = 0;
			}
		}
		for (register int j = 1; j < 3; j++)
		{
			if (num[i][j] == num[i][j + 1] || num[i][j] == 0)
			{
				num[i][j] += num[i][j + 1];
				num[i][j + 1] = 0;
			}
		}
		for (register int j = 2; j < 3; j++)
		{
			if (num[i][j] == num[i][j + 1] || num[i][j] == 0)
			{
				num[i][j] += num[i][j + 1];
				num[i][j + 1] = 0;
			}
		}
	}
}
void right(void)
{
	for (register int i = 0; i < 4; i++)
	{
		for (register int j = 3; j > 0; j--)
		{
			if (num[i][j] == num[i][j - 1] || num[i][j] == 0)
			{
				num[i][j] += num[i][j - 1];
				num[i][j - 1] = 0;
			}
		}
		for (register int j = 2; j > 0; j--)
		{
			if (num[i][j] == num[i][j - 1] || num[i][j] == 0)
			{
				num[i][j] += num[i][j - 1];
				num[i][j - 1] = 0;
			}
		}
		for (register int j = 1; j > 0; j--)
		{
			if (num[i][j] == num[i][j - 1] || num[i][j] == 0)
			{
				num[i][j] += num[i][j - 1];
				num[i][j - 1] = 0;
			}
		}
	}
}