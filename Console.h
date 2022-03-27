#pragma once
#include <windows.h>

using namespace std;


class Console {

private:
    static inline HANDLE console_ = GetStdHandle(STD_OUTPUT_HANDLE);

public:

    static void offCursorVisability();

    static void setCursorPos(int, int);

    static void setCursorPos(COORD);

    static void setFont();

    static void setColor(int);

    static void flash(int count);
    
    static void setup();


};