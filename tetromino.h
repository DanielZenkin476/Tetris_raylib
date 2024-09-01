#pragma once
#include <Position.h>
#include <vector>
#include <map>
#include <colors.h>

class tetromino
{
public:
	tetromino();
	void Draw();
	void Move(int row, int col);
	std::vector<Position> GetCellPos();
	void Rotate();
	void RotateBack();
	int id;
	std::map<int,std::vector<Position>> cells;

private:
	int cellSize;
	int rotationState;
	std::vector<Color> colors;
	int row_offset;
	int col_offset;
};

