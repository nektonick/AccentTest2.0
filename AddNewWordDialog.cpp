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
