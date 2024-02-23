#include <iostream>
#include <conio.h>

#include "Menu.h"
#include "Levels.h"
#include "Movement.h"

extern int movehistory[];

int main()
{
	system("chcp 1251 > nul");

	int level = menu();

	char fullstr[1000]{};

	openfilelvl(fullstr);

	filmas(fullstr);

	int dir = 0;

	//while (win_check())
	while (true)
	{
		system("cls");
		displaymatrix();
		
		for (int i = 0; movehistory[i]; i++)
			printf("%i", movehistory[i]);

		dir = get_player_input();
		move_player(dir, fullstr);
	}

	return 0;
}
