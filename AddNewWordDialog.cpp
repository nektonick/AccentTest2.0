#include "AddNewWordDialog.h"
#include "ui_AddNewWordDialog.h"

AddNewWordDialog::AddNewWordDialog(QWidget *parent) : QDialog(parent),
    ui(new Ui::AddNewWordDialog)
{
    ui->setupUi(this);
    ui->accentLineEdit->setValidator(new QIntValidator(1, 999, this));
    ui->wordLineEdit->setValidator(new QRegExpValidator(QRegExp(QString::fromUtf8("[а-я]+")), ui->wordLineEdit));

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
