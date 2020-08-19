#include "WordsWithCheckBoxVector.h"

WordsWithCheckBoxVector::WordsWithCheckBoxVector()
{

}

WordsWithCheckBoxVector::~WordsWithCheckBoxVector()
{
    this->clear();
}

void WordsWithCheckBoxVector::generateWordsCheckBoxes()
{
    for (unsigned int i=0; i<wordsVector.size(); ++i){
        QCheckBox *l = new QCheckBox;
        //устанавливается разный текст в зависимости от числительного
        if(wordsVector[i].rightAnswersInARow == 1)
            l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i]) + " (" + QString::number(wordsVector[i].rightAnswersInARow) + " верный ответ подряд)");
        else
            if(wordsVector[i].rightAnswersInARow != 1 && wordsVector[i].rightAnswersInARow != 11 && wordsVector[i].rightAnswersInARow%10 == 1 )
                l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i]) + " (" + QString::number(wordsVector[i].rightAnswersInARow) +" верный ответ подряд)");
            else
                if(wordsVector[i].rightAnswersInARow >= 5 && wordsVector[i].rightAnswersInARow<=20)
                    l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i]) + " (" + QString::number(wordsVector[i].rightAnswersInARow) + " верных ответов подряд)");
                else
                    if (wordsVector[i].rightAnswersInARow%10 > 1 && wordsVector[i].rightAnswersInARow%10 < 5)
                        l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i]) + " (" + QString::number(wordsVector[i].rightAnswersInARow) + " верных ответа подряд)");
                    else
                        if(wordsVector[i].rightAnswersInARow%10 == 0 || wordsVector[i].rightAnswersInARow%10 >4)
                            l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i]) + " (" + QString::number(wordsVector[i].rightAnswersInARow) +" верных ответов подряд)");
                        else
                            l->setText(WordWithAccentAndStatistic::getWordWithRightAccent(wordsVector[i]) + "(непредусмотренный случай)");
        this->push_back(l);
    }
}

int WordsWithCheckBoxVector::getLastWordId()
{
    return wordsVector[wordsVector.size()-1].id;
}
