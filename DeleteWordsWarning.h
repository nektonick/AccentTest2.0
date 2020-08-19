#ifndef DELETEWORDSWARNING_H
#define DELETEWORDSWARNING_H

#include <QDialog>

namespace Ui {
class DeleteWordsWarning;
}

class DeleteWordsWarning : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteWordsWarning(QWidget *parent = nullptr);
    ~DeleteWordsWarning();
    void setWarningText(QString text);
private:
    Ui::DeleteWordsWarning *ui;
};

#endif // DELETEWORDSWARNING_H
