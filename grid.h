
#pragma once // to make sure header file is included only once in a compalation
#include <vector>
#include <raylib.h>
using namespace std; 
class Grid {
	// grid Class- saves the grid layout with locked blocks,draws the grid and check and clear full rows
public:
	Grid();// Ctor
	int grid[20][10];// grid 2D matrix to keep blocks
	void Initialize();// Init grid object function
	void print();//function to print out value of each cell in grid on cmd
	void Draw();//function to draw value of each cell in grid on window(canvas)
	bool IsOut(int row, int column);// checks if a position( row , col) is out of bounds and checks if location is empty in grid (collision)
	int ClearFullRows();// checks rows and clears full row
private:
	int nRows;// keps row number
	int nCols;// keeps col number
	int cellsize;// keeps cellsize
	std::vector<Color> colors;//vector of colors for visualization
	bool IsRowFull(int row);//checks if row at var row is full
	void ClearRow(int row);// 
	void MoveRowsDown(int row);// moves rows down from row to 0
	bool CombineRowsCheck(int row);//cheks if the bottom row that fell and the top row that didnt fall can be combined to one- if yes return true
	// clears row at index row and moves all rows down by one
};