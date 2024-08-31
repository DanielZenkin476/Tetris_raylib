#pragma once // to make sure header file is included only once in a compalation

class Grid {

public:
	Grid();
	void Initialize();
	int grid[20][10];
	void print();
	int GetRows();
	int GetColms();
private:
	int nRows =20;
	int nCols =10;
	int cellsize =30;

};