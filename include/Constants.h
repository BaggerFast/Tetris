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

/// <summary>
/// Declaration of all tetraminos
/// </summary>
struct Tetrominoes {
    static inline std::vector<std::vector<bool>>
        T{
            { 1, 1, 1 },
            { 0, 1, 0 },
        },
        Q{
            { 1, 1 },
            { 1, 1 },
        },
        I{
            { 1, },
            { 1, },
            { 1, },
        },
        Z{
            { 1, 1, 0 },
            { 0, 1, 1 },
        },
        S{
            { 0, 1, 1 },
            { 1, 1, 0 },
        },
        O{
            { 1 },
        },
        J{
            { 0, 1, },
            { 0, 1, },
            { 1, 1, },
        },
        L{
            { 1, 0 },
            { 1, 0 },
            { 1, 1 },
        },
        X{
            { 0, 1, 0 },
            { 1, 1, 1 },
            { 0, 1, 0 },
        },
        U{
            { 1, 0, 1 },
            { 1, 1, 1 },
        };
};

/// <summary>
/// Get random color for Console without black
/// </summary>
int getRandomColor();