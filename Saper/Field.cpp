#include "Field.h"

void Field::GenerateField()
{
	field = new Cell<char>*[gameSettings.rows];
	for (int i = 0; i < gameSettings.rows; i++) {
		field[i] = new Cell<char>[gameSettings.cols];
		for (int j = 0; j < gameSettings.cols; j++) {
			field[i][j].value = '.';
		}
	}

	int placedMines = 0;
	while (placedMines < gameSettings.mines)
	{
		int row = rand() % gameSettings.rows;
		int col = rand() % gameSettings.cols;

		if (field[row][col].value != '*')
		{
			field[row][col].value = '*';
			placedMines++;
		}
	}

	for (int i = 0; i < gameSettings.rows; i++)
	{
		for (int j = 0; j < gameSettings.cols; j++)
		{
			if (field[i][j].value == '*') {
				continue;
			}

			int mineCount = 0;
			for (int x = -1; x <= 1; x++)
			{
				for (int y = -1; y <= 1; y++)
				{
					int newRow = i + x;
					int newCol = j + y;
					if (newRow >= 0 && newRow < gameSettings.rows && 
						newCol >= 0 && newCol < gameSettings.cols && 
						field[newRow][newCol].value == '*')
					{
						mineCount++;
					}
				}
			}

			if (!mineCount) {
				field[i][j].value = '.';
				continue;
			}

			char value = mineCount + '0';
			field[i][j].value = value;
		}
	}
}

void Field::CheckWin()
{
	for (int i = 0; i < gameSettings.rows; i++) {
		for (int j = 0; j < gameSettings.cols; j++) {
			if (!field[i][j].revealed && field[i][j].value != '*') {
				win = false;
				return;
			}
		}
	}
	win = true;
	gameOver = true;
}

void Field::MoveCursor(Key::Keys key)
{
	if (key == Key::Keys::ArrowDown) {
		cursor.Y = cursor.Y + 1 < gameSettings.rows
			? cursor.Y + 1
			: 0;
		return;
	}

	if (key == Key::Keys::ArrowUp) {
		cursor.Y = cursor.Y - 1 >= 0
			? cursor.Y - 1
			: gameSettings.rows - 1;
		return;
	}

	if (key == Key::Keys::ArrowLeft) {
		cursor.X = cursor.X - 1 >= 0
			? cursor.X - 1
			: gameSettings.cols - 1;
		return;
	}

	if (key == Key::Keys::ArrowRight) {
		cursor.X = cursor.X + 1 < gameSettings.cols
			? cursor.X + 1
			: 0;
		return;
	}

	return;
}

Field::Field()
{
	Restart();
}

Field::Field(GameSetting gameSettings): gameSettings(gameSettings)
{
	Restart();
}

void Field::Restart()
{
	GenerateField();

	gameOver = win = false;
	cursor = Coord(0, 0);
}

void Field::Restart(GameSetting gameSettings)
{
	this->gameSettings = gameSettings;
	GenerateField();

	gameOver = win = false;
	cursor = Coord(0, 0);
}

void Field::Show()
{
	COORD pos = getxy();
	const int XTemp = pos.X;

	for (int i = 0; i < gameSettings.rows; i++) {
		for (int j = 0; j < gameSettings.cols; j++) {
			char buffer[2] = { 0 };
			buffer[0] = (field[i][j].revealed || gameOver
				? field[i][j].value
				: '#');

			Color::RPrint(buffer,
				Color::White,
				Coord(j, i) == cursor
					? gameOver
						? Color::Red
						: Color::Green
					: field[i][j].marker
						? Color::Cyan
						: gameOver
							? field[i][j].revealed
								? Color::Brown
								: Color::LightMagenta
							: Color::Black
			);

			field[i][j].coord = pos;
			pos.X += 2;

			gotoxy(pos);
		}

		pos.X = XTemp;
		pos.Y += 2;
		gotoxy(pos);
	}

	Color::RPrint("Enter", Color::Cyan);
	std::cout << " - ќткрыть €чейку\t";

	Color::RPrint("F", Color::Magenta);
	std::cout << " - " << (field[cursor.Y][cursor.X].marker ? "убрать" : "установить") << " маркер\t";

	std::cout << std::endl;
}

void Field::RevealCell(int x, int y)
{
	if (x < 0 || x >= gameSettings.cols || 
		y < 0 || y >= gameSettings.rows || 
		field[y][x].revealed) {
		return;
	}

	field[y][x].revealed = true;

	if (field[y][x].value != '.' && field[y][x].value != '0')
	{
		return;
	}

	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			if (dx != 0 || dy != 0)
			{
				RevealCell(x + dx, y + dy);
			}
		}
	}
}

void Field::SetMarker()
{
	field[cursor.Y][cursor.X].marker = !field[cursor.Y][cursor.X].marker;
}

void Field::Action(Key::Keys key)
{
	if (key == Key::Keys::Undefined) {
		return;
	}

	if (key == Key::Keys::F) {
		return SetMarker();
	}

	if (key != Key::Keys::Enter) {
		return MoveCursor(key);
	}

	if (field[cursor.Y][cursor.X].value == '*') {
		gameOver = true;
		RevealCell(cursor.X, cursor.Y);
		return CheckWin();
	}

	if (field[cursor.Y][cursor.X].revealed) {
		return;
	}

	RevealCell(cursor.X, cursor.Y);
	CheckWin();
}

bool Field::IsOver()
{
	return gameOver;
}

bool Field::IsWin()
{
	return win;
}
