#ifndef ACCENTTEST_H
#define ACCENTTEST_H

#include <QWidget>
#include <WordsVector.h>
#include <ButtonsWithLetter.h>
#include <QDebug>
#include <QSignalMapper>
#include <QLabel>
namespace Ui {
class AccentTest;
}

class AccentTest : public QWidget
{
    Q_OBJECT
public:
    explicit AccentTest(QWidget *parent = nullptr);
    ~AccentTest();
    void showRandomWord();
private:
    Ui::AccentTest *ui;
    WordsVector wordsVector;
    WordWithAccentAndStatistic word;
    ButtonsWithLetter buttons;
    QLabel wrongAnswerLabel;
    QString userAnswer;
    void wrongAnswerTextAdd();
    void setGreenButtonStyleSheet(QPushButton & b);
    void setRedLableStyleSheet (QLabel &l);
private slots:
    void rightVowelClick();
    void wrongVowelClick();
    void nextWordClick();
};

#endif // ACCENTTEST_H
