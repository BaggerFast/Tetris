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

	#pragma region Abstact
	
	void drawControl_();

	void drawFieldPoint_(int);

	void processLogic_();
	
#pragma endregion

	/// <summary>
	/// Display score count
	/// </summary>
	void drawScore_();

	/// <summary>
	/// Black and green flashing in console
	/// </summary>
	/// <param name="count">Number of repetitions</param>
	/// <param name="Delay">Delay between flashing</param>
	void flash_(int, int=100);

	/// <summary>
	/// Delete full lines in field
	/// </summary>
	void deleteFullLines_();

	/// <summary>
	/// Check game over
	/// </summary>
	/// <returns> true if the top line in the field is not empty</returns>
	bool gameOver_();

#pragma endregion

#pragma region Public

public:

	#pragma region Constructors

	MainScene(int width, int height, int x = 0, int y = 0) : BaseScene(width, height, x, y) {};

	MainScene(int width, int height, COORD coord) : BaseScene(width, height, coord) {};

	#pragma endregion 

#pragma endregion

};