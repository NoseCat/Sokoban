#pragma once
#ifndef _MENU_H_
#define _MENU_H_

// Запускает интерфейс выбора уровня и возвращает номер выбранного уровня. Если возвращает 0, то было выбрано Exit.
int menu(bool skip);

//интерфейс выбора уровня и возможный его предпоказ.
int level_choice();

//уведомляет об окончании игры и выводит результат с выбором действий.
int ending();

int player_lvl(char* fullstr);

// Интерфейс при ошибке открытия уровня игрока.
int error_player_lvl();

void clear_history(int* movehistory);

#endif