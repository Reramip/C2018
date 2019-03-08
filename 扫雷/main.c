#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ALL 10

void gotoxy(short x, short y);//指定位置显示指针
short search(short x, short y);

char show[ROW][COL+1];
_Bool mine[ROW + 2][COL + 2];

int main(void)
{
	short x, y, sx, sy;
	short minex, miney;
	short num = ROW*COL - ALL;
	short setmine = ALL;
	short judge;

	for (register int i = 0; i<ROW; i++)
	{
		for (register int j = 0; j<COL; j++)
		{
			show[i][j] = '#';
		}
		show[i][COL + 1] = '\0';
	}
	for (register int i = 0; i<ROW + 2; i++)
	{
		for (register int j = 0; j<COL + 2; j++)
		{
			mine[i][j] = 0;
		}
	}
	gotoxy(4, 2);
	printf("123456789");
	for (register int i = 0; i < 9; i++)
	{
		gotoxy(1, 4 + i);
		printf("%d", i + 1);
	}
	for (register int i = 0; i < 9; i++)
	{
		gotoxy(4, 4+i);
		puts(show[i]);
	}


	while (1)
	{
		gotoxy(0, 0);
		scanf("%hd%hd", &sx, &sy);
		y = sy - 1;
		x = sx - 1;
		gotoxy(0, 0);
		printf("          ");
		if (x > -1 && x<9 && y>-1 && y < 9) break;
	}
	srand((unsigned int)time(NULL));
	while (setmine)
	{
		minex = rand() % (COL-1) + 1;
		miney = rand() % (ROW-1) + 1;
		if (mine[minex][miney] == 0 && minex != x&&minex != y)
		{
			mine[minex][miney] = 1;
			setmine--;
		}
	}
	judge = search(x, y);
	gotoxy(4 + y, 4 + x);
	printf("%d",judge);


	while (num)
	{
		gotoxy(0, 0);
		scanf("%hd%hd", &sx, &sy);
		y = sy - 1;
		x = sx - 1;
		if (x > -1 && x<9 && y>-1 && y < 9)
		{
			judge = search(x, y);
			if (judge == -1)
			{
				gotoxy(5, 1);
				printf("GAME OVER");
				system("pause>nul echo");
				return 0;
			}
			gotoxy(4 + y, 4 + x);
			printf("%d", judge);
			num--;
		}
		gotoxy(0, 0);
		printf("          ");
	}
	gotoxy(5, 1); 
	printf("Congratulations!\n");

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

short search(short x, short y)
{
	short lei = 0;
	if (mine[x][y] == 1) return -1;
	if (mine[x - 1][y - 1] == 1) lei++;
	if (mine[x - 1][y] == 1) lei++;
	if (mine[x - 1][y + 1] == 1) lei++;
	if (mine[x][y - 1] == 1) lei++;
	if (mine[x][y] == 1) lei++;
	if (mine[x][y + 1] == 1) lei++;
	if (mine[x + 1][y - 1] == 1) lei++;
	if (mine[x + 1][y] == 1) lei++;
	if (mine[x + 1][y + 1] == 1) lei++;
	return lei;
}