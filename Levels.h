#pragma once
#ifndef _LEVELS_H_
#define _LEVELS_H_

enum objects { EMPTY, WALL, PLAYER, BOX, FINISH, NEXTROWS };

enum sizes {rows = 20, cols = 20};

//int mas[rows][cols];

void openfilelvl(char* str);

void filmas(char str[]);
void displaymatrix();
#endif