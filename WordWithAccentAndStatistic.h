#ifndef WORDWITHACCENTANDSTATISTIC_H
#define WORDWITHACCENTANDSTATISTIC_H
#include <QString>

class WordWithAccentAndStatistic
{
public:
    WordWithAccentAndStatistic();
    WordWithAccentAndStatistic(int id, QString wordText, int rightAccent, int rightAnswersInARow);
    QString wordText;
    int id;
    int rightAccent;
    int rightAnswersInARow = 0;

    int getWordSize();
    bool isInputAccentRight(int inputAccent);
    QString getNCharInWordInQstringFormat(int n);
    static QChar makeLetterBig(QCharRef inputChar);
    static bool isVowel(QCharRef s);
    static QString getWordWithRightAccent(WordWithAccentAndStatistic wordText);

private:
};

#endif // WORDWITHACCENTANDSTATISTIC_H
