#include "GameSetting.h"

GameSetting::GameSetting(): rows(10), cols(10), mines(20)
{
}

GameSetting::GameSetting(int rows, int cols, int mines): 
	rows(rows), cols(cols), mines(mines)
{
}

GameSetting Setting()
{
	char answ;
	std::cout << "������������ ��������� �� ���������? y/n ";
	std::cin >> answ;
	clear();

	if (std::tolower(answ) == 'y') {
		return GameSetting();
	}

	int row, cols, mines;
	std::cout << "������� ������ ����: ";
	std::cin >> cols;

	std::cout << "������� ������ ����: ";
	std::cin >> row;

	do {
		std::cout << "������� ����������� ��� (�� ������ " << row + cols << "): ";
		std::cin >> mines;
		clear();
	} while (mines <= 0 || mines >= row + cols);

	return GameSetting(row, cols, mines);
}
