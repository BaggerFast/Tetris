#pragma once
#include <windows.h>
#include "Field.h"

using namespace std;

class Tetromino
{

#pragma region Private

private:

	vector<vector<bool>> figure_;	
	COORD coord_;
	bool isFallen_ = false;

	vector<vector<bool>> getNextRotate();

#pragma endregion

#pragma region Public

public:

	#pragma region Constructors

	Tetromino(vector<vector<bool>>, COORD);

	Tetromino(vector<vector<bool>>);

	#pragma endregion

	bool isFallen();

	void fall(vector<vector<int>>&);

	void process_draw(vector<vector<int>>&, int = Unit::Falling);

	void rotate(vector<vector<int>>&);

	void process_logic(vector<vector<int>> &);

	bool checkInsert(int, int, vector<vector<int>> &);

#pragma endregion

};

