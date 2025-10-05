#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include "raylib.h"
#include <string>
#include <iostream>

class Files;

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

void UpdateText(Vector2 MouseButton,Files &csvFile);
void DrawBox();
void UpdateBoxPosition(float parentX, float parentY, float parentW, float parentH, float relX, float relY, float relW, float relH);


std::string GetText() const;
void Clear();
bool getActive() const { return active;}

};



#endif //TEXTINPUT_H