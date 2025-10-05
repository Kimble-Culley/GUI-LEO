#include "raylib.h"
#include <string>
#include <iostream>
#include "textInput.h"



TextInput::TextInput(Rectangle rect, int fontSize, Color boxColor, Color textColor)
: textBox(rect), fontSize(fontSize), boxColor(boxColor), textColor(textColor) {}

void TextInput::UpdateText(Vector2 mousePos){

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        active = CheckCollisionPointRec(mousePos, textBox);
    }

    if(active){
        int key = GetCharPressed();


        while(key > 0){
            if(key >= 32 && key <= 125){
                text += static_cast<char>(key);
            }
            key = GetCharPressed();
        }
    }

    if(IsKeyPressed(KEY_BACKSPACE) && !text.empty()){
        text.pop_back();
    }
}

void TextInput::DrawBox(){
    Color drawColor = active ? RAYWHITE : boxColor;

    DrawRectangleRec(textBox, drawColor);
    DrawRectangleLinesEx(textBox,2,DARKGRAY);

    DrawText(text.c_str(), textBox.x + 8, textBox.y + (textBox.height/4), fontSize, textColor);

}

std::string TextInput::GetText() const {
    return text;
}

void TextInput::Clear(){
    text.clear();
}

