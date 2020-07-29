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
        QPushButton *b = new QPushButton(word.getNCharInWordInQstringFormat(i));
        buttonsWithLetter.push_back(b);
    }
}

void ButtonsWithLetter::deleteAllButtons()
{
    for (int i=0; i<buttonsWithLetter.size(); ++i){
        delete &buttonsWithLetter[i];
    }

    //debug test
    for (int i=0; i<buttonsWithLetter.size(); ++i){
        qDebug() << &buttonsWithLetter[i]<<endl;
    }
}

int ButtonsWithLetter::size()
{
    return buttonsWithLetter.size();
}

QPushButton &ButtonsWithLetter::operator [](int index)
{
    return *buttonsWithLetter[index];
}

