#include "raylib.h"
#include "buttons.h"
#include <iostream>


void Buttons::DrawButton(){
    DrawRectangleRec(buttonParam,buttonColor);
    DrawText(Text.c_str(),(buttonParam.x)+((buttonParam.width)/2)-(FontSize/2)-(Text.length()*2),(buttonParam.y)+((buttonParam.height)/2)-(FontSize/2),FontSize,BLACK);
}

void Buttons::Collison(Vector2 Mouse){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if(CheckCollisionPointRec(Mouse,buttonParam)){
            std::cout << "yep" << std::endl;
        }
    }
}