#ifndef WORLDSVECTOR_H
#define WORLDSVECTOR_H
#include <vector>
#include <WordWithAccentAndStatistic.h>
#include <QDebug>
#include <QFile>
#include <AppSettings.h>

class WordsVector
{
public:
    WordsVector();
    void getWordsByReadingFromFileOrCreatingDefaultFile();
    void saveWords();
    int size();
    int getGoodRandomWordNum();
    WordWithAccentAndStatistic& operator [] (int index);
    std::vector<WordWithAccentAndStatistic> words;
    AppSettings appSettings;
private:
    QFile wordsFile;
    QString fileName = "words_and_accents";
    void readWordsFromFile();
    void createDefaultWordsFileIfItNotExist();
};

#endif // WORLDSVECTOR_H
