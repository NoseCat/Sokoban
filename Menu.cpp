#include <iostream>
#include <conio.h>

//счётчик файлов добавить.
const int max_lvl = 3;

//коды кнопок.
enum keyboard_kod { UP_KEY = 0x48, DOWN_KEY = 0x50, LEFT_KEY = 0x4B, RIGHT_KEY = 0x4D, SPACE = 32, ENTER = 13};

int level_choice();
int opening(int lvl);
int ending();


//Заменить все циферки на буковки (слова) (сделать свой enum)

//По задумке основная функция с которой запускается игра и в которой она проходит. 
int menu()
{
	bool repeat;
	do
	{
		repeat = 0;
		int menu_code, menu_choice = 1, level;
		system("cls");
		printf("\tSocoban\n\n");
		printf(">> Start game\nExit\n\npress enter or spacebar to continue");

		do
		{
			menu_code = _getch();
			switch (menu_code)
			{
			case 0x48:
			case 'W':
			case 'w':
			case 'Ц':
			case 'ц':
				system("cls");
				printf("\tSocoban\n\n");
				printf(">> Start game\nExit\n\npress enter or spacebar to continue");
				menu_choice = 1;
				break;

			case 0x50:
			case 'S':
			case 's':
			case 'Ы':
			case 'ы':
				system("cls");
				printf("\tSocoban\n\n");
				printf("Start game\n>> Exit\n\npress enter or spacebar to continue");
				menu_choice = 2;
				break;

			default:
				break;
			}
		} while (menu_code != ENTER and menu_code != SPACE);

		// 1.Start 2.Exit
		switch (menu_choice)
		{
		case 1:
			level = level_choice();
			if (level == 0)
			{
				system("cls");
				repeat = 1;
			}
			opening(level);
			break;

		case 2:
			return 0;

		default:
			system("cls");
			printf("error: menu's switch.");
			break;
		}
	} while (repeat == 1);

	return 0;
}

//интерфейс выбора уровня и возможный его предпоказ.
int level_choice()
{
	system("cls");

	printf("Level 1\n\n#######\n#.....#\n#..@..###\n#.......#\n#...B...#\n#.......#\n###..X..#\n  #.....#\n  #######\n\npress enter or spacebar to continue");

	int lvl_choice = 1, lvl_code;

	do
	{
		lvl_code = _getch();
		switch (lvl_code)
		{
		case 0x4B:
		case 'A':
		case 'a':
		case 'Ф':
		case 'ф':
			system("cls");

			//printf(" left ");

			if (lvl_choice > 0)
				lvl_choice -= 1;
			break;

		case 0x4D:
		case 'D':
		case 'd':
		case 'В':
		case 'в':
			system("cls");

			//printf(" right ");

			if (lvl_choice < max_lvl)
				lvl_choice += 1;
			break;
		}

		switch (lvl_choice)
		{
		case 0:
			system("cls");
			printf("Back to Menu\n __________\n|   Scbn   |\n|>Strt     |\n|Ext_______|\n\npress enter or spacebar to continue");
			break;
		case 1:
			system("cls");
			printf("Level 1\n\n#######\n#.....#\n#..@..###\n#.......#\n#...B...#\n#.......#\n###..X..#\n  #.....#\n  #######\n\npress enter or spacebar to continue");
			break;

		case 2:
			system("cls");
			printf("Level 2\n\n#######\n#.....#\n#..@..###\n#.......#\n#...[]..#\n#.......#\n###..X..#\n  #.....#\n  #######\n\npress enter or spacebar to continue");
			break;
		}
	} while (lvl_code != ENTER and lvl_code != SPACE);


	switch (lvl_choice)
	{
	case 0:
		return 0; break;

	case 1:
		return 1; break;

	case 2:
		return 2; break;
	}

}

//принимает на вход выбраный уровень и запускает его.
int opening(int lvl)
{
	switch (lvl)
	{
		//menu
	case 0: return 0;
	}
}

//уведомляет об окончании игры и выводит результат с выбором действий.
int ending()
{

	return 0;// ЗАГЛУШКА. Если вы её видите, сообщите ответственному за этот участок кода.
}

/*int main()
{

	menu();

	return 0;
}*/