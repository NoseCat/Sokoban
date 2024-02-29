#include <iostream>
#include <conio.h>

// �������������� �������� �������.
const int max_lvl = 3;

// ���� ������.
enum keyboard_kod { UP_KEY = 0x48, DOWN_KEY = 0x50, LEFT_KEY = 0x4B, RIGHT_KEY = 0x4D, SPACE = 32, ENTER = 13 };
// ����������, � ������� ������������ ��� �������.
int  key_code;

int level_choice();

// ��������� ��������� ������ ������ � ���������� ����� ���������� ������. ���� ���������� 0, �� ���� ������� Exit.
int menu(bool skip)
{
	//���������� ��� ��� ������ � ����.
	bool repeat;
	do
	{
		repeat = 0;

		//menu_choice - �������� ����� ����. level - ��������� level_choice(), ����� �������� ���������� ������.
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
				case '�':
				case '�':
					menu_choice = 1;
					break;

				case DOWN_KEY:
				case 'S':
				case 's':
				case '�':
				case '�':
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

		// ���� ������ Exit.
		if (menu_choice == 2) return 0;

		// ����� ���������� ������ ������.
		level = level_choice();
		if (level == 0) // ���� ������ ������� � ����
		{
			system("cls");
			repeat = 1;
		}
		else return level;

	} while (repeat == 1);

	return 0;
}

//��������� ������ ������ � ��������� ��� ���������.
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
		case '�':
		case '�':
			system("cls");

			//printf(" left ");

			if (lvl_choice > 0)
				lvl_choice -= 1;
			break;

		case 0x4D:
		case 'D':
		case 'd':
		case '�':
		case '�':
			system("cls");

			//printf(" right ");

			if (lvl_choice < max_lvl)
				lvl_choice += 1;
			break;
		}
	} while (key_code != ENTER and key_code != SPACE);


	return lvl_choice;
}

//���������� �� ��������� ���� � ������� ��������� � ������� ��������.
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
		case '�':
		case '�':
			if (ending_choice > 1)
				ending_choice--;
			break;

		case DOWN_KEY:
		case 'S':
		case 's':
		case '�':
		case '�':
			if (ending_choice < 3)
				ending_choice++;
			break;

		default:
			break;
		}
	} while (key_code != ENTER and key_code != SPACE);

	return ending_choice;
}