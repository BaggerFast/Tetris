#pragma once
#include <vector>

/// <summary>
/// Symbols for Display
/// </summary>
struct Block {
    static const char
        FIELD = char(219),
        TETROMINO = char(254),
        SPACE = char(255),
        CURSOR = char(248);
};

/// <summary>
/// Abstract Unit inside the field
/// </summary>
enum Unit {
    Space,
    Falling,
    Fallen,
    Cursor,
};

/// <summary>
/// Colors for console
/// </summary>
enum Color {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};


int getRandomColor();