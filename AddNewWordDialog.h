#ifndef ADDNEWWORDDIALOG_H
#define ADDNEWWORDDIALOG_H

#include <QDialog>

namespace Ui {
class AddNewWordDialog;
}

class AddNewWordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewWordDialog(QWidget *parent = nullptr);
    ~AddNewWordDialog();

private:
    Ui::AddNewWordDialog *ui;
};

#endif // ADDNEWWORDDIALOG_H
