#include "MainScene.h"
#include "Tetromino.h"
#include "Console.h"

#pragma region Private Methods

#pragma region Abstact Methods

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
        "CONTROL:",
        "s - down",
        "a - left",
        "d - right",
        "space - rotate"
    };
    int y = 4, x = 24;

    Console::setColor(Color::Yellow);
    for (int i = 0; i < 5; ++i) {
        Console::setCursorPos(x, y);
        cout << names[i];
        y++;
    }
}

void MainScene::processLogic_() {
    
    vector<vector<vector<bool>>> figures = {
       Tetrominoes::T,
       Tetrominoes::Q,
       Tetrominoes::I,
       Tetrominoes::Z,
       Tetrominoes::S,
       Tetrominoes::O,
       Tetrominoes::J,
       Tetrominoes::L,
       Tetrominoes::X,
       Tetrominoes::U,
    };

    srand(unsigned(time(0)));
    
    drawScore_();
    
    while (!gameOver_()) {
        
        Tetromino figure = Tetromino(figures[rand() % figures.size()], field_[0].size());

        colorCurrentTetromino_ = getRandomColor();

        while (!figure.isFallen()) {
            drawField_();
            figure.processLogic(field_);
            Sleep(100);
        }

        colorLastTetromino_ = colorCurrentTetromino_;
        
        deleteFullLines_();
    }
    drawField_();
    Sleep(2000);
    flash_(3, 100);
}

#pragma endregion

void MainScene::drawScore_()
{
    Console::setCursorPos(1, 0);
    Console::setColor(Color::Yellow);
    cout << "Score: " << score_;
    Console::setCursorPos(coord_);
}

void MainScene::flash_(int count, int delay) {
    for (int i = 0; i < count; i++) {
        system("color 20");
        Sleep(delay);
        system("color 02");
        Sleep(delay);
    }
}

void MainScene::deleteFullLines_()
{
    int y = field_.size() - 1;
    while (y > 0) {
        vector<int> fullLine(field_[y].size(), Unit::Fallen);
        vector<int> emptyLine(field_[y].size(), Unit::Space);
        if (fullLine == (field_[y])) {
            field_.erase(field_.cbegin() + y);
            field_.insert(field_.cbegin(), emptyLine);
            score_++;
            drawScore_();
            drawField_();
            continue;
        }
        y--;
    }
}

bool MainScene::gameOver_()
{
    for (int i = 0; i < field_[0].size(); ++i)
        if (field_[0][i] == Unit::Fallen)
            return true;
    return false;
} 

#pragma endregion