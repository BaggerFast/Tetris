#include "Tetromino.h"
#include <iostream>
#include <conio.h>


Tetromino::Tetromino(vector<vector<bool>> figure, COORD coord)
{
    figure_ = figure;
    coord_ = coord;
}

bool Tetromino::canRotate()
{
    return isFallen_ != true;
}

bool Tetromino::isFallen() { return isFallen_; }

void Tetromino::fall(vector<vector<int>> &field) {
    if (checkInsert(coord_.X, coord_.Y+1, field) == false) {
        process_draw(field, Unit::Fallen);
        isFallen_ = true;
        return;
    }
    process_draw(field, Unit::Space);
    coord_.Y += 1;
}

void Tetromino::process_draw(vector<vector<int>>& field, int tag)
{
    int tmpY = coord_.Y, tmpX = 0;
    for (int y = 0; y < figure_.size(); ++y) {
        tmpX = coord_.X;
        for (int x = 0; x < figure_[y].size(); ++x) {
            if (figure_[y][x] == Unit::Falling && field[tmpY][tmpX] != Unit::Fallen)
                field[tmpY][tmpX] = tag;
            tmpX++;
        }
        tmpY++;
    }
}

void Tetromino::rotate()
{
    if (canRotate() != true)
        return;
    vector<vector<bool>> tmp;
    for (int y = 0; y < figure_[0].size(); ++y) {
        vector<bool> tmp1;
        for (int x = 0; x < figure_.size(); ++x) {  
            tmp1.insert(tmp1.cbegin(), figure_[x][y]);
        }
        tmp.push_back(tmp1);
    }
    figure_ = tmp;
}

void Tetromino::move()
{
}

bool parseKeys(vector<int> keys, int key) {
    return find(keys.begin(), keys.end(), key) != keys.end();
}

void Tetromino::process_logic(vector<vector<int>> & field) {


    vector<int>
        W = { 119, 246 },
        A = { 97, 244 },
        S = { 115, 251 },
        D = { 100, 226 },
        SPACE = { 32 };

    if (_kbhit()) {
        int key = _getch();
        if (parseKeys(SPACE, key))
            rotate();
        else if (parseKeys(A, key) && checkInsert(coord_.X-1, coord_.Y, field))
            coord_.X -= 1;
        else if (parseKeys(D, key) && checkInsert(coord_.X+1, coord_.Y, field))
            coord_.X += 1;
        else if (parseKeys(S, key) && checkInsert(coord_.X, coord_.Y+1, field))
            coord_.Y += 1;
    }
}

bool Tetromino::checkInsert(int x, int y, vector<vector<int>> & field)
{   
    int tmpY = y;
    for (int y = 0; y < figure_.size(); ++y) {
        int tmpX = x;
        for (int x = 0; x < figure_[y].size(); ++x) {
            try {
                if (field.at(tmpY).at(tmpX) == Unit::Fallen && figure_[y][x] == Unit::Falling) {
                    return false;
                }                  
            }
            catch (out_of_range) {
                return false;
            }
            tmpX++;
        }
        tmpY++;
    }
    return true;
}
