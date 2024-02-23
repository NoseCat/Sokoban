#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

enum objects { EMPTY = 1, WALL, PLAYER, BOX, FINISH, NEXTROWS};

enum sizes { rows = 20, cols = 20 };

//const int cols = 20, rows = 20;
int mas[rows][cols];

void openfilelvl(char* fullstr)
{
	FILE* level;
	char str[100];

	fopen_s(&level, "test.txt", "rt");
		while (fgets(str, 100, level))
			strcat(fullstr, str);
		fclose(level);
}

void filmas(char str[])
{
	int counterstr = -1;
	for (int i = 0; i < rows; i++)
	{
		bool flag = false;
		for (int j = 0; j < cols; j++)
		{
			counterstr++;
			if (str[counterstr] == '#')
				mas[i][j] = WALL;
			else if (str[counterstr] == '.' or str[counterstr] == ' ')
				mas[i][j] = EMPTY;
			else if (str[counterstr] == '@')
				mas[i][j] = PLAYER;
			else if (str[counterstr] == 'B')
				mas[i][j] = BOX;
			else if (str[counterstr] == 'X')
				mas[i][j] = FINISH;
			else if (str[counterstr] == '\n')
			{
				mas[i][j] = NEXTROWS;
				flag = true;
				break;
			}
		}
		if (!flag)
			break;
	}
}

void displaymatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
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
				printf("\n");
		}
	}
}

/*char fullstr[1000]{};
openfilelvl(str);*/