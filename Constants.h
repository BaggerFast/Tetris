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