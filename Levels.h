#pragma once
#ifndef _LEVELS_H_
#define _LEVELS_H_

// ������ ����������: 0 - ���� ��������, 1 - �� ���������� ������� ����.
bool openfilelvl(char* fullstr, const char lvl_name[]);
void find_rows_cols(char* fullstr);

void filmas(char str[]);
void displaymatrix();
#endif