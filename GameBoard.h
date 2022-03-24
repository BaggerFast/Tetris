#pragma once
#include <iostream>
#include <vector>

using namespace std;


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


class GameBoard
{
private:
    static const int WIDTH_ = 10, HEIGHT_ = 20;

    static void drawLine();

    static void drawPoint(int);
    
public:
    static inline vector<vector<int>> field = vector<vector<int>>(HEIGHT_, vector<int>(WIDTH_, Unit::Space));

    static void draw();

};

