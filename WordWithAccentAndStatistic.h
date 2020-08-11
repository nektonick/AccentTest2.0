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
    QString getText();
    int accentLetterNumber;
    int rightAnswersInARow = 0;
    int getWordSize();
    QString getNCharInWordInQstringFormat(int n);

    static QChar makeLetterBig(QCharRef c);
    static bool isVowel(QCharRef s);
    static QString getWordWithRightAccent(WordWithAccentAndStatistic word);

private:
    QString word;
};

#endif // WORDWITHACCENTANDSTATISTIC_H
