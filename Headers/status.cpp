#include <vector>
#include <iostream>
#include <string>
#include "files.h"
#include "raylib.h"
#include "status.h"



//Draws the status of the connect to the raspberry pi in the form of a colored circle
//Gray means no connect
//Red means failed connection
//Green means connected
void Status::DrawStatus(){
    int X = GetScreenWidth();
    int Y = GetScreenHeight();
    DrawText("Pi Status",X-250,Y-50,40,BLACK);
    
    switch (currentCode)
    {
    case 1:
        DrawCircle(X-30,Y-30,25,GRAY);
        break;
    case -1:
        DrawCircle(X-30,Y-30,25,RED);
        break;
    case 0:
        DrawCircle(X-30,Y-30,25,GREEN);
        break;
    
    default:
        DrawCircleLines(X-30,Y-30,25,BLACK);
        break;
    }
}

//Will attempt to ssh into the raspberry pi
int Status::GetPiStatus(){

    int result = system("ssh cleo@192.168.1.207 '~/RemoteTest/test'");

    currentCode = WEXITSTATUS(result);

    return currentCode;
}


//Draws a box displaying current status along with other parameters
void Status::DrawInfo(Files &fromFile){
    int Height = GetScreenHeight();
    int Width = GetScreenWidth();
    float screenH = 0.5f*Height;
    float screenW = 0.5f*Width;
    int x = 20;
    float y = Height-(screenH)-20;

    //info section
    int points = fromFile.getCounter();
    




    //end info section


    //Black Background
    DrawRectangle(x,y,(screenW),(screenW),BLACK);
    

    //Text Section
    std::vector<std::string> text ={
        "Current File: " + fromFile.getFileName(),
        "Number of points: "+ std::to_string(points)
    };


    int FontSize = 30;
    Color col = LIME;
    x += 5;
    y += 5;

    for(int i = 0; i < text.size(); i++){
        DrawText(text[i].c_str(),x,y+(FontSize*i),FontSize,col);
    }
}