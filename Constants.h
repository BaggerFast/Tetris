#pragma once
#include <vector>


struct Block {
    static const char
        FIELD = char(219),
        TETROMINO = char(254),
        SPACE = char(255);
};

enum Unit {
    Space,
    Falling,
    Fallen,
};

struct Keyboard {
    static inline std::vector<int>
        W = { 119, 246 },
        A = { 97, 244 },
        S = { 115, 251 },
        D = { 100, 226 },
        SPACE = { 32 };
};