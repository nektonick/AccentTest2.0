#include "WordLettersButtonsVector.h"

WordLettersButtonsVector::WordLettersButtonsVector()
{

}

WordLettersButtonsVector::~WordLettersButtonsVector()
{
    deleteAllButtons();
}

void WordLettersButtonsVector::generateButtonsFor(WordWithAccentAndStatistic inputWord)
{
    for (int i=0; i<inputWord.getWordSize(); ++i){
        QPushButton *b = new QPushButton();
        b->setObjectName(QString::number(i));
        b->setText(inputWord.getNCharInWordInQstringFormat(i));
        b->setStyleSheet(
                    "font-size: 36px;"
                    "font-weight: normal;"
                    "margin: 0.5px; padding: 5px;"
                    );
        this->push_back(b);
    }
}

void WordLettersButtonsVector::generateButtonWithRightAnswerFor(WordWithAccentAndStatistic inputWord)
{
    QPushButton *b = new QPushButton();
    QString text = WordWithAccentAndStatistic::getWordWithRightAccent(inputWord);
    b->setText(text);
    this->push_back(b);
}

void WordLettersButtonsVector::deleteAllButtons()
{
    for (auto i: *this){
        delete i;
    }
   this->clear();
}
