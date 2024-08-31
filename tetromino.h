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

	int id;

	std::map<int,std::vector<Position>> cells;



private:
	int cellSize;
	int rotationState;
	std::vector<Color> colors;
};

