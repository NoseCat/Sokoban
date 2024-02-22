#include <iostream>
#include <conio.h>

const int max_lvl = 2;

int level_choice();
int opening(int lvl);
int ending();

//�� ������� �������� ������� � ������� ����������� ���� � � ������� ��� ��������. 
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
		} while (menu_code != 13 and menu_code != 32);

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

//��������� ������ ������ � ��������� ��� ���������.
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
	} while (lvl_code != 13 and lvl_code != 32);


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

//��������� �� ���� �������� ������� � ��������� ���.
int opening(int lvl)
{
	switch (lvl)
	{
		//menu
	case 0: return 0;
	}
}

//���������� �� ��������� ���� � ������� ��������� � ������� ��������.
int ending()
{

	return 0;// ��������. ���� �� � ������, �������� �������������� �� ���� ������� ����.
}

int main()
{
	system("chcp 1251 > nul");

	menu();

	return 0;
}