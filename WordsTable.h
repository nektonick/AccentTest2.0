#ifndef WORDSTABLE_H
#define WORDSTABLE_H

#include <QWidget>
#include <QCheckBox>
#include <WordsVector.h>
#include <CheckBoxesWithWords.h>
#include <AddNewWordDialog.h>
#include <DeleteWordsWarning.h>

namespace Ui {
class WordsTable;
}

class WordsTable : public QWidget
{
    Q_OBJECT

public:
    explicit WordsTable(QWidget *parent = nullptr);
    ~WordsTable();

private slots:
    void on_addNewWordButton_clicked();
    void on_deleteWordButton_clicked();
    void on_returnButton_clicked();
    void on_clearStatisticButton_clicked();

private:
    Ui::WordsTable *ui;
    CheckBoxesWithWords checkBoxesWithWords;
    void showWords();
    WordWithAccentAndStatistic newWord;
    QWidget *mainWidget;
    void addNewWord();
    void wordsUpdate();
    void saveWords();
    int showWarningAndReturnExecCode(int howManyWordsWillBeDelete);
};

#endif // WORDSTABLE_H
