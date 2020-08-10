#include "MainMenu.h"
#include "ui_MainMenu.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    ui->label->setStyleSheet(
                "font-size: 36px;"
                "font-weight: normal;"
                "margin: 0.5px; padding: 5px;"
                );
    ui->StartButton->setStyleSheet(
                "font-size: 28px;"
                "font-weight: normal;"
                "margin: 0.5px; padding: 0px;"
                );
    ui->ShowAllWorldsButton->setStyleSheet(
                "font-size: 28px;"
                "font-weight: normal;"
                "margin: 0.5px; padding: 0px;"
                );
    ui->AboutButton->setStyleSheet(
                "font-size: 28px;"
                "font-weight: normal;"
                "margin: 0.5px; padding: 0px;"
                );
    ui->ExitButton->setStyleSheet(
                "font-size: 28px;"
                "font-weight: normal;"
                "margin: 0.5px; padding: 0px;"
                );
}

MainMenu::~MainMenu()
{
    delete ui;
}


void MainMenu::on_StartButton_clicked()
{
    AccentTest *test= new AccentTest;
    test->show();
    hide();
}

void MainMenu::on_ShowAllWorldsButton_clicked()
{
    WordsTable *wordsTable= new WordsTable;
    wordsTable->show();
    hide();
}
