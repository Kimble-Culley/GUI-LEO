#include "raylib.h"
#include "status.h"

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

void Status::GetPiStatus(){

}