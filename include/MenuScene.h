#pragma once
#include "BaseScene.h"

class MenuScene : public BaseScene
{

#pragma region Private

private:
	
	COORD cursorCoord_;

	#pragma region Abstact
	
	void drawControl_();

	void drawFieldPoint_(int point);

	void processLogic_();

	#pragma endregion
	
	/// <summary>
	/// Title: TET
	/// </summary>
	void insertTitleIntoField_();

	/// <summary>
	/// Inserts a word into a field
	/// </summary>
	/// <param name="word"></param>
	/// <param name="x">Starting point x to insert word into field</param>
	/// <param name="y">Starting point y to insert word into field</param>
	void insertWordIntoField_(string, int, int);

	/// <summary>
	/// Analyzing keyboard actions
	/// </summary>
	void parseKeyboard_();

	void insertStairsIntoField_();

#pragma endregion

#pragma region Public

public:

	#pragma region Constructors

	MenuScene(int width, int height, int x = 0, int y = 0);

	MenuScene(int width, int height, COORD coord);

	#pragma endregion 

#pragma endregion

};