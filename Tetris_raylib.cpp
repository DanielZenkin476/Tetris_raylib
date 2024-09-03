// Tetris_raylib.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <raylib.h>
#include <colors.h>//colors file
#include <Game.h>//main game file

using namespace std;

double lastUpdateTime = 0.0;// to manage block movment downwards

bool EventTriggered(double interval) {
    // function to check if time between current time and last check time is more then interval- if yes return true
    double currTime = GetTime();
    if (interval <= currTime - lastUpdateTime) {
        lastUpdateTime = currTime;
        return true;
    }
    return false;
}


int main()
{
    InitWindow(510, 600, "Tetris");// size of window
    SetTargetFPS(60);// sets Game Target FPS
   

    Font font = LoadFontEx("Font/hpsimplifiedjpan-regular.ttf", 64, 0, 0);// font for display
    Game game = Game();
    double interval = 1.0;// to count time between blocks fall
    int count = 0;// var to count amount of times a block has fallen - to change interval
    while (WindowShouldClose() == false)// will run until esc key is pressed
    {
       // countdown = countdown + rate;
        game.HandleInput();
        if (EventTriggered(interval)) {
            game.MoveBlockDown();// move block down if interval has passed
            if (interval > 0.5 && count == 100) {// decrease interval if conditions are met
                interval -= 0.1;
            }
        }

        BeginDrawing();//creates blank canvas so we can draw
        ClearBackground(darkBlue);// change backround color

        DrawTextEx(font, "Score", {365,15},38,2,WHITE);// draw Score
        DrawTextEx(font, "Next", { 370,175 }, 38, 2, WHITE);//fraw next
        if (game.gameOver) {// check for game over and display Game Over if true
            DrawTextEx(font, "Game Over", { 310,450 }, 40, 2, WHITE);
        }
        DrawRectangleRounded({ 320, 55, 170, 60 }, float(0.3), 6, lightBlue);// rectangle for score
        // drawing the score
        char scoreText[10];
        sprintf_s(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, { 310 +(170-textSize.x)/2,65}, 38, 2, WHITE);//draw score centered
        //draw rectangle for next block- block is drawin in game class
        DrawRectangleRounded({ 320, 270, 170, 180 }, float(0.3),6, lightBlue);// for next

        game.Draw();// draw game
        EndDrawing();// end canvas drawing
        
    }

    CloseWindow();//close window
}

