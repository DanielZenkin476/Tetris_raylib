#include <grid.h>
#include <iostream>
#include <vector>
#include <colors.h>

using namespace std;


Grid::Grid()
{
	nRows = 10;
	nCols = 20;
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
	for (int x = 0; x < nRows; x++) {
		for (int y = 0; y < nCols; y++) {
			int cellvalue = grid[x][y];
			//void DrawRectangle(int posx, int poy, int width ,int height, Color color) -draws a rectangle

			DrawRectangle(x * cellsize+ 1, y * cellsize+1, cellsize-1, cellsize-1, colors[cellvalue]);
		}
	}
}