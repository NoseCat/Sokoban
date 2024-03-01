#pragma once
#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_

//������ ������� ������� � � b (����� ����� �������� ������ ��� ������������)
void swap(int& a, int& b);

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
int try_move(int y, int x, int dir, bool move_boxes, bool write_history);

//�������� ��������� �������� �������� movehistory[]
void undo();

//������� ������ � ������������ ��������
void move_player(int dir);

//�������� ������
bool win_check();

#endif