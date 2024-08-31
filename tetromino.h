#pragma once

#include <Position.h>
#include <vector>
#include <map>
class tetromino
{
public:
	tetromino();
	int id;
	std::map<int,std::vector<Position>> cells;


private:
	int cellSize;
	int RotationState;

};

