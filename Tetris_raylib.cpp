// Tetris_raylib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <raylib.h>

int main()
{
    InitWindow(500, 600, "raylib Tetris");// open window size 300x600 
    SetTargetFPS(60);// must set so game will run- otherwise stuck at startuo - BEFORE GAME LOOP
    // Struct color = {R,G,B,alpha} - 0-255 values, alpha is transparancy
    Color darkBlue = { 50,50,127,255 };
    while (WindowShouldClose() == false)// will run until esc key is pressed
    {
        BeginDrawing();//creates blank canvas so we can draw
        ClearBackground(darkBlue);// change backround color


        EndDrawing();// end canvas drawing
    }

    CloseWindow();//close window
}

