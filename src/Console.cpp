#include "Console.h"

#pragma region Public Methods

#pragma region setCursorPos

void Console::setCursorPos(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(console_, coord);
}

void Console::setCursorPos(COORD coord)
{
    SetConsoleCursorPosition(console_, coord);
}

#pragma endregion

void Console::offCursorVisability()
{
    CONSOLE_CURSOR_INFO structCurInf;
    GetConsoleCursorInfo(console_, &structCurInf);
    structCurInf.bVisible = false;
    SetConsoleCursorInfo(console_, &structCurInf);
}

void Console::setFont()
{
    CONSOLE_FONT_INFOEX text;
    text.cbSize = sizeof(text);
    text.dwFontSize.Y = 36;
    #pragma warning(suppress : 4996)
    wcscpy(text.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(console_, FALSE, &text);
}

void Console::setColor(int color) 
{
    SetConsoleTextAttribute(console_, color);
}

void Console::setup()
{
    SetConsoleCP(1251);
    system("mode con cols=40 lines=27");
    offCursorVisability();
    setFont();
}

#pragma endregion