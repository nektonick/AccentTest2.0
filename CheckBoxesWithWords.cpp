#include "CheckBoxesWithWords.h"

CheckBoxesWithWords::CheckBoxesWithWords()
{

}

void CheckBoxesWithWords::generateCheckBoxes()
{
    for (int i=0; i<wordsVector.size(); ++i){
        QCheckBox *l = new QCheckBox;
        //разный текст в зависимости от числительного
        if(wordsVector[i].getNumOfRightAnswers() == 1)
            l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i])
                       + " (" + QString::number(wordsVector[i].getNumOfRightAnswers())
                       +" верный ответ подряд)");
        else
            if(wordsVector[i].getNumOfRightAnswers() != 1 && wordsVector[i].getNumOfRightAnswers() != 11
                    && wordsVector[i].getNumOfRightAnswers()%10 == 1 )
                l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i])
                           + " (" + QString::number(wordsVector[i].getNumOfRightAnswers())
                           +" верный ответ подряд)");
            else
                if(wordsVector[i].getNumOfRightAnswers() >= 5 && wordsVector[i].getNumOfRightAnswers()<=20)
                    l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i])
                               + " (" + QString::number(wordsVector[i].getNumOfRightAnswers())
                               +" верных ответов подряд)");
                else
                    if (wordsVector[i].getNumOfRightAnswers()%10 > 1
                            && wordsVector[i].getNumOfRightAnswers()%10 < 5)
                        l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i])
                                   + " (" + QString::number(wordsVector[i].getNumOfRightAnswers()) +" верных ответа подряд)");
                    else
                        if(wordsVector[i].getNumOfRightAnswers()%10 == 0 || wordsVector[i].getNumOfRightAnswers()%10 >4)
                            l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i])
                                       + " (" + QString::number(wordsVector[i].getNumOfRightAnswers()) +" верных ответов подряд)");
                        else
                            l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i])
                                       + "(непредусмотренный случай)");
        checkBoxesVector.push_back(l);
    }
}

int CheckBoxesWithWords::size()
{
    return checkBoxesVector.size();
}

QCheckBox &CheckBoxesWithWords::operator [](int index)
{
    return *checkBoxesVector[index];
}

int CheckBoxesWithWords::getLastWordId()
{
    return wordsVector.words[wordsVector.words.size()-1].getId();
}

void CheckBoxesWithWords::clear()
{
    for (unsigned int i=0; i<checkBoxesVector.size(); ++i){
        delete checkBoxesVector[i];
    }
    checkBoxesVector.clear();
}
