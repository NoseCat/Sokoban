#include <iostream>
#include <conio.h>

// предполагаемый максимум уровней.
const int max_lvl = 3;

// коды кнопок.
enum keyboard_kod { UP_KEY = 0x48, DOWN_KEY = 0x50, LEFT_KEY = 0x4B, RIGHT_KEY = 0x4D, SPACE = 32, ENTER = 13 };
// переменная, в которую записывается код клавиши.
int  key_code;

int level_choice();

// Запускает интерфейс выбора уровня и возвращает номер выбранного уровня. Если возвращает 0, то было выбрано Exit.
int menu(bool skip)
{
	//переменная для для выхода в меню.
	bool repeat;
	do
	{
		repeat = 0;

		//menu_choice - выбраный пункт меню. level - результат level_choice(), чтобы избежать повторного вызова.
		int menu_choice = 1, level;

		do
		{
			if (skip == 0)
			{
				// 1.Start 2.Exit
				switch (menu_choice)
				{
				case 1:
					system("cls");
					printf("\tSocoban\n\n");
					printf(">> Start game\nExit\n\npress enter or spacebar to continue");
					break;

				case 2:
					system("cls");
					printf("\tSocoban\n\n");
					printf("Start game\n>> Exit\n\npress enter or spacebar to continue");
					break;

				default:
					system("cls");
					printf("error: menu's switch.");
					break;
				}

				key_code = _getch();
				switch (key_code)
				{
				case UP_KEY:
				case 'W':
				case 'w':
				case 'Ц':
				case 'ц':
					menu_choice = 1;
					break;

				case DOWN_KEY:
				case 'S':
				case 's':
				case 'Ы':
				case 'ы':
					menu_choice = 2;
					break;

				default:
					break;
				}
			}
			else
			{
				skip = 0;
				key_code = ENTER;
			}
		} while (key_code != ENTER and key_code != SPACE);

		// если выбран Exit.
		if (menu_choice == 2) return 0;

		// вызов интерфейса выбора уровня.
		level = level_choice();
		if (level == 0) // если выбран возврат в меню
		{
			system("cls");
			repeat = 1;
		}
		else return level;

	} while (repeat == 1);

	return 0;
}

//интерфейс выбора уровня и возможный его предпоказ.
int level_choice()
{
	system("cls");

	int lvl_choice = 1;

	do
	{

		switch (lvl_choice)
		{
		case 0:
			system("cls");

			printf("Back to Menu\n __________\n|   Scbn   |\n|>Strt     |\n|Ext_______|\n\npress enter or spacebar to continue");
			break;
		case 1:
			system("cls");
			printf("Level 1\n\n");
			//openfilelvl(fullstr);
			printf("\n\npress enter or spacebar to continue");
			break;

		case 2:
			system("cls");
			printf("Level 2\n\n");
			//openfilelvl(fullstr);
			printf("\n\npress enter or spacebar to continue");
			break;

		case 3:
			system("cls");
			printf("Level 3\n\n");
			//openfilelvl(fullstr);
			printf("\n\npress enter or spacebar to continue");
			break;
		}

		key_code = _getch();

		switch (key_code)
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
	} while (key_code != ENTER and key_code != SPACE);


	return lvl_choice;
}

//уведомляет об окончании игры и выводит результат с выбором действий.
int ending()
{
	int ending_choice = 1;
	system("cls");
	do
	{
		switch (ending_choice)
		{
		case 1:
			system("cls");
			printf("\tLevel completed!\n\n>> Exit to main menu.\nSelect level.\nQuit the game.\n");
			break;

		case 2:
			system("cls");
			printf("\tLevel completed!\n\nExit to main menu.\n>> Select level.\nQuit the game.\n");
			break;

		case 3:
			system("cls");
			printf("\tLevel completed!\n\nExit to main menu.\nSelect level.\n>> Quit the game.\n");
			break;

		default:
			system("cls");
			printf("error: switch(ending_choice) in ending()\n");
			system("pause");
			break;
		}

		key_code = _getch();
		switch (key_code)
		{
		case UP_KEY:
		case 'W':
		case 'w':
		case 'Ц':
		case 'ц':
			if (ending_choice > 1)
				ending_choice--;
			break;

		case DOWN_KEY:
		case 'S':
		case 's':
		case 'Ы':
		case 'ы':
			if (ending_choice < 3)
				ending_choice++;
			break;

		default:
			break;
		}
	} while (key_code != ENTER and key_code != SPACE);

	return ending_choice;
}