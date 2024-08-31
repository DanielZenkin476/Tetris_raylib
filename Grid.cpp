#include <grid.h>
#include <iostream>
using namespace std;
Grid::Grid()
{
	nRows = 20;
	nCols = 10;
	cellsize = 30;
	Initialize();
}

void Grid::Initialize() {// Init Grid to be 0 
	
	for (int x = 0; x < nRows; x++) {
		for (int y = 0; y < nCols; y++) {
			grid[x][y] = 0;
		}
	}
}
int Grid::GetColms() { return nCols; }
int Grid::GetRows() { return nRows; }

void Grid::print() {
	cout << nRows;
	cout << nCols;
	for (int x = 0; x < nRows; x++) {
		for (int y = 0; y < nCols; y++) {
			cout << grid[x][y] << " ";
		}
	}
	cout << endl;
}