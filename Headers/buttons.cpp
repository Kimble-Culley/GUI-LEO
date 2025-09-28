#include "raylib.h"
#include "buttons.h"
#include <iostream>


void Buttons::DrawButton(){
    DrawRectangleRec(buttonParam,buttonColor);
    int textWidth = MeasureText(Text.c_str(),FontSize);
    int textX = buttonParam.x + (buttonParam.width - textWidth)/2;
    int textY = buttonParam.y + (buttonParam.height - FontSize)/2;
    DrawText(Text.c_str(),textX,textY,FontSize,BLACK);
}

bool Buttons::Collison(Vector2 Mouse){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if(CheckCollisionPointRec(Mouse,buttonParam)){
            return true;
        }
    }
    return 0;
}

void Buttons::UpdatePositon(Rectangle newRect){
    buttonParam = newRect;
}

Rectangle Buttons::getRect() const{
    return buttonParam; 
}