#pragma once
#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// Class for Scenes
/// </summary>
class BaseScene
{

#pragma region Protected

protected:

	bool exit_ = false;
	
	/// <summary>
	/// Field position
	/// </summary>
	COORD coord_;

	vector<vector<int>> field_;

	/// <summary>
	/// Field display
	/// </summary>
	void draw_();
	
	/// <summary>
	/// Display the control hud
	/// </summary>
	virtual void drawControl_() = 0;

	/// <summary>
	/// Display points inside the field (unique)
	/// </summary>
	virtual void drawFieldPoint_(int point) = 0;

	virtual void processDraw_() = 0;

	/// <summary>
	/// Start logic of Scene
	/// </summary>
	virtual void processLogic_() = 0;

#pragma endregion

#pragma region Public

public:

	#pragma region Constructors
	
	BaseScene(int, int, int = 0, int = 0);
	
	BaseScene(int, int, COORD);

	#pragma endregion

	/// <summary>
	/// Scene start
	/// </summary>
	void run();

#pragma endregion

};

