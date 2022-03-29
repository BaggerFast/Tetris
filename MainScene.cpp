#include "MainScene.h"
#include "Tetromino.h"
#include "Field.h"
#include "Console.h"

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
    Console::setColor(Color::Yellow);
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
            Console::setColor(colorCurrentTetromino_);
            cout << Block::TETROMINO;
            break;
        case Unit::Fallen:
            Console::setColor(colorLastTetromino_);
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

    Console::setColor(Color::Yellow);
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

    srand(unsigned(time(0)));
    Field gameField = Field(field_);

    while (!gameField.gameOver()) {
        
        Tetromino figure = Tetromino(figures[rand() % figures.size()]);

        colorCurrentTetromino_ = getRandomColor();

        while (!figure.isFallen()) {
            draw_();
            figure.process_logic(field_);
            Sleep(100);
        }

        colorLastTetromino_ = colorCurrentTetromino_;
        
        for (int i = 0; i < gameField.deleteFullLines(); ++i){
            draw_();
            score_ += 1;
        }
    }
    Sleep(2000);
    flash_(3, 100);
}

void MainScene::flash_(int count, int timer) {
    for (int i = 0; i < count; i++) {
        system("color 20");
        Sleep(timer);
        system("color 02");
        Sleep(timer);
    }
}

#pragma endregion
