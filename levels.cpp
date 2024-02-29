#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

enum objects { EMPTY = 1, WALL, PLAYER, BOX, FINISH, NEXTROWS };

enum sizes { rows = 20, cols = 20, razmaszh = 100 };

//const int cols = 20, rows = 20;
int mas[rows][cols];

int masznach_x[razmaszh];
void openfilelvl(char* fullstr, const char lvl_name[])
{
	FILE* level;
	char str[100];

	if (fopen_s(&level, lvl_name, "rt") != 0)
		system("pause");
	while (fgets(str, 100, level))
		strcat(fullstr, str);
	fclose(level);
}

void filmas(char str[], int mass[][cols])
{
	int counterstr = -1;
	for (int i = 0; i < razmaszh; i++)
		masznach_x[i] = 0;
	int mas_x = 0;
	for (int i = 0; i < rows; i++)
	{
		bool flag = false;
		for (int j = 0; j < cols; j++)
		{
			counterstr++;
			switch (str[counterstr])
			{
			case '#':
				mass[i][j] = WALL;
				break;
			case '.':
			case ' ':
				mass[i][j] = EMPTY;
				break;
			case '@':
				mass[i][j] = PLAYER;
				break;
			case 'B':
				mass[i][j] = BOX;
				break;
			case 'X':
				masznach_x[mas_x] = i;
				masznach_x[mas_x + 1] = j;
				mas_x += 2;
				mass[i][j] = EMPTY;

				break;
			case'\n':

				mass[i][j] = NEXTROWS;
				flag = true;

			default:
				break;
			}
			if (flag)
				break;
		}
		if (!flag)
			break;
	}
}

void displaymatrix()
{
	bool fulage;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			switch (mas[i][j])
			{
			case WALL:
				printf("#");
				break;
			case EMPTY:
				fulage = false;
				for (int k = 0; k < razmaszh - 1; k += 2)
				{
					if (0 == masznach_x[k] and 0 == masznach_x[k + 1])
						break;
					if (i == masznach_x[k] and j == masznach_x[k + 1])
						fulage = true;
				}
				if (fulage)
					printf("X");
				else
					printf(" ");
				break;
			case PLAYER:
				printf("@");
				break;
			case BOX:
				printf("B");
				break;
			case FINISH:
				printf("X");
				break;
			case NEXTROWS:
				printf("\n");
				break;
			}
			/*
			if (mas[i][j] == WALL)
				printf("#");
			else if (mas[i][j] == EMPTY)
				printf(" ");
			else if (mas[i][j] == PLAYER)
				printf("@");
			else if (mas[i][j] == BOX)
				printf("B");
			else if (mas[i][j] == FINISH)
				printf("X");
			else if (mas[i][j] == NEXTROWS)
				printf("\n");*/
		}
	}
}

/*char fullstr[1000]{};
openfilelvl(str);*/