#include <iostream>
#include <conio.h>

#include "Menu.h"
#include "Levels.h"
#include "Movement.h"

int main()
{
	system("chcp 1251 > nul");

	char fullstr[1000]{};
	openfilelvl(fullstr);

	int dir = 0;

	//while (win_check())
	while (true)
	{
		system("cls");
		displaymatrix();

		dir = get_player_input();
		move_player(dir);
	}

	return 0;
}
