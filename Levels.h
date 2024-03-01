#pragma once
#ifndef _LEVELS_H_
#define _LEVELS_H_

enum objects { EMPTY = 1, WALL, PLAYER, WHITEBOX, REDBOX, GREENBOX, BLUEBOX, FINISH, NEXTROWS };

enum maxsizes { rows = 64, cols = 64, razmaszh = 16 * 3};

// ������ ����������: 0 - ���� ��������, 1 - �� ���������� ������� ����.
bool openfilelvl(char* fullstr, const char lvl_name[]);

void filmas(char str[]);
void displaymatrix();
#endif