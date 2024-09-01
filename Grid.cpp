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
	if (row >= 0 and row < nRows and col >= 0 and col < nCols) {
		return false;
	}
	return true;
}

