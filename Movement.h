#pragma once
#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_

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
void move_player(int dir);

//проверка победы
bool win_check();

#endif