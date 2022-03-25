#pragma once
#include <windows.h>
#include <vector>
#include "Constants.h"

using namespace std;




class Field
{
private:
    static const int WIDTH_ = 10, HEIGHT_ = 20;

    static inline bool gameOver_ = false;

    static void drawLine();

    static void drawPoint(int);
    
public:
    static inline vector<vector<int>> field = vector<vector<int>>(HEIGHT_, vector<int>(WIDTH_, Unit::Space));

    static void draw();

    static void processLogic();

    static int deleteFullLines();

    static bool gameOver();

};

