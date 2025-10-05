#ifndef STATUS_H
#define STATUS_H

#include "files.h"

class Status{

private:
int currentCode;

public:
Status() : currentCode(1) {}
int GetPiStatus();
void DrawStatus();
void DrawInfo(Files &fromFile);

int getCurrentCode() const { return currentCode; }

};



#endif //STATUS_H