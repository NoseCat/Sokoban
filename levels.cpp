#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <string.h>

#include "Enums.h"

int** mas;
int* masznach_x;

int targets;
int znach_x = 3;
int realrows = rows, realcols = cols;

// Теперь возвращает: 0 - файл открылся, 1 - не получилось открыть файл.
bool openfilelvl(char* fullstr, const char lvl_name[])
{
	FILE* level;
	char str[100];

	if (fopen_s(&level, lvl_name, "rt") != 0)
		return 1;
	while (fgets(str, 100, level))
		strcat(fullstr, str);
	fclose(level);

	return 0;
}
void find_rows_cols(char* fullstr)
{
	realrows = 1;
	realcols = 0;
	int leg = 0;
	int n = strlen(fullstr);

	for (int i = 0; i < n; i++)
	{
		leg++;
		if (fullstr[i] == '\n')
		{
			realcols = fmax(realcols, leg);
			realrows++;
			leg = 0;
		}
	}
}
void filmas(char str[])
{
	targets = 0;
	int counterstr = -1;
	masznach_x = (int*)malloc(razmaszh * sizeof(int)); //16 * 3 * 4 = 192 байта
	for (int i = 0; i < razmaszh; i++)
		masznach_x[i] = -1;

	int mas_x = 0;
	for (int i = 0; i < realrows; i++)
	{
		bool flag = false;
		for (int j = 0; j < realcols; j++)
		{
			counterstr++;
			switch (str[counterstr])
			{
			case '#':
				mas[i][j] = WALL;
				break;
			case '.':
			case ' ':
				mas[i][j] = EMPTY;
				break;
			case '@':
				mas[i][j] = PLAYER;
				break;
			case 'w':
				mas[i][j] = WHITEBOX;
				break;
			case 'r':
				mas[i][j] = REDBOX;
				break;
			case 'g':
				mas[i][j] = GREENBOX;
				break;
			case 'b':
				mas[i][j] = BLUEBOX;
				break;
			case 'W':
			case 'X':
			case 'R':
			case 'G':
			case 'B':
				switch (str[counterstr])
				{
				case 'W':
				case 'X':
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
				targets++;
				mas[i][j] = EMPTY;

				break;
			case'\n':

				//mas[i][j] = NEXTROWS;
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
	for (int i = 0; i < realrows; i++)
	{
		for (int j = 0; j < realcols; j++)
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
						color_x = masznach_x[k + 2];
						fulage = true;
						break;
					}
				}
				if (fulage)
				{
					SetConsoleTextAttribute(hwnd, color_x);
					printf("X");
					SetConsoleTextAttribute(hwnd, white);
				
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
			//case NEXTROWS: //?
				//printf("\n");
				//break;
			}
		}
		printf("\n");
	}
	
}