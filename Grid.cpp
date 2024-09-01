#include <grid.h>
#include <iostream>
#include <vector>
#include <colors.h>

using namespace std;


Grid::Grid()
{
	nRows = 20;
	nCols = 10;
	cellsize = 30;
	Initialize();
	colors = GetCellcolors();
}

void Grid::Initialize() {// Init Grid to be 0 
	
	for (int x = 0; x < nRows; x++) {
		for (int y = 0; y < nCols; y++) {
			grid[x][y] = 0;
		}
	}
}

void Grid::print() {
	for (int x = 0; x < nRows; x++) {
		for (int y = 0; y < nCols; y++) {
			cout << grid[x][y] << " ";
		}
	}
	cout << endl;
}


void Grid::Draw() {
	for (int x = 0; x < nCols; x++) {
		for (int y = 0; y < nRows; y++) {
			int cellvalue = grid[y][x];
			//void DrawRectangle(int posx, int poy, int width ,int height, Color color) -draws a rectangle

			DrawRectangle(x * cellsize+ 1, y * cellsize+1, cellsize-1, cellsize-1, colors[cellvalue]);
		}
	}
}

bool Grid::IsOut(int row, int col)
{
	if (row >= 0 and row < nRows and col >= 0 and col < nCols and grid[row][col] == 0) {// 0 check to make sure there is no collisions with other exsisting blocks
		return false;
	}
	return true;
}

int Grid::ClearFullRows()
{
	int completed = 0;
	for (int i = 0; i < nRows; i++) {
		if (IsRowFull(i)) {
			ClearRow(i);
			completed++;
			i = 0;// back to check from top in case of double complete
		}
	}
	return completed;
}

bool Grid::IsRowFull(int row)
{
	for (int i = 0; i < nCols; i++) {
		if (grid[row][i] == 0) return false;
	}
	return true;
}

void Grid::ClearRow(int row) {// clears row and moves all rows down 
	for (int i = 0; i < nCols; i++) {
		grid[row][i] = 0;
	}// works 
	if (row == 0) {
		// means that game is over
	}// move row down
	for (int r = row; r > 0;r--) {
		for (int i = 0; i < nCols; i++) {
			grid[r][i] = grid[r - 1][i];
		}
	}

}




