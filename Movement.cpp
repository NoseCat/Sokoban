#include <iostream>
#include <conio.h>

enum arrowkeys { UP_KEY = 0x48, DOWN_KEY = 0x50, LEFT_KEY = 0x4B, RIGHT_KEY = 0x4D };
enum direction { STAND, UP_DIR, DOWN_DIR, LEFT_DIR, RIGHT_DIR, CANCEL};

enum objects { EMPTY, WALL, PLAYER, BOX};

const int rows = 10, cols = 15;
int matrix[rows][cols] = {};

int history[1000] = {};

//меняет местами интовые а и b (такая форма работает только для целочисленых)
void swap(int& a, int& b)
{
	a ^= b ^= a ^= b;
}

//Получение с клавиатуры клавиши
//STAND - передается try_move чтобы сказать что она ничего не делает
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
		//printf("up\n");
		return UP_DIR;
		break;
	case DOWN_KEY:
	case 'S':
	case 's':
	case 'Ы':
	case 'ы':
		//printf("down\n");
		return DOWN_DIR;
		break;
	case LEFT_KEY:
	case 'A':
	case 'a':
	case 'Ф':
	case 'ф':
		//printf("left\n");
		return LEFT_DIR;
		break;
	case RIGHT_KEY:
	case 'D':
	case 'd':
	case 'В':
	case 'в':
		//printf("right\n");
		return RIGHT_DIR;
		break;
	case 'R':
	case 'r':
	case 'К':
	case 'к':
		//printf("restart\n");
		//restart();
		return STAND;
		break;
	case ' ':
		return CANCEL;
		break;
	default:
		//printf("default\n");
		return STAND;
	}
	return STAND;
}

//Позже хорошобы сделать счетчик ходов

//Пытается сдвинуть элемент матрицы в сторону dir
//так как i идет сверху вниз (; i < rows; i++), и j идет вправо (; j < cols; j++) то в данной системе координат
//y направлен вниз, x направлен вправо
void try_move(int y, int x, int dir, bool move_boxes)
{
	int target_y = y;
	int target_x = x;

	switch (dir)
	{
	case STAND:
		return;
		break;
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
	case CANCEL:
		break;
	default:
		printf("try_move: default\n");
		return;
	}

	//Стена, здесь же и проверка на выход за границы матрицы
	if (target_x < 0 || target_x >= cols || target_y < 0 || target_y >= rows || matrix[target_y][target_x] == WALL)
		return;

	//Пусто
	if (matrix[target_y][target_x] == EMPTY)
	{
		swap(matrix[y][x], matrix[target_y][target_x]);
		//if ((dir == RIGHT_DIR || dir == DOWN_DIR) && matrix[y][x] == PLAYER)
			//matrix[target_y][target_x] = MOVED_PLAYER;
		//else
			//matrix[target_y][target_x] = matrix[y][x];

		//matrix[y][x] = EMPTY;
	}

	//Коробка
	if (matrix[target_y][target_x] == BOX)
	{
		if (move_boxes)
		{
			try_move(target_y, target_x, dir, false);
			try_move(y, x, dir, false);
		}
		else { return; }
	}

	//Тоже игрок
	/*if (matrix[target_y][target_x] == PLAYER && (dir == RIGHT_DIR || dir == DOWN_DIR))
	{
		try_move(target_y, target_x, dir, true);
		try_move(y, x, dir, false);
	} */
}

void move_player(int dir)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] == PLAYER)
			{
				try_move(i, j, dir, true); // is matrix global?
				return;
			}

			//if (matrix[i][j] == MOVED_PLAYER)
			//{
				//matrix[i][j] = PLAYER;
			//}
		}
}

int main()
{
	matrix[5][5] = PLAYER;
	//matrix[6][6] = PLAYER;
	matrix[7][7] = BOX;

	//вне цикла
	system("chcp 1251 > nul");
	int dir = STAND;

	//в цикле
	while (true)
	{
		system("cls");
		for (int i = 0; i < rows; i++)
		{
			printf("\n");
			for (int j = 0; j < cols; j++)
				printf("%i", matrix[i][j]);
		}

		dir = get_player_input();
		move_player(dir);
	}
}