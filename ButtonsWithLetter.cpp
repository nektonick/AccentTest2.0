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
        b->setStyleSheet(
                    "font-size: 36px;"
                    "font-weight: normal;"
                    "margin: 0.5px; padding: 5px;"
                    );
        buttonsWithLetter.push_back(b);
    }
}

void ButtonsWithLetter::generateButtonWithRightAnswer(WordWithAccentAndStatistic word)
{
    QPushButton *b = new QPushButton();
    QString text = WordWithAccentAndStatistic::getWordWithRightAccent(word);
    b->setText(text);
    buttonsWithLetter.push_back(b);
}



void ButtonsWithLetter::deleteAllButtons()
{
    for (unsigned int i=0; i<buttonsWithLetter.size(); ++i){
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




