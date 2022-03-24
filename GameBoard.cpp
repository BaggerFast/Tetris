#include "GameBoard.h"
#include "Console.h"




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
