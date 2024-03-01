#pragma once
#ifndef _MENU_H_
#define _MENU_H_

//коды кнопок.
enum keyboard_kod { UP_KEY = 0x48, DOWN_KEY = 0x50, LEFT_KEY = 0x4B, RIGHT_KEY = 0x4D, SPACE = 32, ENTER = 13, BACK_SLASH = 92 };

// строки * столбцы.
const int char_size = 4096;

// Для отрисовки уровней при выборе.
char lvl1[];
char lvl2[];
char lvl3[];
char lvl4[];
char lvl5[];

// Запускает интерфейс выбора уровня и возвращает номер выбранного уровня. Если возвращает 0, то было выбрано Exit.
int menu(bool skip);

//интерфейс выбора уровня и возможный его предпоказ.
int level_choice();

//уведомляет об окончании игры и выводит результат с выбором действий.
int ending();

//
int player_lvl(char* fullstr);

// Интерфейс при ошибке открытия уровня игрока.
int error_player_lvl();

void clear_history(int movehistory[]);

#endif