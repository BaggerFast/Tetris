#include "BaseScene.h"
#include "Constants.h"
#include "Console.h"


#pragma region Constructors

BaseScene::BaseScene(int width, int height, int x, int y) {
    field_ = vector<vector<int>>(height, vector<int>(width, 0));
    coord_.X = x;
    coord_.Y = y;
}

BaseScene::BaseScene(int width, int height, COORD coord) {
    field_ = vector<vector<int>>(height, vector<int>(width, 0));
    coord_ = coord;
}

#pragma endregion

#pragma region Private Methods

void BaseScene::draw_()
{
    processDraw_();

    Console::setCursorPos(coord_);

    Console::setColor(Color::Green);

    for (int i = 0; i <= field_.size(); ++i)
        cout << Block::FIELD;
    cout << endl;

    for (int i = 0; i < field_.size(); ++i) {
        cout << Block::FIELD;

        for (int j = 0; j < field_[i].size(); ++j)
            drawFieldPoint_(field_[i][j]);

        Console::setColor(Color::Green);
        cout << '\b' << Block::FIELD << endl;
    }

    for (int i = 0; i <= field_.size(); ++i)
        cout << Block::FIELD;
    cout << endl;
}

#pragma endregion

#pragma region Public Methods

void BaseScene::run() {
    system("cls");
    drawControl_();
    processLogic_();
}

#pragma endregion

