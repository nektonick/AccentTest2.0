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
    int size();
    WordWithAccentAndStatistic getGoodRandomWord();
    WordWithAccentAndStatistic& operator [] (int index);
    std::vector<WordWithAccentAndStatistic> words;
private:

    QFile wordsFile;
    QString fileName = "words_and_accents";
    void readWordsFromFile();
    void createDefaultWordsFileIfItNotExist();
};

#endif // WORLDSVECTOR_H
