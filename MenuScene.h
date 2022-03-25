#pragma once
# include "BaseScene.h"

class MenuScene : public BaseScene
{
private:
	COORD coord_;
	void drawControl_();

	void drawFieldLine_();

	void drawPoint_(int point);

public:

	MenuScene(int x, int y);

	void processDraw();

	void processLogic();

	void parseKeyboard();

};

