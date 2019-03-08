#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

void gotoxy(short x, short y);//指定位置显示指针
void setfood(void);
void move(void);

typedef struct SNAKE
{
	short x, y;
}SNAKE;

char ch=RIGHT;
short len = 3;
short ex, ey;

char map[30][71];
SNAKE snake[2000];

int main(void)
{
	register int i, j;
	snake[0].x = 20;
	snake[0].y = 15;

	for (i = 0; i<30; i++)
	{
		for (j = 0; j<70; j++)
		{
			map[i][j] = ' ';
		}
	}
	for (i = 0; i<70; i++)
	{
		map[0][i] = '#';
		map[29][i] = '#';
	}
	for (i = 0; i<30; i++)
	{
		map[i][0] = '#';
		map[i][69] = '#';
		map[i][70] = '\0';
		puts(map[i]);
	}

	setfood();

	while (1)
	{
		move();
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

void setfood(void)
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		ex = rand() % 67 + 1;
		ey = rand() % 27 + 1;
		if (!(ex == 0 || ex == 69 || ey == 0 || ey == 19))
			break;
	}
	gotoxy(ex, ey);
	printf("X");
	gotoxy(71, 0);
}

void move(void)
{

	for (register int i = len - 1; i >0; i--)
	{
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
		gotoxy(snake[i].x, snake[i].y);
		printf("O");
		gotoxy(71, 0);
	}
	gotoxy(snake[len - 1].x, snake[len - 1].y);
	printf(" ");	
	gotoxy(71, 0);

	if(snake[0].x==ex&&snake[0].y==ey)
	{
		len++;
		setfood();
		gotoxy(snake[len - 1].x, snake[len - 1].y);
		printf("O");
		gotoxy(71, 0);
	}

	if (kbhit())
	{
		ch = getch();
	}

	switch (ch)
	{
	case UP:snake[0].y--; break;
	case DOWN:snake[0].y++; break;
	case LEFT:snake[0].x--; break;
	case RIGHT:snake[0].x++; break;
	default:break;
	}

	if (!(ex == 0 || ex == 69 || ey == 0 || ey == 19))
	{
		gotoxy(ex, ey);
		printf("X");
		gotoxy(71, 0);
	}

	if (snake[0].x == 0 || snake[0].x == 69 || snake[0].y == 0 || snake[0].y == 29)
	{
		gotoxy(73, 13);
		printf("GAME OVER");
		gotoxy(73, 15);
		printf("Length:%d", len - 2);
		system("pause>nul echo");
		exit(1);
	}
	for (register int i = 2; i < len - 2; i++)
	{
		if (snake[0].x == snake[i].x&&snake[0].y == snake[i].y)
		{
			gotoxy(73, 13);
			printf("GAME OVER");
			gotoxy(73, 15);
			printf("Length:%d", len - 2);
			system("pause>nul echo");
			exit(1);
		}
	}

	if(ch==LEFT||ch==RIGHT) Sleep(80);
	if (ch == UP || ch == DOWN) Sleep(150);
}