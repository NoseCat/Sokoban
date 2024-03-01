#pragma once
#ifndef _LEVELS_H_
#define _LEVELS_H_

enum objects { EMPTY = 1, WALL, PLAYER, WHITEBOX, REDBOX, GREENBOX, BLUEBOX, FINISH, NEXTROWS };
enum color { white = 7, red = 12, green = 10, blue = 9 };
enum maxsizes { rows = 64, cols = 64, razmaszh = 16 * 3};

// Теперь возвращает: 0 - файл открылся, 1 - не получилось открыть файл.
bool openfilelvl(char* fullstr, const char lvl_name[]);
void find_rows_cols(char* fullstr);

void filmas(char str[]);
void displaymatrix();
#endif