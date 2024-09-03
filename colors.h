// Object to keep Colors for display
#pragma once
#include <raylib.h>
#include<vector>


extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color darkBlue;
extern const Color lightBlue;

std::vector<Color> GetCellcolors();// function returns all colors as a vector of colors