#ifndef CHECKBOXESWITHWORDS_H
#define CHECKBOXESWITHWORDS_H
#include <QCheckBox>
#include <WordsVector.h>

class WordsWithCheckBoxVector :  public std::vector<QCheckBox*>
{
public:
    WordsWithCheckBoxVector();
    ~WordsWithCheckBoxVector();
    WordsVector wordsVector;
    void generateWordsCheckBoxes();
    void deleteChechBoxes();
    int getLastWordId();
};

#endif // CHECKBOXESWITHWORDS_H
