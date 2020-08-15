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
    set28pxFont(ui->StartButton);
    set28pxFont(ui->ShowAllWorldsButton);
    set28pxFont(ui->AboutButton);
    set28pxFont(ui->optionsButton);
    set28pxFont(ui->ExitButton);
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
    AppSettings *appSettings = new AppSettings(this);
    appSettings->show();
    this->hide();
}

void MainMenu::set28pxFont(QPushButton *button)
{
    button->setStyleSheet(
                "font-size: 28px;"
                "font-weight: normal;"
                "margin: 0.5px; padding: 0px;"
                );
}
