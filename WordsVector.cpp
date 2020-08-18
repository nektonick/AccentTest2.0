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

WordsVector::~WordsVector()
{
    wordsFile.close();
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
                this->push_back(word);
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
        for (auto w : *this){
            outStream<<w.getId()<<" "<<w.getText()<<" "<<w.getRightAccent()<<" "<<w.getNumOfRightAnswers()<<endl;
        }
        wordsFile.close();
    }
}
