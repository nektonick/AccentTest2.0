#include "WordsVector.h"


WordsVector::WordsVector()
{
    wordsFile.setFileName(fileName);
    if (wordsFile.isOpen()){
        qDebug()<<"file is already open"<<endl;
        wordsFile.close();
    }
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
    if (wordsFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append) && wordsFile.pos() == 0){
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
    while (words[id].getNumOfRightAnswers()>=4){
        id = rand()%words.size();
    }
    return id;
}

WordWithAccentAndStatistic &WordsVector::operator [](int index)
{
    return words[index];
}

