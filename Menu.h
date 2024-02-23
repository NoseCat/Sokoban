#pragma once
#ifndef _MENU_H_
#define _MENU_H_

//коды кнопок.
enum keyboard_kod { UP_KEY = 0x48, DOWN_KEY = 0x50, LEFT_KEY = 0x4B, RIGHT_KEY = 0x4D, SPACE = 32, ENTER = 13 };

//По задумке основная функция с которой запускается игра и в которой она проходит. 
int menu();

//интерфейс выбора уровня и возможный его предпоказ.
int level_choice();

//уведомляет об окончании игры и выводит результат с выбором действий.
int ending();

#endif