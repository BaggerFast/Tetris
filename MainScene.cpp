#include "MainScene.h"
#include "Tetromino.h"
#include "Field.h"
#include "Console.h"
#include "ColorManager.h"
using namespace std;

struct Tetrominos {
    static inline vector<vector<bool>>
        T{
            { 1, 1, 1 },
            { 0, 1, 0 },
        },
        Q{
            { 1, 1 },
            { 1, 1 },
        },
        I{
            { 1, },
            { 1, },
            { 1, },
        },
        Z{
            { 1, 1, 0 },
            { 0, 1, 1 },
        },
        S{
            { 0, 1, 1 },
            { 1, 1, 0 },
        },
        O{
            { 1 },
        },
        J{
            { 0, 1, },
            { 0, 1, },
            { 1, 1, },
        },
        L{
            { 1, 0 },
            { 1, 0 },
            { 1, 1 },
        },
        X{
            { 0, 1, 0 },
            { 1, 1, 1 },
            { 0, 1, 0 },
        },
        U{
            { 1, 0, 1 },
            { 1, 1, 1 },
        };
};

#pragma region Private Methods

#pragma region Draw Methods

void MainScene::processDraw_()
{
    Console::setCursorPos(1, 0);
    Console::setColor(ColorManager::Color::Yellow);
    cout << "Score: " << score_;
    Console::setCursorPos(coord_);
}

void MainScene::drawFieldPoint_(int point)
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

void MainScene::drawControl_() {
    string names[] = {
    "CONTROL",
    "s - down",
    "a - left",
    "d - right",
    "space - rotate"
    };
    int y = 5, x = 24;

    Console::setColor(ColorManager::Color::Yellow);
    for (int i = 0; i < 5; ++i) {
        Console::setCursorPos(x, y);
        cout << names[i];
        y++;
    }
}

#pragma endregion

void MainScene::processLogic_() {
    vector<vector<vector<bool>>> figures = {
       Tetrominos::T,
       Tetrominos::Q,
       Tetrominos::I,
       Tetrominos::Z,
       Tetrominos::S,
       Tetrominos::O,
       Tetrominos::J,
       Tetrominos::L,
       Tetrominos::X,
       Tetrominos::U,
    };
    srand(time(0));
    Field gameField = Field(field_);
    while (!gameField.gameOver()) {
        Tetromino figure = Tetromino(figures[rand() % figures.size()]);
        while (!figure.isFallen()) {
            figure.process_logic(field_);
            draw_();
            Sleep(125);
        }
        score_ += gameField.deleteFullLines();
    }
    Sleep(2000);
    Console::flash(3);
}

#pragma endregion
