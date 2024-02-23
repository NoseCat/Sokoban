#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include < fstream >
#include < vector >
using namespace std;

//ВСЕ ЦИФРЫ ЗАМЕНИТЬ НА КОНСТАНТЫ!!!!!
//enum objects { EMPTY, WALL, PLAYER, BOX, FINISH, NEXTROWS};
const int cols = 20, rows = 20;
void openfilelvl(char* str)
{
	printf("введите номер уровня  ");
	int choice;
	FILE* ft;
	char st[100];
	scanf("%d", &choice);
	switch (choice)
	{
	case 0:
		ft = fopen("test.txt", "rt");

		while (fgets(st, 100, ft))
			strcat(str, st);
		fclose(ft);
		//cout << str << endl << endl;
		break;
	case 1:

		ft = fopen("lvl1.txt", "rt");

		while (fgets(st, 100, ft))
			strcat(str, st);
		fclose(ft);
		break;
	case 2:

		ft = fopen("lvl2.txt", "rt");

		while (fgets(st, 100, ft))
			strcat(str, st);
		fclose(ft);
		break;
	default:
		printf("уровень не найден");


	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	char str[1000]{};
	openfilelvl(str);


	
	
	int counterstr = -1;
	for (int i = 0; i < cols; i++)
	{
		bool flag = false;
		for (int j = 0; j < rows; j++)
		{
			counterstr++;
			if (str[counterstr] == '#')
				mas[i][j] = WALL;
			else if (str[counterstr] == '.' or str[counterstr] == 32)
				mas[i][j] = EMPTY;
			else if (str[counterstr] == '@')
				mas[i][j] = PLAYER;
			else if (str[counterstr] == 'B')
				mas[i][j] = BOX;
			else if (str[counterstr] == 'X')
				mas[i][j] = FINISH;
			else if (str[counterstr] == 'n')
			{
				mas[i][j] = NEXTROWS;
				flag = true;
				break;
			}

		}
		if (!flag)
			break;
	}

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			/* switch (numbar)
			{
			case 1:
				do whateever;
				break;
			default:
				do default;
			}*/
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