#include <iostream>
#include "raylib.h"
#include "Headers/buttons.h"

int main(){

const int screenWidth = 1440;
const int screenHeight = 1080;
const int border = 20;
InitWindow(screenWidth,screenHeight,"Test Window For GUI");

SetTargetFPS(60);

Buttons button1({border,border,400,150},LIGHTGRAY,"Hello",20);
Buttons button2({border,190,400,150},LIGHTGRAY,"Click Me",20);
Buttons ConnectToPi({screenWidth-300,screenHeight-300,200,50},LIGHTGRAY,"Connect to PI",20);



while(!WindowShouldClose()){
    Vector2 mousePos = GetMousePosition();

    if(button1.Collison(mousePos)){
        system("ls");
    }
    
    if(button2.Collison(mousePos)){
        system("~/3Drenderer/Open3D/build/test_open3d");
    }




    BeginDrawing();
    ClearBackground(WHITE);

    DrawText("LEO",(screenWidth/2)-100,20,100,BLACK);

    button1.DrawButton();
    button2.DrawButton();
    ConnectToPi.DrawButton();

    EndDrawing();
    
}

CloseWindow();
return 0;
}