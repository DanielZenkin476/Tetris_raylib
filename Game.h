#pragma once
#include <grid.h>
#include <vector>
#include "Shapes.cpp"
#include <tetromino.h>

class Game{
	// Game Class- main class that is used to run the game
public:
	Game();//Ctor
	void Draw();//Draws the Game
	void MoveBlockDown();// moves current block down
	void HandleInput();//handles player input
	bool gameOver;//bool to symbolize game over- true on game over
	int score;// score of player

private:
	std::vector<tetromino> blocks;//blocks vector to choose from 
	tetromino currBlock;
	tetromino nextBlock;
	bool IsBlockOut();//checks if currblock is out of bounds
	void RotateBlock();// rotates block
	void RotateBlockBack();// rotates block back
	void LockBlock();// locks block in place - becomes part of grid
	void Reset();// resets the game
	void MoveBlockLeft();// moves block left by 1
	void MoveBlockRight();// moves block right by 1
	tetromino GetRandomBlock();// gets random block from vector of blocks blocks
	Grid grid;// grid used in game
};

