#include "Tetromino.h"
#include "Ñonsole.h"

Tetromino::Tetromino(vector<vector<bool>> figure, COORD coord)
{
	figure_ = figure;
    coord_ = coord;
}

void Tetromino::fall(vector<vector<int>>& field) {
    process_draw(field, true);
    coord_.Y += 1;
}

void Tetromino::rotate()
{
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
    int i = coord_.Y, j = 0;
    for (int y = 0; y < figure_.size(); ++y) {
        j = coord_.X;
        for (int x = 0; x < figure_[y].size(); ++x) {
            field[i][j] = undraw ? 0 : figure_[y][x];
            j++;
        }
        i++;
    }
}

void Tetromino::process_logic() { 
    if (_kbhit()) {
        int c = _getch();
        if (c == 115 || c == 235)
            rotate();
        else if (c == 100 || c == 162)
            coord_.X += 1;
    }
       
}
