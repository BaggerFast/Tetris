#include "Field.h"
#include "Console.h"
#include <iostream>
#include "ColorManager.h"
#include "Constants.h"

Field::Field(vector<vector<int>>& field) {
    field_ = field;
}

void Field::drawFieldLine_()
{
    for (int i = 0; i <= field_.size(); ++i)
        cout << Block::FIELD;
    cout << endl;
}

void Field::drawPoint_(int point)
{
    switch (point) {
        case Unit::Space:
            cout << Block::SPACE;
            break;
        case Unit::Falling:
            Console::setColor(ColorManager::current);
            cout << Block::TETROMINO;
            break;
        case Unit::Fallen:
            Console::setColor(ColorManager::previous);
            cout << Block::TETROMINO;
            break;
        }
        cout << point << Block::SPACE;
}

void Field::draw()
{
    Console::setCursorPos(0, 3);
    Console::setColor(ColorManager::Color::Green);

    drawFieldLine_();
    for (int i = 0; i < field_.size(); ++i) {
        cout << Block::FIELD;
        for (int j = 0; j < field_[i].size(); ++j)
            drawPoint_(field_[i][j]);
        Console::setColor(ColorManager::Color::Green);
        cout << '\b' << Block::FIELD << endl;
    }
    drawFieldLine_();
}

int Field::deleteFullLines()
{
    int deleteLines = 0;
    int y = field_.size() - 1;
    while (y > 0) {
        vector<int> fullLine(field_[y].size(), Unit::Fallen);
        vector<int> emptyLine(field_[y].size(), Unit::Space);
        if (fullLine == field_[y]) {
            field_.erase(field_.cbegin() + y);
            field_.insert(field_.cbegin(), emptyLine);
            Sleep(150);
            deleteLines += 1;
            draw();
        }
        else {
            --y;
        }
    }
    return deleteLines;
}

bool Field::gameOver()
{
    int count = 0;
    for (int i = 0; i < field_[0].size(); ++i)
        count += field_[0][i];
    return count != 0;
}
