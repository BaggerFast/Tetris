#pragma once
# include "BaseScene.h"

class MenuScene : public BaseScene
{

#pragma region Private

private:
	
	COORD cursorCoord_;

	void drawControl_();

	void drawFieldPoint_(int point);

	void processDraw_();

	void processLogic_();

	void parseKeyboard_();

#pragma endregion

#pragma region Public

public:

	#pragma region Constructors

		MenuScene(int width, int height, int x = 0, int y = 0) : BaseScene(width, height, x, y) {};

		MenuScene(int width, int height, COORD coord) : BaseScene(width, height, coord) {};

	#pragma endregion 

#pragma endregion

};

