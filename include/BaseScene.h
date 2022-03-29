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

	/// <summary>
	/// Game field
	/// </summary>
	vector<vector<int>> field_;

	/// <summary>
	/// Field displaying
	/// </summary>
	void drawField_();
	
	/// <summary>
	/// Displaying the control hud
	/// </summary>
	virtual void drawControl_() = 0;

	/// <summary>
	/// Displaying points inside the field (unique)
	/// </summary>
	virtual void drawFieldPoint_(int point) = 0;

	/// <summary>
	/// Logic of Scene
	/// </summary>
	virtual void processLogic_() = 0;

#pragma endregion

#pragma region Public

public:

	#pragma region Constructors

	/// <summary>
	/// </summary>
	/// <param name="width">Width of field</param>
	/// <param name="height">Height of field</param>
	/// <param name="x">Starting coord x in console to display the field</param>
	/// <param name="y">Starting coord y in console to display the field</param>
	BaseScene(int, int, int = 0, int = 0);
	
	BaseScene(int, int, COORD);

	#pragma endregion

	/// <summary>
	/// Inserts a vector into field
	/// </summary>
	/// <param name="vec"></param>
	/// <param name="x"> Starting coord x into field_ for insert vec </param>
	/// <param name="y"> Starting coord y into field_ for insert vec </param>
	/// <param name="Unit"> Element to insert. Example: Unit::Falling </param>
	void insertVectorIntoField_(vector<vector<bool>>, int, int, int);

	/// <summary>
	/// Scene start
	/// </summary>
	void run();

#pragma endregion

};