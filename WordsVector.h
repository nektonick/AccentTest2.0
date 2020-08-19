#ifndef WORLDSVECTOR_H
#define WORLDSVECTOR_H
#include <vector>
#include <WordWithAccentAndStatistic.h>
#include <QDebug>
#include <QFile>
#include <QMessageBox>

class WordsVector : public std::vector<WordWithAccentAndStatistic>
{
public:
    WordsVector();
    ~WordsVector();
    void getWordsByReadingFromFileOrCreatingDefaultFile();
    void saveWords();
private:
    QFile wordsFile;
    QString fileName = "words_and_accents";
    void readWordsFromFile();
    void createDefaultWordsFileIfItNotExist();
};

#endif // WORLDSVECTOR_H
