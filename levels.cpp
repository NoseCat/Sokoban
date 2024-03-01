#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <string.h>

enum objects { EMPTY = 1, WALL, PLAYER, WHITEBOX, REDBOX, GREENBOX, BLUEBOX, FINISH, NEXTROWS };
enum color { white = 7,red=12,green=10,blue=9 };
enum maxsizes { rows = 64, cols = 64, razmaszh = 16 *3};
//максимальное количество крестов на поле = razmaszh / 3

//const int cols = 20, rows = 20;
int mas[rows][cols];
int znach_x = 3;
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
			case 'w':
				mass[i][j] = WHITEBOX;
				break;
			case 'r':
				mass[i][j] = REDBOX;
				break;
			case 'g':
				mass[i][j] = GREENBOX;
				break;
			case 'b':
				mass[i][j] = BLUEBOX;
				break;
			case 'W':
			case 'R':
			case 'G':
			case 'B':
				switch (str[counterstr])
				{
				case 'W':
					masznach_x[mas_x + 2] = white;
					break;
				case 'R':
					masznach_x[mas_x + 2] = red;
					break;
				case 'G':
					masznach_x[mas_x + 2] = green;
					break;
				case 'B':
					masznach_x[mas_x + 2] = blue;
					break;
				}
				masznach_x[mas_x] = i;
				masznach_x[mas_x + 1] = j;
				
				mas_x += znach_x;
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
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	bool fulage;
	int color_x = 2;
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
				for (int k = 0; k < razmaszh - 2; k += znach_x)
				{
					if (0 == masznach_x[k] and 0 == masznach_x[k + 1])
						break;
					if (i == masznach_x[k] and j == masznach_x[k + 1])
					{
						fulage = true;

					}
				}
				if (fulage)
				{
					SetConsoleTextAttribute(hwnd, masznach_x[color_x]);
					printf("X");
					SetConsoleTextAttribute(hwnd, white);
					color_x += znach_x;
				}
				else
					printf(" ");
				break;
			case PLAYER:
				printf("@");
				break;
			case WHITEBOX:
				
				printf("B");
				break;
			case REDBOX:
				SetConsoleTextAttribute(hwnd, red);
				printf("B");
				SetConsoleTextAttribute(hwnd, white);
				break;
			case GREENBOX:
				SetConsoleTextAttribute(hwnd, green);
				printf("B");
				SetConsoleTextAttribute(hwnd, white);
				break;
			case BLUEBOX:
				SetConsoleTextAttribute(hwnd, blue);
				printf("B");
				SetConsoleTextAttribute(hwnd, white);
				break;
			case FINISH:
				printf("X");

				break;
			case NEXTROWS:
				printf("\n");
				break;
			}
		}
	}
	
}