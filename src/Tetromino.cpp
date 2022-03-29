#include <iostream>
#include <conio.h>

#include "Tetromino.h"
#include "Constants.h"
#include "Keyboard.h"


vector<vector<bool>> Tetromino::getNextRotate()
{
    vector<vector<bool>> newFigureRotate;
    for (int y = 0; y < figure_[0].size(); ++y) {
        vector<bool> tmp;
        for (int x = 0; x < figure_.size(); ++x) {
            tmp.insert(tmp.cbegin(), figure_[x][y]);
        }
        newFigureRotate.push_back(tmp);
    }
    return newFigureRotate;
}

Tetromino::Tetromino(vector<vector<bool>> figure, COORD coord)
{
    figure_ = figure;
    coord_ = coord;
}

Tetromino::Tetromino(vector<vector<bool>> figure)
{
    figure_ = figure;
    srand(unsigned(time(0)));
    int rotate = rand() % 4;
    for (int i = 0; i < rotate; ++i)
        figure_ = getNextRotate();
    coord_.X = rand() % 11;
    if (coord_.X > 10-figure_[0].size()-1)
        coord_.X = 10 - figure_[0].size() - 1;
    coord_.Y = 0;
}

bool Tetromino::isFallen() { 
    return isFallen_; 
}

void Tetromino::fall(vector<vector<int>> &field) {
    if (checkInsert(coord_.X, coord_.Y+1, field) == false) {
        process_draw(field, Unit::Fallen);
        isFallen_ = true;
        return;
    }
    coord_.Y += 1;
}  

void Tetromino::rotate(vector<vector<int>> & field)
{
    vector<vector<bool>> tmp = figure_;
    figure_ = getNextRotate();
   
    if (checkInsert(coord_.X, coord_.Y, field) == false)
        figure_ = tmp;   
}

bool Tetromino::checkInsert(int x, int y, vector<vector<int>>& field)
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

void Tetromino::process_draw(vector<vector<int>>& field, int tag)
{
    int tmpY = coord_.Y;
    for (int y = 0; y < figure_.size(); ++y) {
        int tmpX = coord_.X;
        for (int x = 0; x < figure_[y].size(); ++x) {
            if (figure_[y][x] == Unit::Falling && field[tmpY][tmpX] != Unit::Fallen)
                field[tmpY][tmpX] = tag;
            tmpX++;
        }
        tmpY++;
    }
}

void Tetromino::process_logic(vector<vector<int>> &field) {
    process_draw(field, Unit::Space);
    fall(field);
    if (_kbhit() && isFallen_ != true) {
        int key = _getch();
        if (Keyboard::parseKeys(Keyboard::SPACE, key))
            rotate(field);
        else if (Keyboard::parseKeys(Keyboard::A, key) && checkInsert(coord_.X - 1, coord_.Y, field))
            coord_.X -= 1;
        else if (Keyboard::parseKeys(Keyboard::D, key) && checkInsert(coord_.X + 1, coord_.Y, field))
            coord_.X += 1;
        else if (Keyboard::parseKeys(Keyboard::S, key) && checkInsert(coord_.X, coord_.Y + 1, field))
            coord_.Y += 1;
    }
     process_draw(field, Unit::Falling);
}