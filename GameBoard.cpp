#include "GameBoard.h"
#include "Console.h"
#include <iostream>


void GameBoard::drawLine()
{
    for (int i = 0; i <= field.size(); ++i)
        cout << Block::FIELD;
    cout << endl;
}

void GameBoard::drawPoint(int point)
{
    switch (point) {
        case Unit::Space: cout << Block::SPACE; break;
        case Unit::Falling: cout << Block::TETROMINO; break;
        case Unit::Fallen: cout << Block::TETROMINO; break;
    }
    cout << Block::SPACE;
}

void GameBoard::draw()
{
    Console::setCursorPos(0, 0);

    drawLine();
    for (int i = 0; i < field.size(); ++i) {
        cout << Block::FIELD;
        for (int j = 0; j < field[i].size(); ++j)
            drawPoint(field[i][j]);
        cout << '\b' << Block::FIELD << endl;
    }
    drawLine();
}

void GameBoard::processLogic()
{
    checkLine();
}

void GameBoard::checkLine()
{
    for (int y = field.size() - 1; y > 0; --y) {
        vector<int> fullLine(field[y].size(), Unit::Fallen);
        vector<int> emptyLine(field[y].size(), Unit::Space);
        if (fullLine == field[y]) {
            field.erase(field.cbegin() + y);
            field.insert(field.cbegin(), emptyLine);
            Sleep(50);
            return;
        }
    }
}
