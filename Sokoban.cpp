#include <iostream>
#include <conio.h>

#include "Menu.h"
#include "Levels.h"
#include "Movement.h"
#include "Enums.h"

extern int realrows, realcols;
extern int moves;
extern int* movehistory;
extern int* masznach_x;
extern int** mas;

char* fullstr;
extern char* lvl1;
extern char* lvl2;
extern char* lvl3;
extern char* lvl4;
extern char* lvl5;

int main()
{
	system("chcp 1251 > nul");
	lvl1 = (char*)malloc(char_size * sizeof(char)); //4096 * 1 = 4 кб
	lvl2 = (char*)malloc(char_size * sizeof(char)); //4096 * 1 = 4 кб
	lvl3 = (char*)malloc(char_size * sizeof(char)); //4096 * 1 = 4 кб
	lvl4 = (char*)malloc(char_size * sizeof(char)); //4096 * 1 = 4 кб
	lvl5 = (char*)malloc(char_size * sizeof(char)); //4096 * 1 = 4 кб
	for (int i = 0; i < char_size; i++)
	{
		lvl1[i] = 0;
		lvl2[i] = 0;
		lvl3[i] = 0;
		lvl4[i] = 0;
		lvl5[i] = 0;
	}
	openfilelvl(lvl1, "lvl1.txt");
	openfilelvl(lvl2, "lvl2.txt");
	openfilelvl(lvl3, "lvl3.txt");
	openfilelvl(lvl4, "lvl4.txt");
	openfilelvl(lvl5, "lvl5.txt");

	int repeat_game = 1;
	do
	{
		int level;
		bool start_game = 1;
		fullstr = (char*)malloc(char_size * sizeof(char)); //4096 * 1 = 4 кб
		for(int i =0; i < char_size; i++)
			fullstr[i] = 0;

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
		mas = (int**)malloc(realrows * sizeof(int*)); // макс: 64*64*4 + 64*4(?) = 16 + 0,25 кб
		for (int i = 0; i < realrows; i++)
		{
			mas[i] = (int*)malloc(realcols * sizeof(int));
		}
		/*for (int i = 0; i < realrows; i++)
			for (int j = 0; j < realcols; j++)
				mas[i][j] = EMPTY;*/
		filmas(fullstr);
		movehistory = (int*)malloc(MAXHISTSIZE * sizeof(int)); //1024 * 4 = 4 кб
		clear_history(movehistory);

		if (start_game == 1)
		{
			int dir = 0;
			moves = 0;
			while (!win_check())
			{
				system("cls");
				displaymatrix();

				/*for (int i = 0; movehistory[i]; i++)
					printf("%i", movehistory[i]);*/

				dir = get_player_input();
				move_player(dir);
			}
			free(movehistory);
			free(masznach_x);

			repeat_game = ending();

		}
		for (int i = 0; i < realrows; i++)
			free(mas[i]);
		free(mas);
	} while (repeat_game != 0);

	free(lvl1);
	free(lvl2);
	free(lvl3);
	free(lvl4);
	free(lvl5);
	free(fullstr);
	return 0;
}
