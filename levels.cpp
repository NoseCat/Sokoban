#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include < fstream >
#include < vector >
using namespace std;
void openfilelvl(char* str)
{
	printf("введите номер уровня");
	int choice;
	bool flag;

	do {
		flag = false;
		scanf("%d", &choice);
		if (choice == 0)
		{
			ifstream f("test.txt");

			char st[100];
			char nochka[2] = "n";
			while (f.getline(st, 100))
			{
				strcat(str, st);
				strcat(str, nochka);
			}
			//cout << str << endl << endl;
			f.close();
		}
		else if (choice == 1)
		{
			ifstream f("lvl1.txt");

			char st[100];
			char nochka[2] = "n";
			while (f.getline(st, 100))
			{
				strcat(str, st);
				strcat(str, nochka);
			}
			//cout << str << endl << endl;
			f.close();
		}
		else
		{
			printf("уровень не найден");
			flag = true;
		}
	} while (flag);

}
int main()
{
	setlocale(LC_ALL, "rus");
	char str[1000]{};
	openfilelvl(str);


	const int cols = 20, rows = 20;
	int mas[cols][rows] = {};
	int counterstr = -1;
	for (int i = 0; i < cols; i++)
	{
		bool flag = false;
		for (int j = 0; j < rows; j++)
		{
			counterstr++;
			if (str[counterstr] == '#')
				mas[i][j] = 1;
			else if (str[counterstr] == '.' or str[counterstr] == 32)
				mas[i][j] = 2;
			else if (str[counterstr] == '@')
				mas[i][j] = 3;
			else if (str[counterstr] == 'B')
				mas[i][j] = 4;
			else if (str[counterstr] == 'X')
				mas[i][j] = 5;
			else if (str[counterstr] == 'n')
			{
				mas[i][j] = 7;
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
			if (mas[i][j] == 1)
				printf("#");
			else if (mas[i][j] == 2)
				printf(" ");
			else if (mas[i][j] == 3)
				printf("@");
			else if (mas[i][j] == 4)
				printf("B");
			else if (mas[i][j] == 5)
				printf("X");
			else if (mas[i][j] == 7)
				printf("\n");
		}
	}
}