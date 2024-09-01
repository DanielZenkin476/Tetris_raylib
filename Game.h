#pragma once
#include <grid.h>
#include <vector>
#include "Shapes.cpp"
#include <tetromino.h>

class Game{
public:
	Game();
	void Draw();
	void MoveBlockDown();
	void HandleInput();
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
	void MoveBlockLeft();
	void MoveBlockRight();
	tetromino GetRandomBlock();
	Grid grid;
};

