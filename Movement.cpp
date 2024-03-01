#include <iostream>
#include <conio.h>
#include "Levels.h"
#include "Menu.h"
#include "Enums.h"

int* movehistory;
int moves;

extern int realrows, realcols, targets;
extern int** mas;
extern int* masznach_x;
extern char* fullstr;

//������ ������� ������� � � b (����� ����� �������� ������ ��� ������������)
void swap(int& a, int& b)
{
	a ^= b ^= a ^= b;
}

//���������� ������ ������� ������� �������� �������
//�� ��������� �� ������������������� �������!
int array_first_empty(int array[])
{
	for (int i = 0; i < MAXHISTSIZE; i++)
	{
		if (array[i] == 0)
			return i;
	}
	return 0;
}

//��������� � ���������� �������
int get_player_input()
{
	char chardir = _getch();
	switch (chardir)
	{
	case UP_KEY:
	case 'W':
	case 'w':
	case '�':
	case '�':
		return UP_DIR;
		break;
	case DOWN_KEY:
	case 'S':
	case 's':
	case '�':
	case '�':
		return DOWN_DIR;
		break;
	case LEFT_KEY:
	case 'A':
	case 'a':
	case '�':
	case '�':
		return LEFT_DIR;
		break;
	case RIGHT_KEY:
	case 'D':
	case 'd':
	case '�':
	case '�':
		return RIGHT_DIR;
		break;

	case ' ':
		return UNDO;
		break;

	case 'R':
	case 'r':
	case '�':
	case '�':
		return RESTART;
		break;

	default:
		return STAND;
	}
	printf("???: we got out of switch for some reason\n");
	return STAND;
}

//����� �������� ������� ������� �����

//�������� �������� ������� ������� � ������� dir
//��� ��� i ���� ������ ���� (; i < rows; i++), � j ���� ������ (; j < cols; j++) �� � ������ ������� ���������
//y ��������� ����, x ��������� ������
//���������� 1 ���� ���� ��������, 0 ���� �� ����
//-1 ���� ���� ������, 2 ���� ���� �������������� � ��������
int try_move(int y, int x, int dir, bool move_boxes, bool write_history)
{
	int target_y = y;
	int target_x = x;


	//������� ������ ����������� ��������
	switch (dir)
	{
	case UP_DIR:
		target_y--; //���� �� �������� ����� y - ����������
		break;
	case DOWN_DIR:
		target_y++; //���� - ����������
		break;
	case LEFT_DIR:
		target_x--; //����� x ����������
		break;
	case RIGHT_DIR:
		target_x++; //������ - ����������
		break;

	default:
		printf("try_move: default\n");
		return -1;
	}

	//��������� ����������� ��������

	//�����, ����� �� � �������� �� ����� �� ������� �������
	if (target_x < 0 || target_x >= realcols || target_y < 0 || target_y >= realrows || mas[target_y][target_x] == WALL)
		return 0;

	//�����
	if (mas[target_y][target_x] == EMPTY)
	{
		if (write_history)
		{
			moves++;
			movehistory[array_first_empty(movehistory)] = dir;
		}
		swap(mas[y][x], mas[target_y][target_x]);
		return 1;
	}

	//�������
	if (move_boxes && (mas[target_y][target_x] == WHITEBOX || mas[target_y][target_x] == REDBOX || mas[target_y][target_x] == GREENBOX || mas[target_y][target_x] == BLUEBOX) && try_move(target_y, target_x, dir, false, false) == 1)
	{
		try_move(y, x, dir, false, true);
		movehistory[array_first_empty(movehistory)] = BOXINDICATOR;
		return 2;
	}

	return 0;
}

//���������� ����������� �������� �������
int reverse_direction(int dir)
{
	switch (dir)
	{
	case UP_DIR:
		return DOWN_DIR;
	case DOWN_DIR:
		return UP_DIR;
	case RIGHT_DIR:
		return LEFT_DIR;
	case LEFT_DIR:
		return RIGHT_DIR;
	}
	return 0;
}

//�������� ��������� �������� �������� movehistory[]
void undo()
{
	int firstempty = array_first_empty(movehistory);
	if (firstempty == 0)
		return;

	moves--;

	int box_y = 0;
	int box_x = 0;
	bool box = false;

	if (movehistory[firstempty - 1] == BOXINDICATOR)
	{
		box = true;
		movehistory[firstempty - 1] = 0;
		firstempty--;
		switch (movehistory[firstempty - 1])
		{
		case UP_DIR:
			box_y--;
			break;
		case DOWN_DIR:
			box_y++;
			break;
		case LEFT_DIR:
			box_x--;
			break;
		case RIGHT_DIR:
			box_x++;
			break;

		default:
			printf("box find: default\n");
			return;
		}
	}

	int backdir = reverse_direction(movehistory[firstempty - 1]);

	for (int i = 0; i < realrows; i++)
		for (int j = 0; j < realcols; j++)
		{
			if (mas[i][j] == PLAYER)
			{
				movehistory[firstempty - 1] = 0;
				try_move(i, j, backdir, false, false);
				if (box)
					try_move(i + box_y, j + box_x, backdir, false, false);
				return;
			}
		}
}

//������� ������ � ������������ ��������
void move_player(int dir)
{
	int histsize;
	switch (dir)
	{
	case STAND:
		return; break;
	case RESTART:
		filmas(fullstr);
		moves = 0;
		histsize = array_first_empty(movehistory);
		for (int i = 0; i < histsize; i++)
			movehistory[i] = 0;
		return; break;
	case UNDO:
		undo();
		return; break;
	case UP_DIR:
	case DOWN_DIR:
	case LEFT_DIR:
	case RIGHT_DIR:

		for (int i = 0; i < realrows; i++)
			for (int j = 0; j < realcols; j++)
			{
				if (mas[i][j] == PLAYER)
				{
					try_move(i, j, dir, true, true);
					return;
				}
			}
		break;

	default:
		printf("move_player: default\n");
		return;
	}
}

//�������� ������
bool win_check()
{
	int s = 0;
	for (int k = 0; k < targets*3; k += 3)
	{
		switch (masznach_x[k + 2])
		{
		case white:
			if (mas[masznach_x[k]][masznach_x[k + 1]] == WHITEBOX || 
				mas[masznach_x[k]][masznach_x[k + 1]] == REDBOX || 
				mas[masznach_x[k]][masznach_x[k + 1]] == GREENBOX ||
				mas[masznach_x[k]][masznach_x[k + 1]] == BLUEBOX )
				s++;
			break;
		case red:
			if (mas[masznach_x[k]][masznach_x[k + 1]] == REDBOX)
				s++;
			break;
		case green:
			if (mas[masznach_x[k]][masznach_x[k + 1]] == GREENBOX)
				s++;
			break;
		case blue:
			if (mas[masznach_x[k]][masznach_x[k + 1]] == BLUEBOX)
				s++;
			break;
		}
	}

	if (s == targets)
		return true;
	else
		return false;
}