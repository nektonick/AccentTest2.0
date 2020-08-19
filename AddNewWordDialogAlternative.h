#ifndef ADDNEWWORDDIALOGALTERNATIVE_H
#define ADDNEWWORDDIALOGALTERNATIVE_H

#include <QDialog>
#include <QDebug>
#include <string>
#include <QMessageBox>
#include <QValidator>

namespace Ui {
class AddNewWordDialogAlternative;
}

class AddNewWordDialogAlternative : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewWordDialogAlternative(QWidget *parent = nullptr);
    ~AddNewWordDialogAlternative();
    QString inputText;
    int inputAccent;
private:
    Ui::AddNewWordDialogAlternative *ui;
    int getInputAccent();
private slots:
    void on_buttonBox_accepted();
};

#endif // ADDNEWWORDDIALOGALTERNATIVE_H
