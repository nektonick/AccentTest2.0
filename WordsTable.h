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
private:
    Ui::WordsTable *ui;
    QWidget *mainWidget;
    CheckBoxesWithWords checkBoxesWithWords;
    WordWithAccentAndStatistic newWord;
    AppSettings appSettings;
    void showWords();
    void wordsUpdate();
    void addNewWord();
    void saveWords();
    void showRegularAddWordDialog();
    void showAlternativeAddWordDialog();
    int showWarningAndReturnExecCode(int howManyWordsWillBeDelete);
private slots:
    void on_addNewWordButton_clicked();
    void on_deleteWordButton_clicked();
    void on_clearStatisticButton_clicked();
    void on_returnButton_clicked();
};

#endif // WORDSTABLE_H
