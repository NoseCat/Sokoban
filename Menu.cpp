#include <iostream>
#include <conio.h>

//������� ������ ��������.
const int max_lvl = 3;

//���� ������.
enum keyboard_kod { UP_KEY = 0x48, DOWN_KEY = 0x50, LEFT_KEY = 0x4B, RIGHT_KEY = 0x4D, SPACE = 32, ENTER = 13 };
int  key_code;

int level_choice();
int opening(int lvl);
int ending();


// ��������� ��������� ������ ������ � ���������� ����� ���������� ������. ���� ���������� 0, �� ���� ������� Exit.
int menu()
{
	bool repeat;
	do
	{
		repeat = 0;
		int menu_choice = 1, level;
		system("cls");
		printf("\tSocoban\n\n");
		printf(">> Start game\nExit\n\npress enter or spacebar to continue");

		do
		{
			key_code = _getch();
			switch (key_code)
			{
			case 0x48:
			case 'W':
			case 'w':
			case '�':
			case '�':
				system("cls");
				printf("\tSocoban\n\n");
				printf(">> Start game\nExit\n\npress enter or spacebar to continue");
				menu_choice = 1;
				break;

			case 0x50:
			case 'S':
			case 's':
			case '�':
			case '�':
				system("cls");
				printf("\tSocoban\n\n");
				printf("Start game\n>> Exit\n\npress enter or spacebar to continue");
				menu_choice = 2;
				break;

			default:
				break;
			}
		} while (key_code != ENTER and key_code != SPACE);

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
			else return level;
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

	return 0;// ��������. ���� �� � ������, �������� �������������� �� ���� ������� ����.
}