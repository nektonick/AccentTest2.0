#ifndef BUTTONSWITHLETTER_H
#define BUTTONSWITHLETTER_H

#include <QPushButton>
#include <WordWithAccentAndStatistic.h>
#include <QDebug>

class ButtonsWithLetter
{
public:
    ButtonsWithLetter();
    ~ButtonsWithLetter();
    std::vector<QPushButton*> buttonsWithLetter;
    void generateButtonsFor(WordWithAccentAndStatistic word);
    void generateAnswer(WordWithAccentAndStatistic word);
    void deleteAllButtons();
    int size();
    QPushButton& operator [] (int index);
};

#endif // BUTTONSWITHLETTER_H
