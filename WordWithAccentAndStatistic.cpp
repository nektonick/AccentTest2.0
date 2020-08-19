#include "WordWithAccentAndStatistic.h"

WordWithAccentAndStatistic::WordWithAccentAndStatistic()
{

}

WordWithAccentAndStatistic::WordWithAccentAndStatistic(
        int id, QString word, int accentLetterNumber, int rightAnswersInARow = 0)
{
    this->id = id;
    this->wordText = word;
    this->rightAccent = accentLetterNumber;
    this->rightAnswersInARow = rightAnswersInARow;
}

bool WordWithAccentAndStatistic::isInputAccentRight(int inputAccent)
{
    return (inputAccent == rightAccent);
}

int WordWithAccentAndStatistic::getWordSize()
{
    return wordText.size();
}

QString WordWithAccentAndStatistic::getNCharInWordInQstringFormat(int n)
{
    QString s ="";
    s += wordText[n];
    return (s);
}

QString WordWithAccentAndStatistic::getWordWithRightAccent(WordWithAccentAndStatistic word)
{
    int vowel=0;
    int i=0;
    while (vowel != word.rightAccent) {
        if(isVowel(word.wordText[i]))
            vowel++;
        i++;
    }
    i--; //без этого работает неверно
    QString ans = word.wordText;
    ans[i]=makeLetterBig(ans[i]);
    ans.insert(i+1, " ́"); //символ ударения
    return ans;
}

QChar WordWithAccentAndStatistic::makeLetterBig(QCharRef inputChar)
{
    QString lower = "аеиоуыэюя";
    QString upper = "АЕИОУЫЭЮЯ";
    return upper[lower.indexOf(inputChar)];
}

bool WordWithAccentAndStatistic::isVowel(QCharRef s)
{
    QString vowels ="аеёиоуыэюяАЕЁИОУЫЭЮЯ";
    return vowels.contains(s);
}
