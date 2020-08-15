#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <AccentTest.h>
#include <WordsTable.h>
#include <AppSettings.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();
private slots:
    void on_StartButton_clicked();
    void on_ShowAllWorldsButton_clicked();

    void on_ExitButton_clicked();

    void on_optionsButton_clicked();

private:
    Ui::MainMenu *ui;
    void set28pxFont(QPushButton * button);
};
#endif // MAINMENU_H
