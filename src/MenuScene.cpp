#include <conio.h>
#include "MenuScene.h"
#include "MainScene.h"
#include "Console.h"
#include "Keyboard.h"
#include "Constants.h"


#pragma region Constructors

MenuScene::MenuScene(int width, int height, int x, int y) : BaseScene(width, height, x, y) {
    cursorCoord_.X = 1;
    cursorCoord_.Y = 7;
};

MenuScene::MenuScene(int width, int height, COORD coord) : BaseScene(width, height, coord) {
    cursorCoord_.X = 1;
    cursorCoord_.Y = 7;
};

#pragma endregion

#pragma region Private Methods

#pragma region Abstract

void MenuScene::drawControl_()
{
    string names[] = {
         "CONTROL:",
         "w - up",
         "s - down",
         "space - enter"
    };
    int y = 4, x = 24;

    Console::setColor(Color::Yellow);

    for (int i = 0; i < 4; ++i) {
        Console::setCursorPos(x, y);
        cout << names[i];
        y++;
    }
}

void MenuScene::drawFieldPoint_(int point)
{
    switch (point) {
        case Unit::Space:
            cout << Block::SPACE;
            break;
        case Unit::Falling:
            Console::setColor(Color::LightBlue);
            cout << Block::TETROMINO;
            break;
        case Unit::Fallen:
            Console::setColor(getRandomColor());
            cout << Block::TETROMINO;
            break;
        default:
            Console::setColor(Color::White);
            cout << char(point);
            break;
        }
    cout << Block::SPACE;
}

void MenuScene::processLogic_()
{
    insertWordIntoField_("START", 2, 7);
    insertWordIntoField_("EXIT", 2, 9);
    insertTitleIntoField_();
    insertStairsIntoField_();

    field_[cursorCoord_.Y][cursorCoord_.X] = Block::CURSOR;

    while (!exit_) {
        parseKeyboard_();
        drawField_();
        Sleep(175);
    }
}

#pragma endregion

void MenuScene::insertTitleIntoField_()
{
    static vector<vector<bool>>
        T{
            { 1, 1, 1 },
            { 0, 1, 0 },
            { 0, 1, 0 },
            { 0, 1, 0 },
            { 0, 1, 0 },
        },
        E{
            { 1, 1 },
            { 1, 0 },
            { 1, 1 },
            { 1, 0 },
            { 1, 1 },
        };
    insertVectorIntoField_(T, 0, 1, Unit::Falling);
    insertVectorIntoField_(E, 4, 1, Unit::Falling);
    insertVectorIntoField_(T, 7, 1, Unit::Falling);
}

void MenuScene::parseKeyboard_()
{
    if (_kbhit()) {
        int key = _getch();
        field_[cursorCoord_.Y][cursorCoord_.X] = Block::SPACE;

        if (Keyboard::parseKeys(Keyboard::SPACE, key)) {
            switch (cursorCoord_.Y) {
                case 7: {
                    MainScene main = MainScene(10, 20, coord_);
                    main.run();
                    run();
                    break;
                }
                case 9: {
                    exit_ = true;
                    break;
                }
            }
        }  
        else if (Keyboard::parseKeys(Keyboard::S, key)) {
            if (cursorCoord_.Y == 7)
                cursorCoord_.Y += 2;
        }
        else if (Keyboard::parseKeys(Keyboard::W, key)) {
            if (cursorCoord_.Y == 9)
                cursorCoord_.Y -= 2;
        }
           
        field_[cursorCoord_.Y][cursorCoord_.X] = Block::CURSOR;
    }
}

void MenuScene::insertWordIntoField_(string word, int cord_x, int cord_y) {
    for (int i = 0; i < word.length(); ++i)
        field_[cord_y][cord_x + i] = word[i];
}

void MenuScene::insertStairsIntoField_() {
    int x = 0, y = 10;
    for (int i = y; i < field_.size(); ++i) {
        for (int j = 0; j < x + 1; ++j)
            field_[i][j] = Unit::Fallen;
        x++;
    }
}

#pragma endregion