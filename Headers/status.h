#ifndef STATUS_H
#define STATUS_H

class Files;
class TextInput;

class Status{

private:
int currentCode;
int currentState;

public:
Status() : currentCode(1), currentState(0) {}
int GetPiStatus();
void DrawStatus();
void DrawInfo(Files &fromFile, TextInput &inputFileBox);
void changeState(int state);

int getCurrentCode() const { return currentCode; }
int getCurrentState() const { return currentState; }
};



#endif //STATUS_H