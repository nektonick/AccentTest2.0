#include "DeleteWordsWarning.h"
#include "ui_DeleteWordsWarning.h"

DeleteWordsWarning::DeleteWordsWarning(QWidget *parent) : QDialog(parent),
    ui(new Ui::DeleteWordsWarning)
{
    ui->setupUi(this);
}

DeleteWordsWarning::~DeleteWordsWarning()
{
    delete ui;
}

void DeleteWordsWarning::setWarningText(QString text)
{
    ui->label->setText(text);
}
