#include <iostream>
#include <conio.h>
#include "Levels.h"
#include "Movement.h"

// �������������� �������� �������.
const int max_lvl = 6;
// ����������� ���������� ������ �������� ������.
const int size_name = 256;

// ���� ������.
enum keyboard_kod { UP_KEY = 0x48, DOWN_KEY = 0x50, LEFT_KEY = 0x4B, RIGHT_KEY = 0x4D, SPACE = 32, ENTER = 13, BACK_SLASH = 92 };
// ����������, � ������� ������������ ��� �������.
int  key_code;

// ��� ��������� ������� ��� ������.
const int char_size = 4096;
char lvl1[char_size]{};
char lvl2[char_size]{};
char lvl3[char_size]{};
char lvl4[char_size]{};
char lvl5[char_size]{};

// �����, ����� menu() ������ ������ ����� �� �������.
int level_choice();
int error_player_lvl();

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
			printf(lvl1);
			printf("\n\npress enter or spacebar to continue");
			break;

		case 2:
			system("cls");
			printf("Level 2\n\n");
			printf(lvl2);
			printf("\n\npress enter or spacebar to continue");
			break;

		case 3:
			system("cls");
			printf("Level 3\n\n");
			printf(lvl3);
			printf("\n\npress enter or spacebar to continue");
			break;

		case 4:
			system("cls");
			printf("Level 4\n\n");
			printf(lvl3); //----------------------------------------------------------------------- !
			printf("\n\npress enter or spacebar to continue");
			break;

		case 5:
			system("cls");
			printf("Level 5\n\n");
			printf(lvl3); //----------------------------------------------------------------------- !
			printf("\n\npress enter or spacebar to continue");
			break;

		case 6:
			system("cls");
			printf("Your level\n\n");

			printf("  #####\n ##   ##\n## X   ##\n\t#\n     B ##\n      ##\n    ##\n   ##\n\n   @");
			//printf("###########\n###.....###\n##..###..##\n#..#####..#\n#@######B.#\n########..#\n#######..##\n######..###\n#####..####\n#####X#####\n#####.#####\n###########");

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

void clear_history(int movehistory[])
{
	for (int i = 0; i < MAXARRAYLENGTH; i++)
		movehistory[i] = 0;
}

// 
int player_lvl(char* fullstr)
{
	bool file_missing;
	bool continue_dowhile;
	bool type_missing;

	//������������ bool file_missing = 0; bool continue_dowhile = 1;
	do
	{
		file_missing = 0;
		continue_dowhile = 0;
		type_missing = 1;

		// �������� ������, �������� �������.
		char name_player_lvl[size_name];

		/* ��������
		strcpy_s(name_player_lvl, "���");
		printf("\n%s, %d, %d\n", name_player_lvl, sizeof(char), sizeof(name_player_lvl)); ���, 1, 32
		system("pause");
		system("cls");
		*/

		//���� �����
		system("cls");
		printf("���� ���� � ����� ������� ��������� � ��� �� �����,\n��� � ����������������� ����� � 1 �� 5 �������,\n����� ������ ������� ��� ��������.\n");
		printf("\n���� ��� ���� ��������� � ������ �����,\n���������� ������� ������ ���� � ����.\n\n��������!\n� ������ ������ ���� ���� ������ ����\n������� .txt � ��� �������.\n\n");

		scanf_s("%s", &name_player_lvl, size_name);


		for (int i = 0; i < size_name; i++)
		{
			if (name_player_lvl[i] == '.' && name_player_lvl[i + 1] == 't' && name_player_lvl[i + 2] == 'x' && name_player_lvl[i + 3] == 't')
				type_missing = 0;
			if (name_player_lvl[i] == BACK_SLASH)
				name_player_lvl[i] = '/';

		}
		if (type_missing)
			strcat_s(name_player_lvl, ".txt");

		file_missing = openfilelvl(fullstr, name_player_lvl);

		if (file_missing == 1)
		{
			if (error_player_lvl() == 2)
			{
				return 1;
			}
			else
			{
				continue_dowhile = 1;
			}

		}

	} while (continue_dowhile);

	if (file_missing == 0)
		filmas(fullstr);

	return 0;

}


// ��������� ��� ������ �������� ������ ������.
int error_player_lvl()
{
	int player_choice = 1;

	do
	{
		// 1.Start 2.Exit
		switch (player_choice)
		{
		case 1:
			system("cls");
			printf("\t�� ���������� ������� ����.\n\n");
			printf(">> ����������� �����.\n������� ������ �������.\n\npress enter or spacebar to continue");
			break;

		case 2:
			system("cls");
			printf("\t�� ���������� ������� ����.\n\n");
			printf("����������� �����.\n>> ������� ������ �������.\n\npress enter or spacebar to continue");
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
			player_choice = 1;
			break;

		case DOWN_KEY:
		case 'S':
		case 's':
		case '�':
		case '�':
			player_choice = 2;
			break;

		default:
			break;
		}

	} while (key_code != ENTER and key_code != SPACE);

	return player_choice;
}