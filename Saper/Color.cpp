#include "Color.h"

void Color::SetColor(int text, int background) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

void Color::ResetColor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((ConsoleColor::Black << 4) | ConsoleColor::White));
}

void Color::Print(const char* text, int textColor, int backgroundColor)
{
	SetColor(textColor, backgroundColor);
	std::cout << text;
}

void Color::RPrint(const char* text, int textColor, int backgroundColor)
{
	Print(text, textColor, backgroundColor);
	ResetColor();
}
