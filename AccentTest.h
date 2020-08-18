#ifndef ACCENTTEST_H
#define ACCENTTEST_H

#include <QWidget>
#include <QDebug>
#include <QSignalMapper>
#include <QLabel>
#include <WordsVector.h>
#include <ButtonsWithLetter.h>

namespace Ui {
class AccentTest;
}

class AccentTest : public QWidget
{
    Q_OBJECT
public:
    explicit AccentTest(QWidget *parent = nullptr);
    ~AccentTest();
private:
    QWidget *mainWidget;
    Ui::AccentTest *ui;
    WordsVector wordsVector;
    WordWithAccentAndStatistic currentWord;
    ButtonsWithLetter buttons;
    QLabel wrongAnswerLabel;
    QString inputAccent;
    int currentWordNum;

    void showRandomWord();
    void showRightAnswer();
    void saveWordsStatistic();
    void showUserWrongAnswer();
    void setGreenButtonStyleSheet(QPushButton & b);
    void setRedLableStyleSheet (QLabel &l);
    void allWordsAreLearned();
private slots:
    void rightVowelClick();
    void wrongVowelClick();
    void nextWordClick();
    void on_returnButton_clicked();
};

#endif // ACCENTTEST_H
