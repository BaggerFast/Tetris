#include "MenuScene.h"
#include "ColorManager.h"
#include "Console.h"
#include <conio.h>
#include "Constants.h"
#include "MainScene.h"

#pragma region Needs Refactor
void print_word(string word, int cord_x, int cord_y, vector<vector<int>>& field) {
    for (int i = 0; i < word.length(); ++i)
        field[cord_y][cord_x + i] = int(word[i]);
}

void draw_on_field(int x, int x_size, int y, int y_size, int pass, vector<vector<int>>& field) {
    for (int i = y; i <= y_size; ++i)
        for (int j = x; j <= x_size; ++j)
            field[i][j] = pass;
}

void draw_stairs(int x, int y, int pass, vector<vector<int>>& field) {
    for (int i = y; i < 20; ++i) {
        for (int j = 0; j < x + 1; ++j) {
            field[i][j] = pass;
        }
        x = x + 1;
    }
}

#pragma endregion

#pragma region Private Methods

void MenuScene::drawControl_()
{
    string names[] = {
         "CONTROL",
         "w - up",
         "s - down",
         "space - enter"
    };
    int y = 4;

    Console::setColor(ColorManager::Color::Yellow);
    for (int i = 0; i < 4; ++i) {
        Console::setCursorPos(24, y);
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
            Console::setColor(ColorManager::LightBlue);
            cout << Block::TETROMINO;
            break;
        case Unit::Fallen:
            ColorManager::getRandom();
            Console::setColor(ColorManager::current);
            cout << Block::TETROMINO;
            break;
        default:
            Console::setColor(ColorManager::White);
            cout << char(point);
            break;
        }
    cout << Block::SPACE;
}

void MenuScene::processDraw_()
{
    Console::setCursorPos(coord_);
    Console::setColor(ColorManager::Color::Green);
    print_word("START", 2, 7, field_);
    print_word("EXIT", 2, 9, field_);
    //T
    draw_on_field(0, 2, 1, 1, Unit::Falling, field_);
    draw_on_field(1, 1, 2, 5, Unit::Falling, field_);
    draw_on_field(7, 9, 1, 1, Unit::Falling, field_);
    draw_on_field(8, 8, 2, 5, Unit::Falling, field_);
    //å      
    draw_on_field(4, 4, 1, 5, Unit::Falling, field_);
    draw_on_field(4, 5, 1, 1, Unit::Falling, field_);
    draw_on_field(4, 5, 3, 3, Unit::Falling, field_);
    draw_on_field(4, 5, 5, 5, Unit::Falling, field_);

    draw_stairs(0, 10, Unit::Fallen, field_);
}

void MenuScene::processLogic_()
{
    cursorCoord_.X = 1;
    cursorCoord_.Y = 7;

    field_[cursorCoord_.Y][cursorCoord_.X] = int(248);
    while (!exit_) {
        draw_();
        parseKeyboard_();
        Sleep(250);
    }
}

void MenuScene::parseKeyboard_()
{
    if (_kbhit()) {
        int key = _getch();
        if (Keyboard::parseKeys(Keyboard::SPACE, key))
        {
            if (cursorCoord_.Y == 7) {
                MainScene main = MainScene(10, 20, coord_);
                main.run();
            }
            else if (cursorCoord_.Y == 9) {
                exit_ = true;
            }
        }
        else if (Keyboard::parseKeys(Keyboard::W, key))
        {
            if (cursorCoord_.Y > 7) {
                field_[cursorCoord_.Y][cursorCoord_.X] = Unit::Space;
                cursorCoord_.Y -= 2;
            }
        }
        else if (Keyboard::parseKeys(Keyboard::S, key))
            {
                if (cursorCoord_.Y < 8) {
                    field_[cursorCoord_.Y][cursorCoord_.X] = Unit::Space;
                    cursorCoord_.Y += 2;
                }
            }
        field_[cursorCoord_.Y][cursorCoord_.X] = int(248);
    }
}

#pragma endregion