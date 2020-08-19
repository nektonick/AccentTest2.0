#include "CheckBoxesWithWords.h"

CheckBoxesWithWords::CheckBoxesWithWords()
{

}

void CheckBoxesWithWords::generateCheckBoxes()
{
    for (unsigned int i=0; i<wordsVector.size(); ++i){
        QCheckBox *l = new QCheckBox;
        //разный текст в зависимости от числительного
        if(wordsVector[i].rightAnswersInARow == 1)
            l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i])
                       + " (" + QString::number(wordsVector[i].rightAnswersInARow)
                       +" верный ответ подряд)");
        else
            if(wordsVector[i].rightAnswersInARow != 1 && wordsVector[i].rightAnswersInARow != 11
                    && wordsVector[i].rightAnswersInARow%10 == 1 )
                l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i])
                           + " (" + QString::number(wordsVector[i].rightAnswersInARow)
                           +" верный ответ подряд)");
            else
                if(wordsVector[i].rightAnswersInARow >= 5 && wordsVector[i].rightAnswersInARow<=20)
                    l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i])
                               + " (" + QString::number(wordsVector[i].rightAnswersInARow)
                               +" верных ответов подряд)");
                else
                    if (wordsVector[i].rightAnswersInARow%10 > 1
                            && wordsVector[i].rightAnswersInARow%10 < 5)
                        l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i])
                                   + " (" + QString::number(wordsVector[i].rightAnswersInARow) +" верных ответа подряд)");
                    else
                        if(wordsVector[i].rightAnswersInARow%10 == 0 || wordsVector[i].rightAnswersInARow%10 >4)
                            l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i])
                                       + " (" + QString::number(wordsVector[i].rightAnswersInARow) +" верных ответов подряд)");
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
    return wordsVector[wordsVector.size()-1].id;
}

void CheckBoxesWithWords::clear()
{
    for (unsigned int i=0; i<checkBoxesVector.size(); ++i){
        delete checkBoxesVector[i];
    }
    checkBoxesVector.clear();
}
