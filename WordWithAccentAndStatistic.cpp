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

QString WordWithAccentAndStatistic::getWordWithRightAccent(WordWithAccentAndStatistic word)
{
    int vowel=0;
    int i=0;
    while (vowel != word.accentLetterNumber) {
        if(isVowel(word.getText()[i]))
            vowel++;
        i++;
    }
    i--; //сдвиг влево, так как буквы в слове с нуля, а глассные с единицы
    QString ans = word.getText();
    ans[i]=makeLetterBig(ans[i]);
    ans.insert(i+1, " ́"); //символ ударения
    return ans;
}

QChar WordWithAccentAndStatistic::makeLetterBig(QCharRef c)
{
    QString lower = "аеиоуыэюя";
    QString upper = "АЕИОУЫЭЮЯ";
    return upper[lower.indexOf(c)];
}

bool WordWithAccentAndStatistic::isVowel(QCharRef s)
{
    QString vowels ="аеёиоуыэюя";
    return vowels.contains(s);
}
