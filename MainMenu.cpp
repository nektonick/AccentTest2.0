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
    ui->optionsButton->setStyleSheet(
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
    //костыль с передачей ссылки на виджет, чтобы потом сделать MainWindow.show();
    AccentTest *test= new AccentTest(this);
    test->show();
    hide();
}

void MainMenu::on_ShowAllWorldsButton_clicked()
{
    WordsTable *wordsTable= new WordsTable(this);
    wordsTable->show();
    hide();
}

void MainMenu::on_ExitButton_clicked()
{
    close();
}

void MainMenu::on_optionsButton_clicked()
{

}
