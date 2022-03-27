#pragma once
#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

class BaseScene
{

#pragma region Protected

protected:

	bool exit_ = false;

	COORD coord_;

	vector<vector<int>> field_;

	void draw_();
	
	virtual void drawControl_() = 0;

	virtual void drawFieldPoint_(int point) = 0;

	virtual void processDraw_() = 0;

	virtual void processLogic_() = 0;

#pragma endregion

#pragma region Public

public:

	#pragma region Constructors

	BaseScene(int, int, int = 0, int = 0);
	
	BaseScene(int, int, COORD);

	#pragma endregion

	void run();

#pragma endregion

};

