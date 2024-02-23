#include <iostream>
#include <conio.h>
#include "Movement.h"
//enum objects { EMPTY, WALL, PLAYER, BOX };

//const int rows = 10, cols = 15;
//int matrix[rows][cols] = {};

//���������� ������ ������� ������� �������� �������
//�� ��������� �� ������������������� �������!
int array_first_empty(int array[])
{
	for (int i = 0; i < MAXARRAYLENGTH; i++)
	{
		if (array[i] == 0)
			return i;
	}
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
void try_move(int y, int x, int dir, bool move_boxes)
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
		return;
	}

	//��������� ����������� ��������

	//�����, ����� �� � �������� �� ����� �� ������� �������
	if (target_x < 0 || target_x >= cols || target_y < 0 || target_y >= rows || matrix[target_y][target_x] == WALL)
		return;

	//�����
	if (matrix[target_y][target_x] == EMPTY)
	{
		swap(matrix[y][x], matrix[target_y][target_x]);
		return;
	}

	//�������
	if (matrix[target_y][target_x] == BOX)
	{
		if (move_boxes)
		{
			try_move(target_y, target_x, dir, false);
			//���� ��������� ������� ����� ��� ��������
			movehistory[array_first_empty(movehistory)] = BOXINDICATOR;
			try_move(y, x, dir, false);
			return;
		}
		else { return; }
	}
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

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] == PLAYER)
			{
				movehistory[firstempty - 1] = 0;
				try_move(i, j, backdir, false);
				if (box)
					try_move(i + box_y, j + box_x, backdir, false);
				return;
			}
		}
}

//������� ������ � ������������ ��������
void move_player(int dir)
{
	switch (dir)
	{
	case STAND:
		return; break;
	case RESTART:
		//restart();
		return; break;
	case UNDO:
		undo();
		return; break;
	case UP_DIR:
	case DOWN_DIR:
	case LEFT_DIR:
	case RIGHT_DIR:

		movehistory[array_first_empty(movehistory)] = dir;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] == PLAYER)
				{
					try_move(i, j, dir, true);
					return;
				}
			}
		break;

	default:
		printf("move_player: default\n");
		return;
	}
}

/* �������� ����
		dir = get_player_input();
		move_player(dir);
*/