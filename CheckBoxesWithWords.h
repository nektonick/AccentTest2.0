#ifndef CHECKBOXESWITHWORDS_H
#define CHECKBOXESWITHWORDS_H
#include <QCheckBox>
#include <WordsVector.h>

class CheckBoxesWithWords
{
public:
    CheckBoxesWithWords();
    std::vector<QCheckBox*> checkBoxesVector;
    void generateCheckBoxes();
    void deleteChechBoxes();
    WordsVector wordsVector;
    int size();
    QCheckBox& operator [] (int index);
    int getLastWordId();
    void clear();
private:
};

#endif // CHECKBOXESWITHWORDS_H
