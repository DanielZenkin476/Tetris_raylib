// Tetris_raylib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <raylib.h>
#include <grid.h>
#include "tetromino.h"
#include "Shapes.cpp"

using namespace std;

int main()
{
    InitWindow(300, 600, "raylib Tetris");// open window size 300x600 
    SetTargetFPS(60);// must set so game will run- otherwise stuck at startuo - BEFORE GAME LOOP
    // Struct color = {R,G,B,alpha} - 0-255 values, alpha is transparancy

    Color darkBlue = { 50,50,127,255 };
    Grid grid = Grid();// create enpty grid
    grid.print();

    SBlock block = SBlock();

    while (WindowShouldClose() == false)// will run until esc key is pressed
    {
        BeginDrawing();//creates blank canvas so we can draw
        ClearBackground(darkBlue);// change backround color
        grid.Draw();
        block.Draw();
        EndDrawing();// end canvas drawing
    }

    CloseWindow();//close window
}

