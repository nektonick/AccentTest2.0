#ifndef WORDSTABLE_H
#define WORDSTABLE_H

#include <QWidget>
#include <QCheckBox>

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
};

#endif // WORDSTABLE_H
