#ifndef WORDWITHACCENTANDSTATISTIC_H
#define WORDWITHACCENTANDSTATISTIC_H
#include <QString>

class WordWithAccentAndStatistic
{
public:
    WordWithAccentAndStatistic();
    WordWithAccentAndStatistic(int id, QString word, int accentLetterNumber, int rightAnswersInARow);

    QString getText();
    int getId();
    int getRightAccent();
    int getNumOfRightAnswers();

    void setText(QString text);
    void setAccent(int inputAccent);
    void setId(int inputId);
    void setNumOfRightAnswers(int numOfRightAnswers);

    int getWordSize();
    bool isInputAccentRight(int inputAccent);
    QString getNCharInWordInQstringFormat(int n);

    static QChar makeLetterBig(QCharRef c);
    static bool isVowel(QCharRef s);
    static QString getWordWithRightAccent(WordWithAccentAndStatistic word);

private:
    QString word;
    int id;
    int accentLetterNumber;
    int rightAnswersInARow = 0;
};

#endif // WORDWITHACCENTANDSTATISTIC_H
