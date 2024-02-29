#include <iostream>
#include <conio.h>

#include "Menu.h"
#include "Levels.h"
#include "Movement.h"

extern int movehistory[];
extern int masznach_x[razmaszh];
extern int mas[rows][cols];

int main()
{
	system("chcp 1251 > nul");

	char lvl1[1000]{};
	char lvl2[1000]{};
	char lvl3[1000]{};
	openfilelvl(lvl1, "test.txt");
	openfilelvl(lvl2, "lvl1.txt");
	openfilelvl(lvl3, "lvl2.txt");
	int lvl1_mass[rows][cols];
	int lvl2_mass[rows][cols];
	int lvl3_mass[rows][cols];
	filmas(lvl1, lvl1_mass);
	filmas(lvl2, lvl2_mass);
	filmas(lvl3, lvl3_mass);

	int repeat_game = 1;
	do
	{
		for (int i = 0; i < MAXARRAYLENGTH; i++)
			movehistory[i] = 0;

		char fullstr[1000]{};

		int level;
		switch (repeat_game)
		{
		case 1:
			level = menu(0);
			break;

		case 2:
			level = menu(1);
			break;

		case 3:
			return 0; break;
			
		default:
			system("cls");
			printf("error: switch(repeat_game) in menu()\n");
			system("pause");
			break;
		}

		switch (level)
		{
		case 1:
			//filmas(lvl1);
			for (int i = 0; i < 1000; i++)
				fullstr[i] = lvl1[i];
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					mas[i][j] = lvl1_mass[i][j];
			break;
		case 2:
			//filmas(lvl2);
			for (int i = 0; i < 1000; i++)
				fullstr[i] = lvl2[i];
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					mas[i][j] = lvl2_mass[i][j];
			break;
		case 3:
			//filmas(lvl2);
			for (int i = 0; i < 1000; i++)
				fullstr[i] = lvl3[i];
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					mas[i][j] = lvl3_mass[i][j];
			break;
		default:
			printf("\nerror: switch(level) in main()\n");
			system("pause");
			system("cls");
			break;
		}

		int dir = 0;

		while (!win_check())
		{
			system("cls");
			displaymatrix();

			for (int i = 0; movehistory[i]; i++)
				printf("%i", movehistory[i]);

			dir = get_player_input();
			move_player(dir, fullstr);
		}
		system("cls");
		displaymatrix();
		repeat_game = ending();

	} while (repeat_game != 0);
	return 0;
}
