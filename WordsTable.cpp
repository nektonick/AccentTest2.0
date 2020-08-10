#include "WordsTable.h"
#include "ui_WordsTable.h"

WordsTable::WordsTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WordsTable)
{
    ui->setupUi(this);
    for (int i=0; i<20; ++i){
        QCheckBox *l = new QCheckBox;
        l->setText(QString::number(i));
        ui->wordsArea->addWidget(l);
    }
}

WordsTable::~WordsTable()
{
    delete ui;
}
