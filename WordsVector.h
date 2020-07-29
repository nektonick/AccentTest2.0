#ifndef WORLDSVECTOR_H
#define WORLDSVECTOR_H
#include <vector>
#include <WordWithAccentAndStatistic.h>
#include <fstream>
#include <QDebug>
#include <QFile>
#include <QTextCodec>

class WordsVector
{
public:
    WordsVector();
    void getWordsByReadingFromFileOrCreatingDefaultFile();
    void saveWords();
    void addNewWord();
    WordWithAccentAndStatistic getGoodRandomWord();
    WordWithAccentAndStatistic& operator [] (int index);
private:
    std::vector<WordWithAccentAndStatistic> words;
    QFile wordsFile;
    QString fileName = "words_and_accents";
    void readWordsFromFile();
    void createDefaultWordsFileIfItNotExist();
};

#endif // WORLDSVECTOR_H
