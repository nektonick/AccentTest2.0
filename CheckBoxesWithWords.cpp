#include "CheckBoxesWithWords.h"

CheckBoxesWithWords::CheckBoxesWithWords()
{
    wordsVector.getWordsByReadingFromFileOrCreatingDefaultFile();
}

void CheckBoxesWithWords::generateCheckBoxes()
{
    for (int i=0; i<wordsVector.size(); ++i){
        QCheckBox *l = new QCheckBox;
        l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i]));
        checkBoxesVector.push_back(l);
    }
}

int CheckBoxesWithWords::size()
{
    return checkBoxesVector.size();
}

QCheckBox &CheckBoxesWithWords::operator [](int index)
{
    return *checkBoxesVector[index];
}
