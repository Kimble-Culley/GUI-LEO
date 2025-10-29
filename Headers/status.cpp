#include <vector>
#include <filesystem>
#include <iostream>
#include <string>
#include <cmath>
#include "files.h"
#include "raylib.h"
#include "status.h"
#include "textInput.h"

namespace fs = std::filesystem;


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
int Status::GetPiStatus(Files &fromFile){

    std::string cmd = "ssh " + fromFile.getsshUser() + "@" + fromFile.getsshHost() + " '~/RemoteTest/test'";
    int result = system(cmd.c_str());

    currentCode = WEXITSTATUS(result);

    return currentCode;
}


//Draws a box displaying current status along with other parameters
void Status::DrawInfo(Files &fromFile, TextInput &inputFileBox){
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

    inputFileBox.UpdateBoxPosition(x,y,screenW,screenH,0.1f,0.8f,0.8f,0.1f);
    

    //Text Section
    std::vector<std::string> statusText;
    
    switch (currentState)
    {
    case 1:
        statusText.clear();
        statusText.push_back("Starting Scan be still");
        break;

    case 2:
        statusText.clear();
        statusText.push_back("Attempting to open " +fromFile.getFileName());
        break;

    case 3:
        statusText.clear();
        statusText.push_back("Locating files");
        for(auto &item : fromFile.getFileList()){
            statusText.push_back(item);
        }
        break;
    default:
        statusText.clear();
        statusText.push_back("Current File: " + fromFile.getFileName());
        statusText.push_back("File Size: " + std::to_string(fs::file_size(fromFile.getFileName())/1024) + " KB");
        statusText.push_back("Number of points: "+ std::to_string(points));
        break;
    }   
    
    


    int FontSize = static_cast<int>(screenW/25);
    Color col = LIME;
    x += 5;
    y += 5;

    for(int i = 0; i < static_cast<int>(statusText.size()); i++){
        DrawText(statusText[i].c_str(),x,y+(FontSize*i),FontSize,col);
    }
}




void Status::changeState(int state){
    currentState = state;
}