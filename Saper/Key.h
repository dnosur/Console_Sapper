#pragma once
#include <conio.h>

#define KEY_ARROW_DOWN 80
#define KEY_ARROW_UP 72

#define KEY_ARROW_LEFT 75
#define KEY_ARROW_RIGHT 77

#define KEY_ENTER 13

#define KEY_F 102

#define KEY_UNDEFINED -1

class Key {
public:
	const enum Keys {
		//Arrows
		ArrowDown = KEY_ARROW_DOWN,
		ArrowUp = KEY_ARROW_UP,
		ArrowLeft = KEY_ARROW_LEFT,
		ArrowRight = KEY_ARROW_RIGHT,

		//Keyboards
		Enter = KEY_ENTER,

		//Letters
		F = KEY_F,

		//Other
		Undefined = KEY_UNDEFINED
	};

	static Keys GetKey();
};