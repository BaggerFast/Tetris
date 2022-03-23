#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>


using namespace std;

class Tetromino
{
private:
	int rotate_ = 0;
	vector<vector<bool>> figure_;
	COORD coord_;

public:
	Tetromino(vector<vector<bool>>, COORD);

	void fall(vector<vector<int>>&);
	
	void process_draw(vector<vector<int>>&, bool = false);

	void rotate();
	
	void move();

	void process_logic();
};

