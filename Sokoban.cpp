#include <iostream>
#include <conio.h>

#include "Menu.h"
#include "Levels.h"
#include "Movement.h"

extern int realrows, realcols;

extern int movehistory[];
extern int masznach_x[razmaszh];
extern int mas[rows][cols];

extern char lvl1[];
extern char lvl2[];
extern char lvl3[];
extern char lvl4[];
extern char lvl5[];

extern char name_player_lvl[];

int main()
{
	system("chcp 1251 > nul");

	openfilelvl(lvl1, "test.txt");
	openfilelvl(lvl2, "lvl2.txt");
	openfilelvl(lvl3, "lvl3.txt");
	openfilelvl(lvl4, "lvl4.txt");
	openfilelvl(lvl5, "lvl5.txt");

	int repeat_game = 1;
	do
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				mas[i][j] = 0;

		bool start_game = 1;

		clear_history(movehistory);

		char fullstr[char_size]{};

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
			for (int i = 0; i < 1000; i++)
				fullstr[i] = lvl1[i];
			break;

		case 2:
			for (int i = 0; i < 1000; i++)
				fullstr[i] = lvl2[i];
			break;

		case 3:
			for (int i = 0; i < 1000; i++)
				fullstr[i] = lvl3[i];
			break;

		case 4:
			for (int i = 0; i < 1000; i++)
				fullstr[i] = lvl4[i];
			break;

		case 5:
			for (int i = 0; i < 1000; i++)
				fullstr[i] = lvl5[i];
			break;

			// уровень игрока.
		case 6:
			 
			if (player_lvl(fullstr) == 1)
			{
				start_game = 0;
				repeat_game = 2;
			}
			
			break;

		default:
			printf("\nerror: switch(level) in main()\n");
			system("pause");
			system("cls");
			break;
		}

		find_rows_cols(fullstr);
		filmas(fullstr);

		if (start_game == 1)
		{
			int dir = 0;

			while (!win_check())
			{
				system("cls");
				displaymatrix();

				//for (int i = 0; movehistory[i]; i++)
					//printf("%i", movehistory[i]);

				dir = get_player_input();
				move_player(dir, fullstr);
			}
			system("cls");
			displaymatrix();
			repeat_game = ending();

		}

	} while (repeat_game != 0);

	return 0;
}
