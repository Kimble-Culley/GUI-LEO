#ifndef BUTTONS_H
#define BUTTONS_H
#include "raylib.h"
#include <iostream>

class Buttons{
Rectangle buttonParam;
std::string Text;
Color buttonColor;
int FontSize;

public:
Buttons(Rectangle rec,Color col,std::string txt,int FntSz){
    buttonParam = rec;
    buttonColor = col;
    Text = txt;
    FontSize = FntSz;
}

void DrawButton();

void Collison(Vector2 Mouse);

};

#endif //BUTTONS_H