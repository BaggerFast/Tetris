#include "BaseScene.h"

BaseScene::BaseScene(int Width, int Height) {
	field_ = vector<vector<int>>(Height, vector<int>(Width, 0));
}
