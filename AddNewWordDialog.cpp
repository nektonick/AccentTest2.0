#include "AddNewWordDialog.h"
#include "ui_AddNewWordDialog.h"

AddNewWordDialog::AddNewWordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewWordDialog)
{
    ui->setupUi(this);
}

AddNewWordDialog::~AddNewWordDialog()
{
    delete ui;
}

void AddNewWordDialog::on_buttonBox_accepted()
{
    inputText = ui->wordLineEdit->text();
    inputAccent = ui->accentLineEdit->text().toInt();
}
