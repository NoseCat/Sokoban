#pragma once
#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_

//enum arrowkeys { UP_KEY = 0x48, DOWN_KEY = 0x50, LEFT_KEY = 0x4B, RIGHT_KEY = 0x4D };
enum direction { STAND, UP_DIR, DOWN_DIR, LEFT_DIR, RIGHT_DIR, UNDO, RESTART };
enum history { BOXINDICATOR = -1 };
//
//const int MAXARRAYLENGTH = 1000;
//int movehistory[MAXARRAYLENGTH] = {};

//меняет местами интовые а и b (такая форма работает только для целочисленых)
void swap(int& a, int& b);

//возвращает индекс первого пустого элемента массива
//не применять на неинициализированые массивы!
int array_first_empty(int array[]);

//Возвращает направление обратное данному
int reverse_direction(int dir);

//Получение с клавиатуры клавиши
int get_player_input();

//Пытается сдвинуть элемент матрицы в сторону dir
//так как i идет сверху вниз (; i < rows; i++), и j идет вправо (; j < cols; j++) то в данной системе координат
//y направлен вниз, x направлен вправо
int try_move(int y, int x, int dir, bool move_boxes, bool write_history);

//отменяет последнее действие согласно movehistory[]
void undo();

//находит игрока и опредеделяет действие
void move_player(int dir, char lvl[]);

//проверка победы
bool win_check();

#endif