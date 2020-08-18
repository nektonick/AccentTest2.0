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
    ~WordsVector();
    void getWordsByReadingFromFileOrCreatingDefaultFile();
    void saveWords();
    int size();
    int getGoodRandomWordNum();
    std::vector<WordWithAccentAndStatistic> words;
    WordWithAccentAndStatistic& operator [] (int index);
private:
    AppSettings appSettings;
    QFile wordsFile;
    QString fileName = "words_and_accents";
    void readWordsFromFile();
    void createDefaultWordsFileIfItNotExist();
};

#endif // WORLDSVECTOR_H
