#pragma once
#include "BaseScene.h"
#include "Constants.h"


class MainScene : public BaseScene
{

#pragma region Private

private:
	int score_ = 0;

	int colorCurrentTetromino_ = Color::Black;
	int colorLastTetromino_ = colorCurrentTetromino_;

	void drawControl_();

	void drawFieldPoint_(int);

	void processDraw_();

	void processLogic_();

	void flash_(int, int);

#pragma endregion

#pragma region Public

public:

	#pragma region Constructors

	MainScene(int width, int height, int x = 0, int y = 0) : BaseScene(width, height, x, y) {};

	MainScene(int width, int height, COORD coord) : BaseScene(width, height, coord) {};

	#pragma endregion 

#pragma endregion

};

