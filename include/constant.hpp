#ifndef __CONSTANT_H_
#define __CONSTANT_H_

enum Direction {
	UP, DOWN, LEFT, RIGHT
};

enum KeyCode {
	UP_KEY_CODE = 259, LEFT_KEY_CODE = 260,
	RIGHT_KEY_CODE = 261, DOWN_KEY_CODE = 258,
	SPACE_BAR_KEY_CODE = 32, PAUSE_KEY_CODE = 112
};

enum Resume {
	RESUME = 49, EXIT = 50
};

enum Color {
	WALL = 1, IMMUNE_WALL, SNAKE, FOOD, POISON, SCORE, TITLE, BLANK
};

#endif
