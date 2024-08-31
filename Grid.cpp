#include <grid.h>
#include <iostream>
#include <vector>

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
std::vector<Color> Grid::GetCellcolors() {// all colors
	const Color darkGrey = { 26, 31, 40, 255 };
	const Color green = { 47, 230, 23, 255 };
	const Color red = { 232, 18, 18, 255 };
	const Color orange = { 226, 116, 17, 255 };
	const Color yellow = { 237, 234, 4, 255 };
	const Color purple = { 166, 0, 247, 255 };
	const Color cyan = { 21, 204, 209, 255 };
	const Color blue = { 13, 64, 216, 255 };
	return{ darkGrey, green, red, orange, yellow, purple, cyan, blue };
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