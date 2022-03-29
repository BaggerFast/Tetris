#pragma once
#include <windows.h>
#include <vector>

using namespace std;

class Tetromino
{

#pragma region Private

private:

	vector<vector<bool>> figure_;
	
	/// <summary>
	/// Coord of Tetromino in field
	/// </summary>
	COORD coord_;

	bool isFallen_ = false;

	/// <summary>
	/// Get the next rotate of the figure clockwise
	/// </summary>
	/// <returns></returns>
	vector<vector<bool>> getNextRotate_();

	/// <summary>
	/// Ñhecks if it is possible to insert a tetramino in the field
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="field"></param>
	/// <returns> true if can else false </returns>
	bool canInsertIntoField_(int, int, vector<vector<int>>&);

	/// <summary>
	/// insert a tetramino in the field
	/// </summary>
	/// <param name="field"></param>
	/// <param name="unit"></param>
	void InsertIntoField_(vector<vector<int>>&, int);
	
	void fall_(vector<vector<int>>&);

	void rotate_(vector<vector<int>>&);

#pragma endregion

#pragma region Public

public:

	#pragma region Constructors

	/// <summary>
	/// </summary>
	/// <param name="figure"></param>
	/// <param name="fieldWidth"></param>
	Tetromino(vector<vector<bool>>, int);

	#pragma endregion

	/// <summary>
	/// getter for isFallen_
	/// </summary>
	/// <returns> isFallen_ </returns>
	bool isFallen();
	
	/// <summary>
	/// </summary>
	/// <param name="field"> gameField </param>
	void processLogic(vector<vector<int>> &);

#pragma endregion

};