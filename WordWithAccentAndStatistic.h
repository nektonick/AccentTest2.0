#ifndef WORDWITHACCENTANDSTATISTIC_H
#define WORDWITHACCENTANDSTATISTIC_H
#include <QString>

class WordWithAccentAndStatistic
{
public:
    WordWithAccentAndStatistic();
    WordWithAccentAndStatistic(int id, QString word, int accentLetterNumber, int rightAnswersInARow);
    int getRightAccent();
    bool isInputAccentRight(int inputAccent);
    int id;
    QString word;
    int accentLetterNumber;
    int rightAnswersInARow = 0;
    int getWordSize();
    QString getNCharInWordInQstringFormat(int n);

private:

};

#endif // WORDWITHACCENTANDSTATISTIC_H
