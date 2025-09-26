#include <iostream>
#include "raylib.h"
#include "buttons.h"

int main(){

const int screenWidth = 1440;
const int screenHeight = 1080;
InitWindow(screenWidth,screenHeight,"Test Window For GUI");

SetTargetFPS(60);

Buttons button1({200,200,400,150},GRAY,"Hello",20);

while(!WindowShouldClose()){
    Vector2 mousePos = GetMousePosition();
    button1.Collison(mousePos);
    /*
    //First Button is start scan from raspberryPI
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if(CheckCollisionPointRec(mousePos, button1)){
            std::cout << "I clicked the button" << std::endl;
            //script.sendToRaspberryPi (runScanProgram)
        }
    }

    */


    BeginDrawing();
    ClearBackground(WHITE);

    button1.DrawButton();

    EndDrawing();
    
}

CloseWindow();
return 0;
}