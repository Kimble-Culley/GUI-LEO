#include <iostream>
#include "raylib.h"
#include "Headers/buttons.h"
#include "Headers/status.h"
#include "Headers/files.h"
#include "Headers/textInput.h"



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
Files csvFile;


csvFile.readCSV();
csvFile.loadPiConfig();


const int screenWidth = 1440;
const int screenHeight = 1080;



InitWindow(screenWidth,screenHeight,"Test Window For GUI");

SetTargetFPS(60);

TextInput inputFileBox({screenWidth/2,screenHeight/2,400,50},24);

Buttons ButtonStartScan({layout.border,layout.border,screenWidth*layout.buttonWidthRatio,screenHeight*layout.buttonHeightRatio},LIGHTGRAY,"Start Scan",20);
Buttons ButtonOpenScan({layout.border,190,400,150},LIGHTGRAY,"OpenScan",20);
Buttons ButtonScanMode({layout.border+ButtonStartScan.getRect().width,layout.border,screenWidth*layout.buttonWidthRatio,screenHeight*layout.buttonHeightRatio},LIGHTGRAY,"Scan Mode",20);
Buttons ButtonLocateFiles({layout.border+ButtonOpenScan.getRect().width,layout.border,screenWidth*layout.buttonWidthRatio,screenHeight*layout.buttonHeightRatio},LIGHTGRAY,"Locate Files",20);
Buttons ButtonRetriveFies({layout.border+ButtonOpenScan.getRect().width,layout.border,screenWidth*layout.buttonWidthRatio,screenHeight*layout.buttonHeightRatio+layout.border},LIGHTGRAY,"Retrive Files",20);
Buttons ConnectToPi({screenWidth-300,screenHeight-300,200,50},LIGHTGRAY,"Connect to PI",20);
Status PiStatus;




while(!WindowShouldClose()){
    float NewScreenWidth = GetScreenWidth();
    float NewScreenHeight = GetScreenHeight();

    ButtonStartScan.UpdatePositon({layout.border,layout.border,NewScreenWidth*layout.buttonWidthRatio,NewScreenHeight*layout.buttonHeightRatio});
    ButtonOpenScan.UpdatePositon({layout.border,(layout.border)*2 + NewScreenHeight*layout.buttonHeightRatio,NewScreenWidth*layout.buttonWidthRatio,NewScreenHeight*layout.buttonHeightRatio});
    ButtonScanMode.UpdatePositon({layout.border*2+ButtonStartScan.getRect().width,layout.border,NewScreenWidth*layout.smButtonWidthRation,NewScreenHeight*layout.smButtonHeightRation});
    ButtonLocateFiles.UpdatePositon({layout.border*2+ButtonOpenScan.getRect().width,layout.border*2 + NewScreenHeight*layout.buttonHeightRatio,NewScreenWidth*layout.smButtonWidthRation,NewScreenHeight*layout.smButtonHeightRation});
    ButtonRetriveFies.UpdatePositon({layout.border*2+ButtonOpenScan.getRect().width,layout.border*2 + NewScreenHeight*layout.buttonHeightRatio+ButtonLocateFiles.getRect().height+20,NewScreenWidth*layout.smButtonWidthRation,NewScreenHeight*layout.smButtonHeightRation});

    ConnectToPi.UpdatePositon({NewScreenWidth-250,NewScreenHeight-120,layout.connectButtonWidth,layout.connectButtonHeight});

    Vector2 mousePos = GetMousePosition();


    if(ButtonStartScan.Collison(mousePos)){
        std::string cmd = "ssh " + csvFile.getsshUser() + "@" + csvFile.getsshHost() + " 'cd ~/Lidar-Exploration-Operator/2dMapping/LidarHardware/src && ./lidar'";
        system(cmd.c_str());
        PiStatus.changeState(1);
    }
    
    if(ButtonOpenScan.Collison(mousePos)){
        PiStatus.changeState(0);
        //std::string cmd = "~/3Drenderer/Open3D/tester/build/view_csv " + csvFile.getFileName();
        //system(cmd.c_str());
        system(
        "powershell.exe -Command \"cd 'C:\\\\Users\\\\Kimble\\\\Documents\\\\testCode'; "
        "python .\\app.py\""
    );

    }

    if(ButtonLocateFiles.Collison(mousePos)){
        csvFile.findFiles();
        PiStatus.changeState(3);
    }

    if(ButtonRetriveFies.Collison(mousePos)){
        
    }

    if(ConnectToPi.Collison(mousePos)){
        PiStatus.GetPiStatus(csvFile);
    }

    inputFileBox.UpdateText(mousePos,csvFile);

    bool clickedButton = 
    ButtonStartScan.Collison(mousePos)||
    ButtonOpenScan.Collison(mousePos)||
    ConnectToPi.Collison(mousePos)||
    ButtonScanMode.Collison(mousePos) ||
    ButtonLocateFiles.Collison(mousePos);

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !clickedButton && !inputFileBox.getActive()){
        PiStatus.changeState(0);
    }


    BeginDrawing();
    ClearBackground(WHITE);
    

    DrawText("LEO",(NewScreenWidth)-350,layout.border,100,BLACK);

    ButtonStartScan.DrawButton();
    ButtonOpenScan.DrawButton();
    ButtonScanMode.DrawButton();
    ButtonLocateFiles.DrawButton();
    ButtonRetriveFies.DrawButton();
    ConnectToPi.DrawButton();
    PiStatus.DrawStatus();
    PiStatus.DrawInfo(csvFile,inputFileBox);

    inputFileBox.DrawBox();


    DrawFPS(20,20);
    EndDrawing();
    
}

CloseWindow();
return 0;
}