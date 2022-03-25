#pragma once
#include "BaseScene.h"


class MainScene : public BaseScene
{

private:
	int score_ = 0;

	void drawControl_();

public:

	MainScene(int x, int y) : BaseScene(x, y) {};

	void processDraw();

	void processLogic();

	
};

