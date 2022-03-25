#pragma once
#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

class BaseScene
{
protected:

	bool exit_ = false;

	vector<vector<int>> field_;


public:

	BaseScene(int, int);

	virtual void processDraw() = 0;
	
	virtual void processLogic() = 0;

};

