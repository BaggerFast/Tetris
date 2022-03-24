#include "Tetromino.h"

Tetromino::Tetromino(vector<vector<bool>> figure, COORD coord)
{
    figure_ = figure;
    coord_ = coord;
}

bool Tetromino::canFall(vector<vector<int>> field)
{
    int tmpY = coord_.Y + 1, tmpX = 0;
    for (int y = 0; y < figure_.size(); ++y) {
        tmpX = coord_.X;
        for (int x = 0; x < figure_[y].size(); ++x) {
            try {
                field.at(tmpY).at(tmpX);
            }
            catch (out_of_range) {
                vector<bool> emptyLine(figure_[y].size(), 0);
                if (emptyLine != figure_[y])
                    return false;
                figure_.erase(figure_.begin() + y);
                break;
            }
            tmpX++;
        }
        tmpY++;
    }
    return true;
}

bool Tetromino::canRotate()
{
    return isFallen_ != true;
}

bool Tetromino::isFallen()
{
    return isFallen_;
}

void Tetromino::fall(vector<vector<int>>& field) {
    if (!canFall(field)) {
        isFallen_ = true;
        return;
    }
    process_draw(field, true);
    coord_.Y += 1;
}

void Tetromino::rotate()
{
    if (canRotate() != true)
        return;
    vector<vector<bool>> tmp = figure_;
    for (int i = 0; i < figure_.size(); ++i)
        for (int j = 0; j < figure_[i].size(); ++j)
            tmp[j][figure_[i].size() - 1 - i] = figure_[i][j];
    figure_ = tmp;
}

void Tetromino::move()
{
}

void Tetromino::process_draw(vector<vector<int>>& field, bool undraw)
{
    int tmpY = coord_.Y, tmpX = 0;
    for (int y = 0; y < figure_.size(); ++y) {
        tmpX = coord_.X;
        for (int x = 0; x < figure_[y].size(); ++x) {
            if (figure_[y][x] == 1)
                field[tmpY][tmpX] = undraw ? 0 : figure_[y][x];
            tmpX++;
        }
        tmpY++;
    }
}

bool parseKeys(vector<int> keys, int key) {
    return find(keys.begin(), keys.end(), key) != keys.end();
}

void Tetromino::process_logic() {


    vector<int>
        W = { 119, 230 },
        A = { 97, 228 },
        S = { 115, 235 },
        D = { 100, 230 },
        SPACE = { 32 };

    if (_kbhit()) {
        int key = _getch();
        if (parseKeys(SPACE, key))
            rotate();
        else if (parseKeys(SPACE, key))
            rotate();

    }
}