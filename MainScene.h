#pragma once
#include "BaseScene.h"

class MainScene : public BaseScene
{

#pragma region Private

private:
	int score_ = 0;

	void drawControl_();

	void drawFieldPoint_(int point);

	void processDraw_();

	void processLogic_();

#pragma endregion

#pragma region Public

public:

	#pragma region Constructors

	MainScene(int width, int height, int x = 0, int y = 0) : BaseScene(width, height, x, y) {};

	MainScene(int width, int height, COORD coord) : BaseScene(width, height, coord) {};

	#pragma endregion 

#pragma endregion

};

