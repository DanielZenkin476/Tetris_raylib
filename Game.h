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
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
	void HandleInput();
	Grid grid;
	bool gameOver;
	int score;

private:
	std::vector<tetromino> blocks;
	tetromino currBlock;
	tetromino nextBlock;
	bool IsBlockOut();
	void RotateBlock();
	void RotateBlockBack();
	void LockBlock();
	void Reset();
};

