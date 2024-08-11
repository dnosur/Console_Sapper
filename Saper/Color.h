#pragma once
#include <iostream>
#include <Windows.h>

class Color
{
public:
	const enum ConsoleColor
	{
		Black = 0,
		Blue = 1,
		Green = 2,
		Cyan = 3,
		Red = 4,
		Magenta = 5,
		Brown = 6,
		LightGray = 7,
		DarkGray = 8,
		LightBlue = 9,
		LightGreen = 10,
		LightCyan = 11,
		LightRed = 12,
		LightMagenta = 13,
		Yellow = 14,
		White = 15
	};

	static void SetColor(int text, int background = ConsoleColor::Black);
	static void ResetColor();

	static void Print(const char* text, int textColor, int backgroundColor = ConsoleColor::Black);
	static void RPrint(const char* text, int textColor, int backgroundColor = ConsoleColor::Black);
};

