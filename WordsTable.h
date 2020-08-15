#ifndef WORDSTABLE_H
#define WORDSTABLE_H

#include <QWidget>
#include <QCheckBox>
#include <WordsVector.h>
#include <CheckBoxesWithWords.h>
#include <AddNewWordDialog.h>
#include <AddNewWordDialogAlternative.h>
#include <DeleteWordsWarning.h>
#include <AppSettings.h>

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
    AppSettings appSettings;
    void addNewWord();
    void wordsUpdate();
    void saveWords();
    void showRegularAddWordDialog();
    void showAlternativeAddWordDialog();
    int showWarningAndReturnExecCode(int howManyWordsWillBeDelete);
};

#endif // WORDSTABLE_H
