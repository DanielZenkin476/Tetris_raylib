#pragma once
#include <grid.h>
#include <vector>
#include "Shapes.cpp"
#include <tetromino.h>

class Game{
public:
	Game();
	tetromino GetRandomBlock();
	void Draw();
	Grid grid;

private:
	std::vector<tetromino> blocks;
	tetromino currBlock;
	tetromino nextBlock;
};
