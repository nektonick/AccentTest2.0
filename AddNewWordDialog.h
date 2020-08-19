#ifndef ADDNEWWORDDIALOG_H
#define ADDNEWWORDDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QValidator>

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
private:
    Ui::AddNewWordDialog *ui;
private slots:
    void on_buttonBox_accepted();
};

#endif // ADDNEWWORDDIALOG_H
