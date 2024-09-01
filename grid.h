#pragma once // to make sure header file is included only once in a compalation
#include <vector>
#include <raylib.h>
using namespace std; 
class Grid {

public:
	Grid();
	void Initialize();
	int grid[20][10];
	void print();
	void Draw();
	bool IsOut(int row, int column);
private:
	int nRows ;
	int nCols ;
	int cellsize ;
	std::vector<Color> colors;
};