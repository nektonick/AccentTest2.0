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
    //костыль с передачей ссылки на виджет, чтобы потом сделать MainWindow.show();
    //если передавать в parent, то у них будет одно общее окно
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
    QWidget *mainWidget;
    int wordNum;
    void saveWordsStatistic();
    void wrongAnswerTextAdd();
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
