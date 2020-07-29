#ifndef ACCENTTEST_H
#define ACCENTTEST_H

#include <QWidget>
#include <WordsVector.h>
#include <ButtonsWithLetter.h>
#include <QDebug>

namespace Ui {
    class AccentTest;
}

class AccentTest : public QWidget
{
    Q_OBJECT

public:
    explicit AccentTest(QWidget *parent = nullptr);
    ~AccentTest();
    void showWord();


private:
    Ui::AccentTest *ui;
    WordsVector wordsVector;
    WordWithAccentAndStatistic word;
    ButtonsWithLetter buttons;
};

#endif // ACCENTTEST_H
