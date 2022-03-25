#include "Field.h"
#include "Console.h"
#include <iostream>
#include "ColorManager.h"
#include "Constants.h"


void Field::drawLine()
{
    for (int i = 0; i <= field.size(); ++i)
        cout << Block::FIELD;
    cout << endl;
}

void Field::drawPoint(int point)
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
    cout << Block::SPACE;
}

void Field::draw()
{
    Console::setCursorPos(0, 3);
    Console::setColor(ColorManager::Color::Green);

    drawLine();
    for (int i = 0; i < field.size(); ++i) {
        cout << Block::FIELD;
        for (int j = 0; j < field[i].size(); ++j)
            drawPoint(field[i][j]);
        Console::setColor(ColorManager::Color::Green);
        cout << '\b' << Block::FIELD << endl;
    }
    drawLine();
}


int Field::deleteFullLines()
{
    int deleteLines = 0;
    int y = field.size() - 1;
    while (y > 0){
        vector<int> fullLine(field[y].size(), Unit::Fallen);
        vector<int> emptyLine(field[y].size(), Unit::Space);
        if (fullLine == field[y]) {
            field.erase(field.cbegin() + y);
            field.insert(field.cbegin(), emptyLine);
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
    for (int i = 0; i < field[0].size(); ++i)
        count += field[0][i];
    return count != 0;
}
