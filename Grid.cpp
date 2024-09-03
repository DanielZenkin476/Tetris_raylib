#include <grid.h>
#include <iostream>
#include <vector>
#include <colors.h>

using namespace std;


Grid::Grid()//Ctor
{
	nRows = 20;//num of rows
	nCols = 10;//nom of columns
	cellsize = 30;//cellsize
	Initialize();// init Grid grid
	colors = GetCellcolors();// gets colors from colors.h
}

void Grid::Initialize() {// Init Grid to be 0 in all cells 
	
	for (int x = 0; x < nRows; x++) {
		for (int y = 0; y < nCols; y++) {
			grid[x][y] = 0;
		}
	}
}

void Grid::print() {// prints out all elements of grid
	for (int x = 0; x < nRows; x++) {
		for (int y = 0; y < nCols; y++) {
			cout << grid[x][y] << " ";
		}
	}
	cout << endl;
}


void Grid::Draw() {//Draws the current grid
	for (int x = 0; x < nCols; x++) {
		for (int y = 0; y < nRows; y++) {
			int cellvalue = grid[y][x];
			//void DrawRectangle(int posx, int poy, int width ,int height, Color color) -draws a rectangle
			//decrease cellsize by 1 in width and hight so we get a line seperating blocks
			DrawRectangle(x * cellsize+ 1, y * cellsize+1, cellsize-1, cellsize-1, colors[cellvalue]);
		}
	}
}

bool Grid::IsOut(int row, int col)// checks if row and col are out of array and checks if cell equal to zer- if not block is there and cant move, true on out of bounds, false on good location
{
	if (row >= 0 and row < nRows and col >= 0 and col < nCols and grid[row][col] == 0) {// 0 check to make sure there is no collisions with other exsisting blocks
		return false;
	}
	return true;
}

int Grid::ClearFullRows()// checks rows from the top to bottom for full rows and clears them
{
	int completed = 0;// var to check amount of rows that are complete
	for (int i = 0; i < nRows; i++) {
		if (IsRowFull(i)) {
			ClearRow(i);
			completed++;
			i = 0;// back to check from top in case of double complete(fallen row completes a row- dont want to miss it, but it is very rare
		}
	}
	return completed;
}

bool Grid::IsRowFull(int row)// checks if row is full - true if full, else false
{
	for (int i = 0; i < nCols; i++) {
		if (grid[row][i] == 0) return false;
	}
	return true;
}

void Grid::ClearRow(int row) {// clears row and moves all rows down 
	// reset current row
	for (int i = 0; i < nCols; i++) {
		grid[row][i] = 0;
	}
	// move down all rows by one)
	MoveRowsDown(row);
	// now we check if the bottom row that fell and the top row that didnt fall can be combined to one
	if (CombineRowsCheck(row)) {
		// loop to combine 2 rows -we checkd already
		for (int i = 0; i < nCols; i++) {
			grid[row][i] += grid[row - 1][i];
		}
		// now we need to move all rows down again 
		MoveRowsDown(row + 1);
	}
}
void Grid::MoveRowsDown(int row) {// Moves down rows from row down to 0 (0 is top row)
	for (int r = row; r > 0;r--) {
		for (int i = 0; i < nCols; i++) {
			grid[r][i] = grid[r - 1][i];
		}
	}
}

bool Grid::CombineRowsCheck(int row) {//Checks if the bottom row that fell and the top row that didnt fall can be combined to one
	if (row == nRows - 1) return false;// means this was the bottom row - no need for check
	for (int i = 0; i < nCols; i++) {
		if (grid[row][i] != 0 && grid[row - 1][i] != 0) return false;
	}
	return true;
}




