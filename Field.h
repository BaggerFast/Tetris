#pragma once
#include <windows.h>
#include <vector>
#include "Constants.h"

using namespace std;


class Field
{
private:

    bool gameOver_ = false;

    vector<vector<int>> field_;
    
    void drawPoint_(int);

    void drawFieldLine_();

public:

    Field(vector<vector<int>>&);

    void draw();

    void processLogic();

    int deleteFullLines();

    bool gameOver();

};

