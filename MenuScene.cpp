#include "MenuScene.h"
#include "ColorManager.h"
#include "Console.h"
#include <conio.h>
#include "Constants.h"
#include "MainScene.h"



MenuScene::MenuScene(int x, int y): BaseScene(x, y)
{
    coord_.X = 1;
    coord_.Y = 7;
    field_[coord_.Y][coord_.X] = int(248);
}

void MenuScene::drawFieldLine_()
{
    for (int i = 0; i <= field_.size(); ++i)
        cout << Block::FIELD;
    cout << endl;
}

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

void MenuScene::drawPoint_(int point)
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

void MenuScene::processDraw()
{
    drawControl_();

    Console::setCursorPos(0, 3);
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

void MenuScene::processLogic()
{
    while (!exit_) {
        processDraw();
        parseKeyboard();
        Sleep(250);
    }
}

void MenuScene::parseKeyboard()
{
    if (_kbhit()) {
        int key = _getch();
        if (Keyboard::parseKeys(Keyboard::SPACE, key))
        {
            if (coord_.Y == 7) {
                MainScene main = MainScene(10, 20);
                main.processLogic();
            }
            else if (coord_.Y == 9) {
                exit_ = true;
            }
        }
        else if (Keyboard::parseKeys(Keyboard::W, key))
        {
            if (coord_.Y > 7) {
                field_[coord_.Y][coord_.X] = Unit::Space;
                coord_.Y -= 2;
            }
        }
        else if (Keyboard::parseKeys(Keyboard::S, key))
            {
                if (coord_.Y < 8) {
                    field_[coord_.Y][coord_.X] = Unit::Space;
                    coord_.Y += 2;
                }
            }
        field_[coord_.Y][coord_.X] = int(248);
    }
}
