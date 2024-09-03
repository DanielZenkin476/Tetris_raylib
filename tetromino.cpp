#include <tetromino.h>

tetromino::tetromino() {//Ctor
	cellSize = 30;
	rotationState = 0;
	colors = GetCellcolors();
	row_offset = 0;
	col_offset = 3;// ofset to spawn in middle of screen 
	id = 0;
}


void tetromino::Draw(int offsetx, int offsety) {//Draws tetromino
	std::vector<Position> tiles = GetCellPos();// Get Cell pos
	for (Position item : tiles) {//loops over al items' draws a rectangle in each position to draw the tetromino
		DrawRectangle(item.col * cellSize + 1+offsetx, item.row * cellSize + 1+ offsety, cellSize - 1, cellSize - 1, colors[id]);
	}
}

void tetromino::Move(int row, int col) {// moves tetromino by row/col
	col_offset += col;
	row_offset += row;
}

std::vector<Position> tetromino::GetCellPos() {//returns Cell position of tetromino
	std::vector<Position> tiles = cells[rotationState];// get rotation state 
	std::vector<Position> moved;// new vector for real pos
	for (Position item : tiles) { 
		Position NewPos = Position(item.row + row_offset, item.col + col_offset);// adds offset to each position of rotation state
		moved.push_back(NewPos);
	}
	return moved;
}
void tetromino::Rotate() {//rotate
	rotationState++;
	rotationState = rotationState % 4;// to reset if bigger then 4
}
void tetromino::RotateBack() {//rotate back
	rotationState--;
	rotationState = rotationState % 4;// to reset if bigger then 4
}
