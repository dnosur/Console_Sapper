#pragma once
#include <windows.h>
#include <string>
#include <conio.h>

#include <map>

void clear();
void pause();

void gotoxy(int X, int Y);
void gotoxy(COORD coord);

COORD getxy();
void getxy(int& x, int& y);