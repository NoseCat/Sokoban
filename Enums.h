#pragma once
#ifndef _ENUMS_H_
#define _ENUMS_H_

//коды кнопок.
enum keyboard_kod { UP_KEY = 0x48, DOWN_KEY = 0x50, LEFT_KEY = 0x4B, RIGHT_KEY = 0x4D, SPACE = 32, ENTER = 13, BACK_SLASH = 92 };

enum direction { STAND, UP_DIR, DOWN_DIR, LEFT_DIR, RIGHT_DIR, UNDO, RESTART};
enum history { BOXINDICATOR = -1, MAXHISTSIZE = 1024 };

enum objects { EMPTY = 1, WALL, PLAYER, WHITEBOX, REDBOX, GREENBOX, BLUEBOX, FINISH, NEXTROWS };
enum color { white = 7, red = 12, green = 10, blue = 9 };
enum maxsizes { rows = 64, cols = 64, razmaszh = 16 * 3 , char_size = 4096};
//максимальное количество крестов на поле = razmaszh / 3

#endif