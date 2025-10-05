#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include "raylib.h"
#include <string>
#include <iostream>

class TextInput{

private:
    Rectangle textBox;
    std::string text;
    bool active = false;
    int fontSize;
    Color boxColor;
    Color textColor;

public:

TextInput(Rectangle rect, int fontSize = 20, Color boxColor = LIGHTGRAY, Color textColor = BLACK);

void UpdateText(Vector2 MouseButton);
void DrawBox();
std::string GetText() const;
void Clear();

};



#endif //TEXTINPUT_H