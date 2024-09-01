#include <tetromino.h>

tetromino::tetromino() {
	cellSize = 30;
	rotationState = 0;
	colors = GetCellcolors();
	row_offset = 0;
	col_offset = 3;// ofset to spawn in middle of screen 
	id = 0;
}


void tetromino::Draw() {
	std::vector<Position> tiles = GetCellPos();
	for (Position item : tiles) {
		DrawRectangle(item.col * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
	}
}

void tetromino::Move(int row, int col) {
	col_offset += col;
	row_offset += row;
}

std::vector<Position> tetromino::GetCellPos() {
	std::vector<Position> tiles = cells[rotationState];
	std::vector<Position> moved;
	for (Position item : tiles) { 
		Position NewPos = Position(item.row + row_offset, item.col + col_offset);
		moved.push_back(NewPos);
	}
	return moved;
}