#pragma once
#include <iostream>

#include "functions.h"

struct GameSetting {
	GameSetting();
	GameSetting(int rows, int cols, int mines);

	int rows;
	int cols;

	int mines;

	bool operator==(const GameSetting& other) const {
		return (rows == other.rows) && (cols == other.cols) && (mines == other.mines);
	}

	bool operator!=(const GameSetting& other) const {
		return !(*this == other);
	}

	GameSetting& operator=(const GameSetting& other) {
		if (this != &other) {
			rows = other.rows;
			cols = other.cols;

			mines = other.mines;
		}

		return *this;
	}
};

GameSetting Setting();