#include "BaseScene.h"
#include "Constants.h"

BaseScene::BaseScene(int Width, int Height) {
	field_ = vector<vector<int>>(Height, vector<int>(Width, 0));
}

void BaseScene::drawFieldLine_() {
	for (int i = 0; i <= field_.size(); ++i)
		cout << Block::FIELD;
	cout << endl;
}
