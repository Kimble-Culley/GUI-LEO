#include "raylib.h"
#include "status.h"


//Draws the status of the connect to the raspberry pi in the form of a colored circle
//Gray means no connect
//Red means failed connection
//Green means connected
void Status::DrawStatus(int status){
    int X = GetScreenWidth();
    int Y = GetScreenHeight();
    DrawText("Pi Status",X-250,Y-50,40,BLACK);
    
    switch (status)
    {
    case 0:
        DrawCircle(X-30,Y-30,25,GRAY);
        break;
    
    default:
        break;
    }
}

//Will attempt to ssh into the raspberry pi
void Status::GetPiStatus(){

}


//Draws a box displaying current status along with other parameters
void Status::DrawInfo(){
    int Height = GetScreenHeight();
    int Width = GetScreenWidth();
    float screenWscale = 0.5f;
    float screenHscale = 0.5f;
    int x = 20;
    float y = Height-(Height*screenHscale)-20;

    DrawRectangle(x,y,(Width*screenWscale),(Height*screenHscale),BLACK);


}