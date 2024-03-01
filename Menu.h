#pragma once
#ifndef _MENU_H_
#define _MENU_H_

// ��������� ��������� ������ ������ � ���������� ����� ���������� ������. ���� ���������� 0, �� ���� ������� Exit.
int menu(bool skip);

//��������� ������ ������ � ��������� ��� ���������.
int level_choice();

//���������� �� ��������� ���� � ������� ��������� � ������� ��������.
int ending();

int player_lvl(char* fullstr);

// ��������� ��� ������ �������� ������ ������.
int error_player_lvl();

void clear_history(int* movehistory);

#endif