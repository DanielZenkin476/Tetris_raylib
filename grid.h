#pragma once // to make sure header file is included only once in a compalation

class Grid {

public:
	Grid();
	int grid[20][10];

private:
	int nRows;
	int nCols;
	int cellsize;

};