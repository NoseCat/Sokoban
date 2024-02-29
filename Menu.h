#pragma once
#ifndef _MENU_H_
#define _MENU_H_

//коды кнопок.
enum keyboard_kod { UP_KEY = 0x48, DOWN_KEY = 0x50, LEFT_KEY = 0x4B, RIGHT_KEY = 0x4D, SPACE = 32, ENTER = 13 };

// «апускает интерфейс выбора уровн€ и возвращает номер выбранного уровн€. ≈сли возвращает 0, то было выбрано Exit.
int menu(bool skip);

//интерфейс выбора уровн€ и возможный его предпоказ.
int level_choice();

//уведомл€ет об окончании игры и выводит результат с выбором действий.
int ending();

#endif