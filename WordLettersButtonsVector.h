#ifndef BUTTONSWITHLETTER_H
#define BUTTONSWITHLETTER_H

#include <QPushButton>
#include <WordWithAccentAndStatistic.h>
#include <QDebug>

class WordLettersButtonsVector : public std::vector<QPushButton*>
{
public:
    WordLettersButtonsVector();
    ~WordLettersButtonsVector();
    void generateButtonsFor(WordWithAccentAndStatistic inputWord);
    void generateButtonWithRightAnswerFor(WordWithAccentAndStatistic inputWord);
    void deleteAllButtons();
};

#endif // BUTTONSWITHLETTER_H
