#include "ButtonsWithLetter.h"

ButtonsWithLetter::ButtonsWithLetter()
{

}

ButtonsWithLetter::~ButtonsWithLetter()
{
    deleteAllButtons();
}

void ButtonsWithLetter::generateButtonsFor(WordWithAccentAndStatistic word)
{
    for (int i=0; i<word.getWordSize(); ++i){
        QPushButton *b = new QPushButton();
        b->setObjectName(QString::number(i));
        b->setText(word.getNCharInWordInQstringFormat(i));
        buttonsWithLetter.push_back(b);
    }
}

void ButtonsWithLetter::generateAnswer(WordWithAccentAndStatistic word)
{
    QPushButton *b = new QPushButton();
    QString text = wordWithRightAccent(word);
    b->setText(text);
    buttonsWithLetter.push_back(b);
}

QString ButtonsWithLetter::wordWithRightAccent(WordWithAccentAndStatistic word)
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
    return ans;
}

void ButtonsWithLetter::deleteAllButtons()
{
    for (int i=0; i<buttonsWithLetter.size(); ++i){
        delete buttonsWithLetter[i];
    }
    buttonsWithLetter.clear();
}

int ButtonsWithLetter::size()
{
    return buttonsWithLetter.size();
}

QPushButton &ButtonsWithLetter::operator [](int index)
{
    return *buttonsWithLetter[index];
}

QChar ButtonsWithLetter::makeLetterBig(QCharRef c)
{
    QString lower = "аеёиоуыэюя";
    QString upper = "АЕЁИОУЫЭЮЯ";
    return upper[lower.indexOf(c)];
}

bool ButtonsWithLetter::isVowel(QCharRef s)
{
    QString vowels ="аеёиоуыэюя";
    return vowels.contains(s);
}


