#pragma once

#include "Cell.h"
#include "GameSetting.h"

#include "Key.h"
#include "Color.h"

class Field
{
	Cell<char>** field;

	GameSetting gameSettings;
	Coord cursor;

	bool gameOver;
	bool win;

	void GenerateField();
	void CheckWin();

	//Actions
	void MoveCursor(Key::Keys key);
	void RevealCell(int x, int y);
	void SetMarker();
public:
	Field();
	Field(GameSetting gameSettings);

	void Restart();
	void Restart(GameSetting gameSettings);

	void Show();

	void Action(Key::Keys key);

	bool IsOver();
	bool IsWin();
};