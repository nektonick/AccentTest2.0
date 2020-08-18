#include "AboutApp.h"
#include "ui_AboutApp.h"

AboutApp::AboutApp(QWidget *parent) : ui(new Ui::AboutApp)
{
    mainWidget = parent;
    ui->setupUi(this);
}

AboutApp::~AboutApp()
{
    delete ui;
}

void AboutApp::on_returnButton_clicked()
{
    mainWidget->show();
    this->close();
    this->destroy();
}
