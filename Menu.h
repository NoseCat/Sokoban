#pragma once
#ifndef _MENU_H_
#define _MENU_H_

//���� ������.
enum keyboard_kod { UP_KEY = 0x48, DOWN_KEY = 0x50, LEFT_KEY = 0x4B, RIGHT_KEY = 0x4D, SPACE = 32, ENTER = 13 };

// ��������� ��������� ������ ������ � ���������� ����� ���������� ������. ���� ���������� 0, �� ���� ������� Exit.
int menu(bool skip);

//��������� ������ ������ � ��������� ��� ���������.
int level_choice();

//���������� �� ��������� ���� � ������� ��������� � ������� ��������.
int ending();

#endif