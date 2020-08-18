#include "MainMenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "ru");
    QApplication a(argc, argv);
    MainMenu w;
    w.show();
    return a.exec();
}
