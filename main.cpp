#include <iostream>
#include "raylib.h"
#include "Headers/buttons.h"
#include "Headers/status.h"

struct bLayout{
    float border = 20;
    float buttonWidthRatio = 0.25f;
    float buttonHeightRatio = 0.1f;
    float smButtonWidthRation = 0.125f;
    float smButtonHeightRation = 0.04f;
    float connectButtonWidth = 200;
    float connectButtonHeight = 50;
};


int main(){
bLayout layout;
const int screenWidth = 1440;
const int screenHeight = 1080;


//Test variables for removal
int tester = 0;

InitWindow(screenWidth,screenHeight,"Test Window For GUI");

SetTargetFPS(60);

Buttons button1({layout.border,layout.border,screenWidth*layout.buttonWidthRatio,screenHeight*layout.buttonHeightRatio},LIGHTGRAY,"Hello",20);
Buttons button2({layout.border,190,400,150},LIGHTGRAY,"Click Me",20);
Buttons button3({layout.border+button1.getRect().width,layout.border,screenWidth*layout.buttonWidthRatio,screenHeight*layout.buttonHeightRatio},LIGHTGRAY,"Hello",20);
Buttons ConnectToPi({screenWidth-300,screenHeight-300,200,50},LIGHTGRAY,"Connect to PI",20);
Status PiStatus;



while(!WindowShouldClose()){
    float NewScreenWidth = GetScreenWidth();
    float NewScreenHeight = GetScreenHeight();

    button1.UpdatePositon({layout.border,layout.border,NewScreenWidth*layout.buttonWidthRatio,NewScreenHeight*layout.buttonHeightRatio});
    button2.UpdatePositon({layout.border,(layout.border)*2 + NewScreenHeight*layout.buttonHeightRatio,NewScreenWidth*layout.buttonWidthRatio,NewScreenHeight*layout.buttonHeightRatio});
    button3.UpdatePositon({layout.border*2+button1.getRect().width,layout.border,NewScreenWidth*layout.smButtonWidthRation,NewScreenHeight*layout.smButtonHeightRation});
    ConnectToPi.UpdatePositon({NewScreenWidth-250,NewScreenHeight-120,layout.connectButtonWidth,layout.connectButtonHeight});

    Vector2 mousePos = GetMousePosition();

    if(button1.Collison(mousePos)){
        system("ls");
    }
    
    if(button2.Collison(mousePos)){
        system("~/3Drenderer/Open3D/build/test_open3d");
    }

    if(ConnectToPi.Collison(mousePos)){
        tester = 1;
    }




    BeginDrawing();
    ClearBackground(WHITE);
    

    DrawText("LEO",(NewScreenWidth)-350,layout.border,100,BLACK);

    button1.DrawButton();
    button2.DrawButton();
    button3.DrawButton();
    ConnectToPi.DrawButton();
    PiStatus.DrawStatus(tester);
    PiStatus.DrawInfo();


    DrawFPS(20,20);
    EndDrawing();
    
}

CloseWindow();
return 0;
}