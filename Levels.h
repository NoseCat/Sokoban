#pragma once
#ifndef _LEVELS_H_
#define _LEVELS_H_

// Теперь возвращает: 0 - файл открылся, 1 - не получилось открыть файл.
bool openfilelvl(char* fullstr, const char lvl_name[]);
void find_rows_cols(char* fullstr);

void filmas(char str[]);
void displaymatrix();
#endif