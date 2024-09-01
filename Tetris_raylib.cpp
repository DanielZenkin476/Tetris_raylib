// Tetris_raylib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <raylib.h>
#include <colors.h>
#include <Game.h>

using namespace std;

int main()
{
    InitWindow(300, 600, "raylib Tetris");// open window size 300x600 
    SetTargetFPS(60);// must set so game will run- otherwise stuck at startuo - BEFORE GAME LOOP
    // Struct color = {R,G,B,alpha} - 0-255 values, alpha is transparancy

    
    Game game = Game();


    while (WindowShouldClose() == false)// will run until esc key is pressed
    {
        game.HandleInput();
        BeginDrawing();//creates blank canvas so we can draw
        ClearBackground(darkBlue);// change backround color
        game.Draw();
        EndDrawing();// end canvas drawing
    }

    CloseWindow();//close window
}

