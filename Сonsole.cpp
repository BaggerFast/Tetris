#include "Ñonsole.h"

void Console::offCursorVisability()
{
    CONSOLE_CURSOR_INFO structCurInf;
    GetConsoleCursorInfo(console, &structCurInf);
    structCurInf.bVisible = false;
    SetConsoleCursorInfo(console, &structCurInf);
}

void Console::setCursorPos(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(console, coord);
}

void Console::setCursorPos(COORD coord)
{
    SetConsoleCursorPosition(console, coord);
}

void Console::setFont()
{
    CONSOLE_FONT_INFOEX text;
    text.cbSize = sizeof(text);
    text.dwFontSize.Y = 36;
#pragma warning(suppress : 4996)
    wcscpy(text.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(console, FALSE, &text);
}

void Console::clear()
{
    system("cls");
}

void Console::setup()
{
    SetConsoleCP(1251);
    offCursorVisability();
    setFont();
    system("mode con cols=40 lines=27");
    clear();
}


