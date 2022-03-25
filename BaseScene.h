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
	
	void drawFieldLine_();

public:

	BaseScene(int, int);

	virtual void processLogic() = 0;

};

