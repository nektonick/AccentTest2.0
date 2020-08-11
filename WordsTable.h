#ifndef WORDSTABLE_H
#define WORDSTABLE_H

#include <QWidget>
#include <QCheckBox>
#include <WordsVector.h>
#include <CheckBoxesWithWords.h>
#include <AddNewWordDialog.h>

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

private:
    Ui::WordsTable *ui;
    CheckBoxesWithWords checkBoxesWithWords;
    void showWords();
};

#endif // WORDSTABLE_H
