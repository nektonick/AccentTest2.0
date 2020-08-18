#include "WordsVector.h"


WordsVector::WordsVector()
{
    wordsFile.setFileName(fileName);
    if (wordsFile.isOpen()){
        qDebug()<<"file is already open"<<endl;
        wordsFile.close();
    }
    getWordsByReadingFromFileOrCreatingDefaultFile();
}

void WordsVector::getWordsByReadingFromFileOrCreatingDefaultFile()
{
    if (wordsFile.exists()){
        readWordsFromFile();
    }
    else{
        createDefaultWordsFileIfItNotExist();
        readWordsFromFile();
    }
}

void WordsVector::readWordsFromFile()
{
    if (wordsFile.isOpen()){
        qDebug()<<"file is already open"<<endl;
        wordsFile.close();
    }
    if (wordsFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream inStream(&wordsFile);
        int tempId=0;
        QString tempWord="";
        int tempAccent=0;
        int tempRightAnswersInARow = 0;

        while (!inStream.atEnd()) {
            inStream>>tempId >> tempWord >>tempAccent >> tempRightAnswersInARow;
            if (tempWord != ""){
                WordWithAccentAndStatistic word(tempId, tempWord.toUtf8().constData(), tempAccent,tempRightAnswersInARow);
                words.push_back(word);
            }
        }
        wordsFile.close();
    }
}

void WordsVector::createDefaultWordsFileIfItNotExist()
{
    if (wordsFile.isOpen()){
        qDebug()<<"file is already open"<<endl;
        wordsFile.close();
    }
    if (wordsFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        QTextStream outStream(&wordsFile);
        outStream<< QString::fromUtf8("0 апостроф 3 0")<<endl;
        wordsFile.close();
    }
}

void WordsVector::saveWords()
{
    if (wordsFile.isOpen()){
        qDebug()<<"file is already open"<<endl;
        wordsFile.close();
    }
    if (wordsFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream outStream(&wordsFile);
        for (auto w : words){
            outStream<<w.getId()<<" "<<w.getText()<<" "<<w.getRightAccent()<<" "<<w.getNumOfRightAnswers()<<endl;
        }
        wordsFile.close();
    }
}

int WordsVector::size()
{
    return words.size();
}

int WordsVector::getGoodRandomWordNum()
{
    int id = rand()%(words.size());
    int numOfTry=0;
    while (words[id].getNumOfRightAnswers()>= appSettings.getRightAnswersInARow() && numOfTry < words.size()*5){
        id = rand()%words.size();
        ++numOfTry;
    }
    if(numOfTry >= words.size()*5){
        for (int i=0; i<words.size(); ++i){
            if (words[i].getNumOfRightAnswers() < appSettings.getRightAnswersInARow()){
                return words[i].getId();
            }
        }
        id = -1;
    }
    return id;
}

WordWithAccentAndStatistic &WordsVector::operator [](int index)
{
    return words[index];
}

