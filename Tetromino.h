#pragma once
#include <windows.h>
#include "GameBoard.h"


using namespace std;

class Tetromino
{
private:

	vector<vector<bool>> figure_;
	COORD coord_;
	
	int rotate_ = 0;

	bool isFallen_ = false;

	bool canFall(vector<vector<int>>);

	bool canRotate();

public:
	Tetromino(vector<vector<bool>>, COORD);

	bool isFallen();

	void fall(vector<vector<int>>&);
	
	void process_draw(vector<vector<int>>&, bool = false);

	void rotate();
	
	void move();

	void process_logic();
};

