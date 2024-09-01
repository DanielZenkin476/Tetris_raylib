// Tetris_raylib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <raylib.h>
#include <colors.h>
#include <Game.h>


using namespace std;
double lastUpdateTime = 0.0;

bool EventTriggered(double interval) {
    double currTime = GetTime();
    if (interval <= currTime - lastUpdateTime) {
        lastUpdateTime = currTime;
        cout << currTime;
        return true;
    }
    return false;
}


using namespace std;

int main()
{
    InitWindow(510, 600, "Tetris");// open window size 300x600 
    SetTargetFPS(60);// must set so game will run- otherwise stuck at startuo - BEFORE GAME LOOP
    // Struct color = {R,G,B,alpha} - 0-255 values, alpha is transparancy
    
    Font font = LoadFontEx("Font/hpsimplifiedjpan-regular.ttf", 64, 0, 0);
    Game game = Game();
    double intervalDown = 1.0;
    double interval = 1.0;
    while (WindowShouldClose() == false)// will run until esc key is pressed
    {
       // countdown = countdown + rate;
        game.HandleInput();
        if (EventTriggered(interval)) {
            game.MoveBlockDown();
        }

        BeginDrawing();//creates blank canvas so we can draw
        ClearBackground(darkBlue);// change backround color
        DrawTextEx(font, "Score", {355,15},40,2,WHITE);
        game.Draw();
        EndDrawing();// end canvas drawing
        
    }

    CloseWindow();//close window
}

