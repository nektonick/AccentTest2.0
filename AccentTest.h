#ifndef ACCENTTEST_H
#define ACCENTTEST_H

#include <QWidget>
#include <QDebug>
#include <QSignalMapper>
#include <QLabel>
#include <WordsVector.h>
#include <WordLettersButtonsVector.h>
#include <AppSettings.h>

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
    Ui::AccentTest *ui;
    QWidget *mainWidget;
    WordsVector wordsVector;
    WordWithAccentAndStatistic currentWord;
    WordLettersButtonsVector buttons;
    QLabel wrongAnswerLabel;
    QString inputAccent;
    int currentWordNum;
    AppSettings appSettings;

    void showRandomWord();
    void showRightAnswer();
    void saveWordsStatistic();
    void showUserWrongAnswer();
    void setGreenButtonStyleSheet(QPushButton & b);
    void setRedLableStyleSheet (QLabel &l);
    void allWordsAreLearned();
    int getGoodRandomWordNum();
private slots:
    void rightVowelClick();
    void wrongVowelClick();
    void nextWordClick();
    void on_returnButton_clicked();
};

#endif // ACCENTTEST_H
