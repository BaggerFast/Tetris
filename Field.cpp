#include "Field.h"
#include "Console.h"
#include <iostream>
#include "ColorManager.h"
#include "Constants.h"

Field::Field(vector<vector<int>>& field) {
    field_ = field;
}

int Field::deleteFullLines()
{
    int deleteLines = 0;
    int y = field_.size() - 1;
    while (y > 0) {
        vector<int> fullLine(field_[y].size(), Unit::Fallen);
        vector<int> emptyLine(field_[y].size(), Unit::Space);
        if (fullLine == field_[y]) {
            field_.erase(field_.cbegin() + y);
            field_.insert(field_.cbegin(), emptyLine);
            Sleep(150);
            deleteLines += 1;
        }
        else {
            --y;
        }
    }
    return deleteLines;
}

bool Field::gameOver()
{
    int count = 0;
    for (int i = 0; i < field_[0].size(); ++i)
        count += field_[0][i];
    return count != 0;
}
