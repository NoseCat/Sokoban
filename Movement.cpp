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

//меняет местами интовые а и b (такая форма работает только для целочисленых)
void swap(int& a, int& b)
{
	a ^= b ^= a ^= b;
}

//возвращает индекс первого пустого элемента массива
//не применять на неинициализированые массивы!
int array_first_empty(int array[])
{
	for (int i = 0; i < MAXHISTSIZE; i++)
	{
		if (array[i] == 0)
			return i;
	}
	return 0;
}

//Получение с клавиатуры клавиши
int get_player_input()
{
	char chardir = _getch();
	switch (chardir)
	{
	case UP_KEY:
	case 'W':
	case 'w':
	case 'Ц':
	case 'ц':
		return UP_DIR;
		break;
	case DOWN_KEY:
	case 'S':
	case 's':
	case 'Ы':
	case 'ы':
		return DOWN_DIR;
		break;
	case LEFT_KEY:
	case 'A':
	case 'a':
	case 'Ф':
	case 'ф':
		return LEFT_DIR;
		break;
	case RIGHT_KEY:
	case 'D':
	case 'd':
	case 'В':
	case 'в':
		return RIGHT_DIR;
		break;

	case ' ':
		return UNDO;
		break;

	case 'R':
	case 'r':
	case 'К':
	case 'к':
		return RESTART;
		break;

	default:
		return STAND;
	}
	printf("???: we got out of switch for some reason\n");
	return STAND;
}

//Позже хорошобы сделать счетчик ходов

//Пытается сдвинуть элемент матрицы в сторону dir
//так как i идет сверху вниз (; i < rows; i++), и j идет вправо (; j < cols; j++) то в данной системе координат
//y направлен вниз, x направлен вправо
//возвращает 1 если было движение, 0 если не было
//-1 если была ошибка, 2 если было взаимодействие с коробкой
int try_move(int y, int x, int dir, bool move_boxes, bool write_history)
{
	int target_y = y;
	int target_x = x;


	//Находим клетку направления движения
	switch (dir)
	{
	case UP_DIR:
		target_y--; //если мы движемся вверх y - понижается
		break;
	case DOWN_DIR:
		target_y++; //вниз - повышается
		break;
	case LEFT_DIR:
		target_x--; //влево x понижвется
		break;
	case RIGHT_DIR:
		target_x++; //вправо - повышается
		break;

	default:
		printf("try_move: default\n");
		return -1;
	}

	//обработка направления движения

	//Стена, здесь же и проверка на выход за границы матрицы
	if (target_x < 0 || target_x >= realcols || target_y < 0 || target_y >= realrows || mas[target_y][target_x] == WALL)
		return 0;

	//Пусто
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

	//Коробка
	if (move_boxes && (mas[target_y][target_x] == WHITEBOX || mas[target_y][target_x] == REDBOX || mas[target_y][target_x] == GREENBOX || mas[target_y][target_x] == BLUEBOX) && try_move(target_y, target_x, dir, false, false) == 1)
	{
		try_move(y, x, dir, false, true);
		movehistory[array_first_empty(movehistory)] = BOXINDICATOR;
		return 2;
	}

	return 0;
}

//Возвращает направление обратное данному
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

//отменяет последнее действие согласно movehistory[]
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

//находит игрока и опредеделяет действие
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

//проверка победы
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