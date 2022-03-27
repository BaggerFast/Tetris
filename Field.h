#pragma once
#include <windows.h>
#include <vector>
#include "Constants.h"

using namespace std;


class Field
{

#pragma region Private

private:

    bool gameOver_ = false;

    vector<vector<int>> field_;
    
#pragma endregion

#pragma region Public

public:

    Field(vector<vector<int>> &);

    void processLogic();

    int deleteFullLines();

    bool gameOver();


#pragma endregion

};

