#pragma once
#ifndef _MOVEMENT_H_

enum arrowkeys { UP_KEY = 0x48, DOWN_KEY = 0x50, LEFT_KEY = 0x4B, RIGHT_KEY = 0x4D };
enum direction { STAND, UP_DIR, DOWN_DIR, LEFT_DIR, RIGHT_DIR, UNDO, RESTART };
enum history { BOXINDICATOR = -1 };

const int MAXARRAYLENGTH = 1000;
int movehistory[MAXARRAYLENGTH] = {};

//������ ������� ������� � � b (����� ����� �������� ������ ��� ������������)
void swap(int& a, int& b)
{
	a ^= b ^= a ^= b;
}

//���������� ������ ������� ������� �������� �������
//�� ��������� �� ������������������� �������!
int array_first_empty(int array[]);

//���������� ����������� �������� �������
int reverse_direction(int dir);

//��������� � ���������� �������
int get_player_input();

//�������� �������� ������� ������� � ������� dir
//��� ��� i ���� ������ ���� (; i < rows; i++), � j ���� ������ (; j < cols; j++) �� � ������ ������� ���������
//y ��������� ����, x ��������� ������
void try_move(int y, int x, int dir, bool move_boxes);

//�������� ��������� �������� �������� movehistory[]
void undo();

//������� ������ � ������������ ��������
void move_player(int dir);

#endif