#include "raylib.h"
#include <string>
#include <iostream>
#include "textInput.h"
#include "files.h"



TextInput::TextInput(Rectangle rect, int fontSize, Color boxColor, Color textColor)
: textBox(rect), fontSize(fontSize), boxColor(boxColor), textColor(textColor) {}

void TextInput::UpdateText(Vector2 mousePos,Files &csvFile){


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

        if(IsKeyPressed(KEY_BACKSPACE) && !text.empty()){
            text.pop_back();
        }

        if(IsKeyPressed(KEY_ENTER)){
            csvFile.updateFileName(text);
            csvFile.readCSV();
        }

    }
}

void TextInput::DrawBox(){
    fontSize = static_cast<int>(textBox.width/18);
    Color drawColor = active ? RAYWHITE : boxColor;

    DrawRectangleRec(textBox, drawColor);
    DrawRectangleLinesEx(textBox,2,DARKGRAY);

    DrawText(text.c_str(), textBox.x + 8, textBox.y + (textBox.height/4), fontSize, textColor);

}

void TextInput::UpdateBoxPosition(float parentX, float parentY, float parentW, float parentH, float relX, float relY, float relW, float relH){
    textBox.x = parentX+parentW*relX;
    textBox.y = parentY+parentH*relY;
    textBox.width = parentW * relW;
    textBox.height = parentH * relH;
}



std::string TextInput::GetText() const {
    return text;
}

void TextInput::Clear(){
    text.clear();
}

