#pragma once
#ifndef _MENU_H_
#define _MENU_H_

//���� ������.
enum keyboard_kod { UP_KEY = 0x48, DOWN_KEY = 0x50, LEFT_KEY = 0x4B, RIGHT_KEY = 0x4D, SPACE = 32, ENTER = 13, BACK_SLASH = 92 };

// ������ * �������.
const int char_size = 4096;

// ��� ��������� ������� ��� ������.
char lvl1[];
char lvl2[];
char lvl3[];
char lvl4[];
char lvl5[];

// ��������� ��������� ������ ������ � ���������� ����� ���������� ������. ���� ���������� 0, �� ���� ������� Exit.
int menu(bool skip);

//��������� ������ ������ � ��������� ��� ���������.
int level_choice();

//���������� �� ��������� ���� � ������� ��������� � ������� ��������.
int ending();

//
int player_lvl(char* fullstr);

// ��������� ��� ������ �������� ������ ������.
int error_player_lvl();

void clear_history(int movehistory[]);

#endif