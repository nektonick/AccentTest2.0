#include "WordWithAccentAndStatistic.h"

WordWithAccentAndStatistic::WordWithAccentAndStatistic()
{

}
WordWithAccentAndStatistic::WordWithAccentAndStatistic
(int id, QString word, int accentLetterNumber, int rightAnswersInARow = 0)
{
    this->id = id;
    this->word = word;
    this->accentLetterNumber = accentLetterNumber;
    this->rightAnswersInARow = rightAnswersInARow;
}

int WordWithAccentAndStatistic::getRightAccent()
{
    return this->accentLetterNumber;
}

bool WordWithAccentAndStatistic::isInputAccentRight(int inputAccent)
{
    return (inputAccent == this->getRightAccent());
}

QString WordWithAccentAndStatistic::getText()
{
    return word;
}

int WordWithAccentAndStatistic::getWordSize()
{
    return word.size();
}

QString WordWithAccentAndStatistic::getNCharInWordInQstringFormat(int n)
{
    QString s ="";
    s += word[n];
    return (s);
}
