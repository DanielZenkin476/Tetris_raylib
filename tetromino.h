#pragma once
#include <Position.h>
#include <vector>
#include <map>
#include <colors.h>

class tetromino
{//tetromio Base class for all the blocks
public:
	tetromino();//Ctor
	void Draw(int offsetx, int offsety);//Draws tetromino
	void Move(int row, int col);// moves tetromino
	std::vector<Position> GetCellPos();// function to return cell positions of tetromino on grid
	void Rotate();// rotates blocks(changes rotation state)
	void RotateBack();//rotates back
	int id;//id of tetromino- to change colors
	std::map<int,std::vector<Position>> cells;

private:
	int cellSize;// cellsize
	int rotationState;// 0 to 3 - rotation state - 0, 90 ,180, 270
	std::vector<Color> colors;//colors vector
	int row_offset;// offset to spawn block correctly
	int col_offset;// offset to spawn block correctly
};

