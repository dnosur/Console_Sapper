#pragma once
#include <windows.h>

struct Coord
{
    Coord();
    Coord(const int X, const int Y);
    Coord(COORD coord);

    int X, Y;

    bool operator==(const Coord& other) const;
    bool operator!=(const Coord& other) const;

    bool operator==(const COORD& other) const;
    bool operator!=(const COORD& other) const;

    Coord& operator=(const Coord& other);
    Coord& operator=(const COORD& other);
};