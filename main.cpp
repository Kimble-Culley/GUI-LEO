#include <iostream>
#include "raylib.h"
#include "buttons.h"

int main(){

const int screenWidth = 3840;
const int screenHeight = 2160;
InitWindow(screenWidth,screenHeight,"Test Window For GUI");

SetTargetFPS(60);

Rectangle button1 = {20,20,screenWidth/6,150};
Rectangle button2 = {20,190,screenWidth/6,150};

while(!WindowShouldClose()){
    Vector2 mousePos = GetMousePosition();

    //First Button is start scan from raspberryPI
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if(CheckCollisionPointRec(mousePos, button1)){
            std::cout << "I clicked the button" << std::endl;
            //script.sendToRaspberryPi (runScanProgram)
        }
    }



    BeginDrawing();
    ClearBackground(WHITE);

    DrawRectangleRec(button1,PURPLE);
    DrawRectangleRec(button2,GRAY);
    EndDrawing();
    }

CloseWindow();
return 0;
}