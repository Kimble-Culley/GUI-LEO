#include <iostream>
#include "raylib.h"
#include "buttons.h"

int main(){

const int screenWidth = 1240;
const int screenHeight = 720;
InitWindow(screenWidth,screenHeight,"Test Window For GUI");

SetTargetFPS(60);

Rectangle button1 = {300,300,500,200};

while(!WindowShouldClose()){
    Vector2 mousePos = GetMousePosition();

    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        if(CheckCollisionPointRec(mousePos, button1)){
            std::cout << "I clicked the button";
        }
    }

    BeginDrawing();
    ClearBackground(WHITE);

    DrawRectangleRec(button1,PURPLE);
    

    EndDrawing();
    }

CloseWindow();
return 0;
}