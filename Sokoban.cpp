#include <iostream>
#include <conio.h>

#include "Menu.h"
#include "Movement.h"

extern Matrix[]

int main()
{
	system("chcp 1251 > 0");
	while (win_check())
	{
		display();

		dir = get_player_input();
		move_player(dir);
	}
}
