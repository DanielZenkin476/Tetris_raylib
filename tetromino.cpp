#include <tetromino.h>

tetromino::tetromino() {
	cellSize = 30;
	rotationState = 0;
	colors = GetCellcolors();
}


void tetromino::Draw() {
	std::vector<Position> tiles = cells[rotationState];
	for (Position item : tiles) {
		DrawRectangle(item.col * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
	}
}