#ifndef ADDNEWWORDDIALOG_H
#define ADDNEWWORDDIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class AddNewWordDialog;
}

class AddNewWordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewWordDialog(QWidget *parent = nullptr);
    ~AddNewWordDialog();
    QString inputText;
    int inputAccent;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddNewWordDialog *ui;
};

#endif // ADDNEWWORDDIALOG_H
